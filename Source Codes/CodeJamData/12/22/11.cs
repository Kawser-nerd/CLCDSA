using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2012_1B
{
    class Program
    {
        static int[,] ceiling, floor;
        static double[,] map;
        const double INF = 1000000000;
        const double eps = 0.0000001;
        static int H, N, M;
        static int[] dx, dy;
        static bool[,] used;
        static void Main(string[] args)
        {
            string file = "B-large";
            dx = new int[4] { 0, 1, 0, -1 };
            dy = new int[4] { -1, 0, 1, 0 };
            
            using (StreamReader sr = new StreamReader(file+".in"))
            {
                using (StreamWriter sw = new StreamWriter(file+".out"))
                {
                    int casecount = int.Parse(sr.ReadLine());

                    for (int tc = 1; tc <= casecount; tc++)
                    {
                        string[] elems = sr.ReadLine().Split(' ');
                        H = int.Parse(elems[0]);
                        N = int.Parse(elems[1]);
                        M = int.Parse(elems[2]);

                        ceiling = new int[N, M];
                        floor = new int[N, M];

                        for (int i = 0; i < N; i++)
                        {
                            elems = sr.ReadLine().Split(' ');
                            for (int j = 0; j < M; j++)
                                ceiling[i, j] = int.Parse(elems[j]);
                        }

                        for (int i = 0; i < N; i++)
                        {
                            elems = sr.ReadLine().Split(' ');
                            for (int j = 0; j < M; j++)
                                floor[i, j] = int.Parse(elems[j]);
                        }

                        map = new double[N, M];
                        for (int i = 0; i < N; i++)
                        {
                            for (int j = 0; j < M; j++)
                                map[i, j] = INF;
                        }
                        map[0, 0] = -INF;

                        traverse1();

                        double res = 0;
                        if (map[N - 1, M - 1] == 0)
                        {
                        }
                        else
                        {
                            used = new bool[N, M];
                            for (int i = 0; i < N; i++)
                                for (int j = 0; j < M; j++)
                                    used[i, j] = false;
                            traverse2();
                            res = map[N - 1, M - 1];
                        }

                        sw.WriteLine("Case #{0}: {1}", tc, res);
                    }
                }
            }
        }

        public static void traverse1()
        {
            bool found = true;
            while (found)
            {
                found = false;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        if (Math.Abs(map[i, j] - -INF) < eps)
                        {
                            map[i, j] = 0;

                            for (int k = 0; k < 4; k++)
                            {
                                int newi = i + dy[k];
                                int newj = j + dx[k];

                                if (newi >= 0 && newi < N && newj >= 0 && newj < M && Math.Abs(map[newi, newj]-INF)<eps)
                                {
                                    double res = Calc(i, j, newi, newj, 0, true);
                                    if (res < INF - eps)
                                    {
                                        map[newi, newj] = -INF;
                                        found = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        public static void traverse2()
        {
            bool found = true;
            while (found)
            {
                found = false;
                int srci=-1, srcj=-1;
                double last = INF;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        if (used[i,j] == false && map[i, j] < INF && map[i,j] < last)
                        {
                            last = map[i, j];
                            srci = i;
                            srcj = j;
                        }
                    }
                }

                if (last == INF)
                {
                    break;
                }

                for (int k = 0; k < 4; k++)
                {
                    int desti = srci + dy[k];
                    int destj = srcj + dx[k];

                    if (desti >= 0 && desti < N && destj >= 0 && destj < M)
                    {
                        double res = Calc(srci, srcj, desti, destj, map[srci,srcj], false);
                        if (res < INF - eps && map[srci,srcj]+res < map[desti,destj])
                        {
                            map[desti, destj] = map[srci, srcj]+res;
                        }
                    }
                }

                found = true;
                used[srci, srcj] = true;
            }
        }

        public static double Calc ( int srci, int srcj, int desti, int destj, double t, bool nowait )
        {
            int srcceil = ceiling[srci, srcj];
            int srcfloor = floor[srci, srcj];
            int destceil = ceiling[desti, destj];
            int destfloor = floor[desti, destj];

            if (Math.Min(srcceil, destceil) - Math.Max(srcfloor, destfloor) < 50) return INF;

            double currlevel = H - 10 * t;

            double wait = 0;
            double targetlevel = destceil - 50;
            if (currlevel > targetlevel)
            {
                wait = (currlevel - targetlevel) / 10;
                currlevel = targetlevel;
            }

            if (wait > 0 && nowait)
                return INF;

            if (currlevel < srcfloor + 20 - eps)
                return 10+wait;
            else
                return 1+wait;
        }
    }
}
