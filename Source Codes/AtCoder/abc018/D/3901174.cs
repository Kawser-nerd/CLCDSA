using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_018
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nmpqr = ReadInts();
            int n = nmpqr[0];
            int m = nmpqr[1];
            int p = nmpqr[2];
            int q = nmpqr[3];
            int r = nmpqr[4];
            var xyzs = new int[r][];
            for(int i = 0; i < r; i++)
            {
                xyzs[i] = ReadInts();
                xyzs[i][0]--;
                xyzs[i][1]--;
            }
            List<int[]> pat = EnumerateCombination(n, p);
            int res = 0;
            for (int i = 0; i < pat.Count; i++)
            {
                var points = new int[m];
                for (int j = 0; j < r; j++)
                {
                    bool inGroup = false;
                    for (int k = 0; k < p; k++)
                    {
                        if (xyzs[j][0] == pat[i][k])
                        {
                            inGroup = true;
                            break;
                        }
                    }
                    if (inGroup) points[xyzs[j][1]] += xyzs[j][2];
                }
                Array.Sort(points);
                int pnt = 0;
                for(int j = m-q; j <m; j++)
                {
                    pnt += points[j];
                    //Console.WriteLine(points[j]);
                }
                /*for(int j = 0; j < p; j++)
                {
                    Console.Write(pat[i][j] + " ");
                }*/
                //Console.WriteLine(pnt);
                res = Math.Max(res, pnt);
            }

            Console.WriteLine(res);
        }

        static List<int[]> EnumerateCombination(int n,int m)
        {
            var all = new List<List<int>>[n];
            for (int i = 0; i <= n - m; i++)
            {
                var list = new List<int>();
                list.Add(i);
                all[i] = new List<List<int>>();
                all[i].Add(list);
            }

            for(int i = 1; i < m; i++)
            {
                var next = new List<List<int>>[n];
                for(int j = i; j <= n-m+i; j++)
                {
                    next[j] = new List<List<int>>();
                    for (int k = i - 1; k < j; k++)
                    {
                        for(int l = 0;  
                            all[k]!=null&& l < all[k].Count; l++)
                        {
                            var list = new List<int>();
                            list.AddRange(all[k][l]);
                            list.Add(j);
                            next[j].Add(list);
                        }
                    }
                }
                all = next;
            }

            var res = new List<int[]>();
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; all[i]!=null&&j < all[i].Count; j++)
                {
                    res.Add(all[i][j].ToArray());
                    /*for(int k = 0; k < m; k++)
                    {
                        Console.Write(all[i][j][k] + " ");
                    }
                    Console.WriteLine();*/
                }
            }
            return res;
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}