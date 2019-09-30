using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class D : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            int iCases = int.Parse(sLines);

            System.Threading.Tasks.Task<List<string>>[] tasks = new System.Threading.Tasks.Task<List<string>>[iCases];

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string[] s = Console.ReadLine().Split();
                int N = int.Parse(s[0]);
                int M = int.Parse(s[1]);
                char[] c = new char[M];
                int[] x = new int[M];
                int[] y = new int[M];
                for (int i = 0; i < M; i++)
                {
                    s = Console.ReadLine().Split();
                    c[i] = s[0][0];
                    x[i] = int.Parse(s[1]);
                    y[i] = int.Parse(s[2]);
                }
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<List<string>>
                    (
                        () => DoWork(N, c, x, y)
                    );
                tasks[iCase - 1].Wait();
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                List<string> ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret[0]);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret[0]);
                for (int i = 1; i < ret.Count; i++)
                {
                    Console.WriteLine(ret[i]);
                    System.Diagnostics.Debug.WriteLine(ret[i]);
                }
            }
        }

        private List<string> DoWork(int N, char[] c, int[] x, int[] y)
        {
            bool[,] initialStateS = new bool[N, N];
            bool[,] initialStateD = new bool[N, N];
            bool[,] finalStateS = new bool[N, N];
            bool[,] finalStateD = new bool[N, N];

            for (int i = 0; i < c.Length; i++)
            {
                if (c[i]=='+' || c[i]=='o')
                {
                    initialStateD[x[i] - 1, y[i] - 1] = true;
                    finalStateD[x[i] - 1, y[i] - 1] = true;
                }

                if (c[i] == 'x' || c[i] == 'o')
                {
                    initialStateS[x[i] - 1, y[i] - 1] = true;
                    finalStateS[x[i] - 1, y[i] - 1] = true;
                }
            }

            // Rows and cols
            bool[,] sSee = new bool[N, N];
            int[] sMatched1To2 = new int[N];
            int[] sMatched2To1 = new int[N];
            for (int i = 0; i < N; i++)
            {
                sMatched1To2[i] = -1;
                sMatched2To1[i] = -1;
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    sSee[i, j] = true;
                }
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (initialStateS[i, j])
                    {
                        for (int k = 0; k < N; k++)
                        {
                            sSee[i, k] = false;
                            sSee[k, j] = false;
                        }
                    }
                }
            }

            while (bImproveMatching(sSee, sMatched1To2, sMatched2To1))
            {

            }

            for (int i = 0; i < N; i++)
            {
                if (sMatched1To2[i]!=-1)
                {
                    finalStateS[i, sMatched1To2[i]] = true;
                }
            }

            // Diags
            bool[,] dSee = new bool[2*N-1, 2*N-1];
            int[] dMatched1To2 = new int[2 * N - 1];
            int[] dMatched2To1 = new int[2 * N - 1];
            for (int i = 0; i < 2 * N - 1; i++)
            {
                dMatched1To2[i] = -1;
                dMatched2To1[i] = -1;
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    int d1 = i + j;
                    int d2 = i - j + N - 1;
                    dSee[d1, d2] = true;
                }
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (initialStateD[i, j])
                    {
                        int d1 = i + j;
                        int d2 = i - j + N - 1;
                        for (int k = 0; k < 2*N-1; k++)
                        {
                            dSee[d1, k] = false;
                            dSee[k, d2] = false;
                        }
                    }
                }
            }

            while (bImproveMatching(dSee, dMatched1To2, dMatched2To1))
            {

            }

            for (int i = 0; i < 2*N-1; i++)
            {
                if (dMatched1To2[i] != -1)
                {
                    int d1 = i;
                    int d2 = dMatched1To2[i];
                    int ix = (d1 + d2 - N + 1) / 2;
                    int iy = (d1 - d2 + N - 1) / 2;
                    finalStateD[ix, iy] = true;
                }
            }

            int score = 0;
            List<string> moves = new List<string>();
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (finalStateD[i, j]) score++;
                    if (finalStateS[i, j]) score++;
                    if (finalStateD[i,j] && finalStateS[i,j])
                    {
                        if (!initialStateD[i,j] || !initialStateS[i,j])
                        {
                            moves.Add(string.Format("{0} {1} {2}", 'o', i + 1, j + 1));
                        }
                    } else
                    {
                        if (finalStateD[i,j] && !initialStateD[i,j])
                        {
                            moves.Add(string.Format("{0} {1} {2}", '+', i + 1, j + 1));
                        }
                        if (finalStateS[i, j] && !initialStateS[i, j])
                        {
                            moves.Add(string.Format("{0} {1} {2}", 'x', i + 1, j + 1));
                        }
                    }
                }
            }

            List<string> ret = new List<string>();
            ret.Add(string.Format("{0} {1}", score, moves.Count));
            ret.AddRange(moves);

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
