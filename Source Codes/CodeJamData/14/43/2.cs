using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class DontBreakTheNile : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                int W = int.Parse(s.Split(' ')[0]);
                int H = int.Parse(s.Split(' ')[1]);
                int B = int.Parse(s.Split(' ')[2]);

                int[] X0 = new int[B];
                int[] Y0 = new int[B];
                int[] X1 = new int[B];
                int[] Y1 = new int[B];

                for (int i = 0; i < B; i++)
                {
                    string[] s2 = Console.ReadLine().Split(' ');
                    X0[i] = int.Parse(s2[0]);
                    Y0[i] = int.Parse(s2[1]);
                    X1[i] = int.Parse(s2[2]);
                    Y1[i] = int.Parse(s2[3]);
                }

                long ret = CalcMaxFlow(W, H, B, X0, Y0, X1, Y1);
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //    System.Diagnostics.Debug.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private int CalcMaxFlow(int W, int H, int B, int[] X0, int[] Y0, int[] X1, int[] Y1)
        {
            int[] dirX = new int[] { 0, 1, 0, -1 };
            int[] dirY = new int[] { 1, 0, -1, 0 };
            bool[,] buildingMap = new bool[W, H];
            for (int i = 0; i < B; i++)
            {
                for (int x = X0[i]; x <= X1[i]; x++)
                {
                    for (int y = Y0[i]; y <= Y1[i]; y++)
                    {
                        buildingMap[x, y] = true;
                    }
                }
            }

            int riverCount = 0;
            int[,] idxMapIn = new int[W, H];
            int[,] idxMapOut = new int[W, H];
            for (int x = 0; x < W; x++)
            {
                for (int y = 0; y < H; y++)
                {
                    if (!buildingMap[x, y])
                    {
                        idxMapIn[x, y] = riverCount++;
                        idxMapOut[x, y] = riverCount++;
                    }
                }
            }

            int SOURCE = riverCount++;
            int SINK = riverCount++;

            List<int>[] edges = new List<int>[riverCount];
            List<int>[] caps = new List<int>[riverCount];
            for (int i = 0; i < riverCount; i++)
            {
                edges[i] = new List<int>();
                caps[i] = new List<int>();
            }

            for (int x = 0; x < W; x++)
            {
                for (int y = 0; y < H; y++)
                {
                    if (buildingMap[x, y]) continue;
                    int idxIn = idxMapIn[x, y];
                    int idxOut = idxMapOut[x, y];
                    edges[idxIn].Add(idxOut);
                    caps[idxIn].Add(1);
                }
            }

            for (int x = 0; x < W; x++)
            {
                for (int y = 0; y < H; y++)
                {
                    if (buildingMap[x, y]) continue;
                    int idx = idxMapOut[x, y];
                    for (int k = 0; k < 4; k++)
                    {
                        int x2 = x + dirX[k];
                        int y2 = y + dirY[k];
                        if (x2 >= 0 && x2 < W && y2 >= 0 && y2 < H && !buildingMap[x2, y2])
                        {
                            int idx2 = idxMapIn[x2, y2];
                            edges[idx].Add(idx2);
                            caps[idx].Add(1);
                        }
                    }
                }
            }

            for (int x = 0; x < W; x++)
            {
                if (!buildingMap[x, 0])
                {
                    int idx = idxMapIn[x, 0];
                    edges[SOURCE].Add(idx);
                    caps[SOURCE].Add(1);
                }

                if (!buildingMap[x, H - 1])
                {
                    int idx = idxMapOut[x, H - 1];
                    edges[idx].Add(SINK);
                    caps[idx].Add(1);
                }
            }

            int ret = MaxFlow(edges, caps, SOURCE, SINK);
            return ret;
        }

        private int MaxFlow(List<int>[] edges, List<int>[] caps, int SOURCE, int SINK)
        {
            // Uses caps as a residual network, reducing it over and over
            bool work = true;
            int ret = 0;
            int loc;
            int N = caps.Length;

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
                prev[SOURCE] = -2;

                // Find shortest path to sink
                Queue<int> oQ = new Queue<int>();
                oQ.Enqueue(SOURCE);
                while (oQ.Count > 0)
                {
                    loc = oQ.Dequeue();
                    for (int i = 0; i < edges[loc].Count; i++)
                    {
                        if (caps[loc][i] > 0 && prev[edges[loc][i]] == -1)
                        {
                            prev[edges[loc][i]] = loc;
                            if (edges[loc][i] == SINK) break;
                            oQ.Enqueue(edges[loc][i]);
                        }
                    }
                    if (prev[SINK] >= 0) break;
                }
                if (prev[SINK] < 0) break;

                work = true;
                loc = SINK;
                while (prev[loc] >= 0)
                {
                    bool edgeDone = false;
                    for (int i = 0; i < edges[loc].Count; i++)
                    {
                        if (edges[loc][i] == prev[loc])
                        {
                            edgeDone = true;
                            caps[loc][i]++;
                        }
                    }
                    if (!edgeDone)
                    {
                        edges[loc].Add(prev[loc]);
                        caps[loc].Add(1);
                    }

                    edgeDone = false;
                    for (int i = 0; i < edges[prev[loc]].Count; i++)
                    {
                        if (edges[prev[loc]][i] == loc)
                        {
                            edgeDone = true;
                            caps[prev[loc]][i]--;
                            break;
                        }
                    }
                    System.Diagnostics.Debug.Assert(edgeDone);

                    loc = prev[loc];
                }
                ret++;
            }
            return ret;
        }
    }
}
