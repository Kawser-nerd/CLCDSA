using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static int M;
        static int[] nodes;
        static int[] changes;
        static int?[,] best;
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("A-large.in"))
            {
                using (StreamWriter sw = new StreamWriter("A-large.out"))
                {
                    int N = int.Parse(sr.ReadLine());
                    for (int z = 1; z <= N; z++)
                    {
                        string[] elem = sr.ReadLine().Split(' ');
                        M = int.Parse(elem[0]);
                        int V = int.Parse(elem[1]);

                        nodes = new int[M];
                        changes = new int[M];
                        best = new int?[M,2];

                        for (int i = 0; i < M; i++)
                        {
                            if (i * 2 + 1 < M)
                            {
                                elem = sr.ReadLine().Split(' ');
                                nodes[i] = int.Parse(elem[0]);
                                changes[i] = int.Parse(elem[1]);
                            }
                            else
                            {
                                nodes[i] = int.Parse(sr.ReadLine());
                                changes[i] = 0;
                            }
                        }

                        int res = GetMin ( 0, V ) ;
                        sw.WriteLine("Case #{0}: {1}", z, res >= INF ? "IMPOSSIBLE": res.ToString());
                    }
                    sw.Close(); sr.Close();
                }
            }
        }

        const int INF = 20000;
        private static int GetMin(int ridx, int expected)
        {
            if (best[ridx,expected] != null) return (int)best[ridx,expected];

            if (ridx * 2 + 1 >= M)
            {
                int res = INF;
                if (nodes[ridx] == expected) res = 0;

                best[ridx,expected] = res;
                return res;
            }
            else
            {
                int l1 = GetMin(ridx * 2 + 1, 1);
                int l0 = GetMin(ridx * 2 + 1, 0);
                int r1 = GetMin(ridx * 2 + 2, 1);
                int r0 = GetMin(ridx * 2 + 2, 0);

                int nc = INF;
                if (nodes[ridx] == 1)
                {
                    if (expected == 1)
                        nc = l1 + r1;
                    else
                        nc = Math.Min(l1 + r0, Math.Min(l0 + r1, l0 + r0));
                }
                else
                {
                    if (expected == 1)
                        nc = Math.Min(l1 + r1, Math.Min(l0 + r1, l1 + r0));
                    else
                        nc = l0 + r0;
                }
                int cd = INF;
                if (nodes[ridx] == 0)
                {
                    if (expected == 1)
                        cd = 1 + l1 + r1;
                    else
                        cd = 1 + Math.Min(l1 + r0, Math.Min(l0 + r1, l0 + r0));
                }
                else
                {
                    if (expected == 1)
                        cd = 1 + Math.Min(l1 + r1, Math.Min(l0 + r1, l1 + r0));
                    else
                        cd = 1 + l0 + r0;
                }

                int temp = nc;
                if (changes[ridx] == 1) temp = Math.Min(temp, cd);

                best[ridx, expected] = temp;
                return temp;
            }
        }
    }
}
