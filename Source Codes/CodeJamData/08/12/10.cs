using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ08_1A_B
{
    class Program
    {
        static void Large()
        {
            int C = int.Parse(Console.ReadLine());
            for (int i = 1; i <= C; i++)
            {
                int N = int.Parse(Console.ReadLine());
                int M = int.Parse(Console.ReadLine());
                bool[, ,] li = new bool[M, N, 2];

                for (int j = 0; j < M; j++)
                {
                    string[] ss = Console.ReadLine().Split(' ');
                    for (int k = 1; k < ss.Length; k += 2) li[j, int.Parse(ss[k])-1, int.Parse(ss[k + 1])] = true;
                }

                bool ada = false;
                int mask = 0;
                int mama = 2000;
                for (int j = 0; j < (1 << N); j++)
                {
                    bool allOK = true;
                    for (int c = 0; c < M; c++)
                    {
                        bool csat = false;
                        for (int k = 0; k < N; k++)
                        {
                            int cj = ((j & (1 << k)) != 0) ? 1 : 0;
                            if (li[c, k, cj])
                            {
                                csat = true;
                                break;
                            }
                        }

                        if (!csat)
                        {
                            allOK = false;
                            break;
                        }
                    }

                    if (allOK)
                    {
                        ada = true;

                        int mac = 0;
                        for (int k = 0; k < N; k++) if ((j & (1 << k)) != 0) mac++;

                        if (mac < mama)
                        {
                            mama = mac;
                            mask = j;
                        }
                    }
                }

                if (!ada) Console.WriteLine("Case #{0}: IMPOSSIBLE", i);
                else
                {
                    Console.Write("Case #{0}:", i);
                    for (int k = 0; k < N; k++) Console.Write(" {0}", ((mask & (1 << k)) != 0) ? 1 : 0);
                    Console.WriteLine();
                }
            }
        }

        static void Main(string[] args)
        {
            bool large = true;

            if (large) Large();
            else
            {
                int C = int.Parse(Console.ReadLine());
                for (int i = 1; i <= C; i++)
                {
                    int N = int.Parse(Console.ReadLine());
                    int M = int.Parse(Console.ReadLine());

                    List<Dictionary<int, int>> l = new List<Dictionary<int, int>>();
                    for (int j = 0; j < M; j++)
                    {
                        l.Add(new Dictionary<int, int>());
                        string[] ss = Console.ReadLine().Split(' ');
                        for (int k = 1; k < ss.Length; k += 2) l[j][int.Parse(ss[k])] = int.Parse(ss[k + 1]);
                    }

                    bool[] r = new bool[N + 1];
                    bool muri = false;
                    for (int j = 1; j <= N; j++)
                    {
                        int b = -1;
                        for (int k = 0; k < l.Count; k++)
                        {
                            if (l[k].ContainsKey(j))
                            {
                                b = l[k][j];
                                break;
                            }
                        }

                        if (b != -1)
                        {
                            for (int k = 0; k < l.Count; k++)
                            {
                                if (l[k].ContainsKey(j) && l[k][j] != b)
                                {
                                    muri = true;
                                    break;
                                }
                            }

                            r[j] = b == 1;
                        }

                        if (muri) break;
                    }

                    if (muri) Console.WriteLine("Case #{0}: IMPOSSIBLE", i);
                    else
                    {
                        Console.Write("Case #{0}:", i);
                        for (int j = 1; j <= N; j++) Console.Write(" {0}", r[j] ? 1 : 0);
                        Console.WriteLine();
                    }
                }
            }
        }
    }
}
