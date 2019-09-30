using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_041
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nm = ReadInts();
            int n = nm[0];
            int m = nm[1];
            var bLists = new List<int>[n];
            var eLists = new List<int>[n];
            var xys = new int[m][];
            for(int i = 0; i < n; i++)
            {
                bLists[i] = new List<int>();
                eLists[i] = new List<int>();
            }
            for(int i = 0; i < m; i++)
            {
                xys[i] = ReadInts();
                int x = xys[i][0] - 1;
                int y = xys[i][1] - 1;
                bLists[y].Add(x);
                //if (x < y) bCnts2[y]++;
                eLists[x].Add(y);
                //if (x > y) eCnts2[x]++;
            }
            var dp = new long[1 << n];
            dp[0] = 1;

            for(int i = 1; i < dp.Length; i++)
            {
                long cnt = 0;
                for(int j = 0; j < n; j++)
                {
                    int val = 1 << j;
                    //Console.Write((i & val)==0?"0":"1");
                    if ((i & val) == 0) continue;

                    bool exist = true;
                    for(int k = 0; k < bLists[j].Count; k++)
                    {
                        int checkVal = 1 << bLists[j][k];
                        if ((i & checkVal) == 0)
                        {
                            exist = false;
                            break;
                        }
                    }
                    if (exist)
                    {
                        for (int k = 0; k < eLists[j].Count; k++)
                        {
                            int checkVal = 1 << eLists[j][k];
                            if ((i & checkVal) > 0)
                            {
                                exist = false;
                                break;
                            }
                        }
                    }

                    if (exist) cnt += dp[i - val];
                }
                dp[i] = cnt;
                //Console.WriteLine(dp[i]);
            }

            Console.WriteLine(dp[dp.Length - 1]);
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