using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class C : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            int iCases = int.Parse(sLines);

            System.Threading.Tasks.Task<string>[] tasks = new System.Threading.Tasks.Task<string>[iCases];

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                int N = int.Parse(Console.ReadLine());
                string[,] s = new string[N, 2];
                for (int i = 0; i < N; i++)
                {
                    string[] sLine = Console.ReadLine().Split(' ');
                    s[i, 0] = sLine[0];
                    s[i, 1] = sLine[1];
                }
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(N, s)
                    );
                //tasks[iCase - 1].Wait();
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWorkIsh(int N, string[,] s)
        {
            Dictionary<string, int> firstMap = new Dictionary<string, int>();
            Dictionary<string, int> secondMap = new Dictionary<string, int>();
            int firstCount = 0;
            int secondCount = 0;
            for (int i = 0; i < N; i++)
            {
                if (!firstMap.ContainsKey(s[i, 0]))
                {
                    firstMap[s[i, 0]] = firstCount++;
                }

                if (!secondMap.ContainsKey(s[i, 1]))
                {
                    secondMap[s[i, 1]] = secondCount++;
                }
            }

            int[,] words = new int[N, 2];
            for (int i = 0; i < N; i++)
            {
                words[i, 0] = firstMap[s[i, 0]];
                words[i, 1] = secondMap[s[i, 1]];
            }

            Random rnd = new Random();
            int bestReal = 99999;

            for (int a = 0; a < 100; a++)
            {
                bool[] included = new bool[N];
                bool[] first = new bool[firstMap.Count];
                bool[] second = new bool[secondMap.Count];
                int realCount = 0;
                int fwCount = 0;
                int swCount = 0;

                do
                {
                    int nextWord = rnd.Next(N);
                    if (included[nextWord]) continue;
                    if (!first[words[nextWord,0]] || !second[words[nextWord,1]])
                    {
                        included[nextWord] = true;
                        realCount++;

                        if (!first[words[nextWord,0]])
                        {
                            first[words[nextWord, 0]] = true;
                            fwCount++;
                        }

                        if (!second[words[nextWord, 1]])
                        {
                            second[words[nextWord, 1]] = true;
                            swCount++;
                        }

                        if (fwCount==first.Length && swCount==second.Length)
                        {
                            bestReal = Math.Min(bestReal, realCount);
                            break;
                        }
                    }
                } while (true);
            }

            return (N - bestReal).ToString();
        }

        private string DoWork(int N, string[,] s)
        {
            Dictionary<string, int> firstMap = new Dictionary<string, int>();
            Dictionary<string, int> secondMap = new Dictionary<string, int>();
            int firstCount = 0;
            int secondCount = 0;
            for (int i = 0; i < N; i++)
            {
                if (!firstMap.ContainsKey(s[i, 0]))
                {
                    firstMap[s[i, 0]] = firstCount++;
                }

                if (!secondMap.ContainsKey(s[i, 1]))
                {
                    secondMap[s[i, 1]] = secondCount++;
                }
            }

            int M = firstMap.Count + secondMap.Count + 2;
            int SOURCE = M - 2;
            int SINK = M - 1;
            int offset = firstMap.Count;

            int[,] caps = new int[M, M];
            for (int i = 0; i < firstMap.Count; i++)
            {
                caps[SOURCE, i] = 1;
            }

            for (int i = 0; i < secondMap.Count; i++)
            {
                caps[i + offset, SINK] = 1;
            }

            for (int i = 0; i < N; i++)
            {
                caps[firstMap[s[i, 0]], secondMap[s[i, 1]] + offset] = 1;
            }

            int[,] flownet;
            int flow = MaxFlow(caps, SOURCE, SINK, out flownet);

            int real = firstMap.Count + secondMap.Count - flow;

            return (N - real).ToString();
        }

        public int MaxFlow(int[,] caps, int source, int sink, out int[,] flow)
        {
            // Uses caps as a residual network, reducing it over and over
            bool work = true;
            int ret = 0;
            int loc;
            int N = caps.GetUpperBound(0) + 1;
            flow = new int[N, N];

            while (work)
            {
                // Repeat until no more improvement can be found
                work = false;

                int[] prev = new int[N];
                for (int i = 0; i < N; i++)
                {
                    prev[i] = -1;
                }
                // Mark source as visited
                prev[source] = -2;

                // Find shortest path to sink
                Queue<int> oQ = new Queue<int>();
                oQ.Enqueue(source);
                while (oQ.Count > 0)
                {
                    loc = oQ.Dequeue();
                    for (int i = 0; i < N; i++)
                    {
                        if (caps[loc, i] > flow[loc, i] && prev[i] == -1)
                        {
                            prev[i] = loc;
                            if (i == sink) break;
                            oQ.Enqueue(i);
                        }
                    }
                    if (prev[sink] >= 0) break;
                }

                // Work out narrowest segment on the path
                int mincap = int.MaxValue;
                loc = sink;
                while (prev[loc] >= 0)
                {
                    mincap = Math.Min(mincap, caps[prev[loc], loc] - flow[prev[loc], loc]);
                    loc = prev[loc];
                }

                // Remove new flow from residual network
                if (mincap < int.MaxValue)
                {
                    work = true;
                    loc = sink;
                    while (prev[loc] >= 0)
                    {
                        flow[prev[loc], loc] += mincap;
                        flow[loc, prev[loc]] -= mincap;
                        loc = prev[loc];
                    }
                    ret += mincap;
                }
            }
            return ret;
        }

        public bool bImproveMatching(bool[,] aSee, int[] aMatched1To2, int[] aMatched2To1)
        {
            int[] aMark1 = new int[aMatched1To2.Length];
            int[] aMark2 = new int[aMatched2To1.Length];
            int[] aPrev1 = new int[aMatched1To2.Length];
            int[] aPrev2 = new int[aMatched2To1.Length];
            Queue<int> oQueue = new Queue<int>();

            for (int i = 0; i < aMark1.Length; i++)
            {
                aMark1[i] = -1;
                aPrev1[i] = -1;
                if (aMatched1To2[i] == -1)
                {
                    oQueue.Enqueue(i);
                    aMark1[i] = 0;
                }
            }

            for (int i = 0; i < aMark2.Length; i++)
            {
                aMark2[i] = -1;
                aPrev2[i] = -1;
            }

            int iNewEnd = -1;
            bool bBreak = false;

            while (!bBreak && oQueue.Count > 0)
            {
                int i = oQueue.Dequeue();

                for (int j = 0; j < aMark2.Length; j++)
                {
                    if (aSee[i, j] && aMark2[j] == -1)
                    {
                        aMark2[j] = aMark1[i] + 1;
                        aPrev2[j] = i;
                        if (aMatched2To1[j] == -1)
                        {
                            iNewEnd = j;
                            bBreak = true;
                            break;
                        }
                        aMark1[aMatched2To1[j]] = aMark1[i] + 2;
                        aPrev1[aMatched2To1[j]] = j;
                        oQueue.Enqueue(aMatched2To1[j]);
                    }
                }
            }

            if (iNewEnd == -1) return false;

            int k = iNewEnd;

            while (k >= 0)
            {
                aMatched2To1[k] = aPrev2[k];
                aMatched1To2[aPrev2[k]] = k;
                k = aPrev1[aPrev2[k]];
            }

            return true;
        }
    }
}
