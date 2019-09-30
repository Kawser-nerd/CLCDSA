using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_032
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nw = ReadInts();
            int n = nw[0];
            long w = nw[1];
            var vws = new long[n][];
            long wMax = 0;
            for(int i = 0; i < n; i++)
            {
                vws[i] = ReadLongs();
                wMax = Math.Max(wMax, vws[i][1]);
            }
            if (n <= 30)
            {
                Console.WriteLine(ValueDP(vws, w));
            }
            else
            {
                if (wMax <= 1000)
                {
                    Console.WriteLine(BasicDP(vws, w));
                }
                else
                {
                    Console.WriteLine(BasicDP2(vws, w));
                }
            }
        }

        static long ValueDP(long[][] vws,long w)
        {
            var dict = new Dictionary<long, long>();
            dict.Add(0, 0);
            long max = 0;
            for(int i = 0; i < vws.GetLength(0); i++)
            {
                var nextDict = new Dictionary<long, long>();
                foreach(long key in dict.Keys)
                {
                    if (nextDict.ContainsKey(key))
                    {
                        nextDict[key] = Math.Max(nextDict[key], dict[key]);
                    }
                    else
                    {
                        nextDict.Add(key, dict[key]);
                    }

                    long val = dict[key] + vws[i][0];
                    long weight = key + vws[i][1];
                    if (w < weight) continue;

                    if (dict.ContainsKey(weight))
                    {
                        val=Math.Max(val, dict[weight]);
                    }
                    if (nextDict.ContainsKey(weight))
                    {
                        nextDict[weight] = Math.Max(val, nextDict[weight]);
                    }
                    else
                    {
                        nextDict.Add(weight, val);
                    }
                    max = Math.Max(max, val);
                }
                dict = nextDict;
            }
            return max;
        }

        static long BasicDP(long[][] vws,long w)
        {
            int n = vws.Length;
            var dp = new long[Math.Min(n * 1000, w) + 1];
            for(int i = 0; i < n; i++)
            {
                var next = new long[dp.Length];
                for(int j = 0; j < vws[i][1]; j++)
                {
                    next[j] = dp[j];
                }
                for(long j = vws[i][1]; j < dp.Length; j++)
                {
                    next[j] = Math.Max(dp[j], dp[j - vws[i][1]] + vws[i][0]);
                }
                dp = next;
            }
            return dp[dp.Length - 1];
        }


        static long BasicDP2(long[][] vws, long w)
        {
            int n = vws.Length;
            var dp = new long[n * 1000 + 1];
            long val = 0;
            for (int i = 0; i < n; i++)
            {
                var next = new long[dp.Length];
                for (int j = 0; j < vws[i][0]; j++)
                {
                    next[j] = dp[j];
                }
                for (long j = vws[i][0]; j < dp.Length; j++)
                {
                    if (j - vws[i][0] > 0 && dp[j - vws[i][0]] == 0
                        || dp[j - vws[i][0]] + vws[i][1] > w)
                    {
                        next[j] = dp[j];
                    }
                    else
                    {
                        if (dp[j] == 0)
                        {
                            next[j] = dp[j - vws[i][0]] + vws[i][1];
                        }
                        else
                        {
                            next[j] 
                                = Math.Min(dp[j], dp[j - vws[i][0]] + vws[i][1]);
                        }
                        val = Math.Max(val, j);
                    }
                }
                dp = next;
            }
            return val;
        }
        static long ValueDP2(long[][] vws, long w)
        {
            var dict = new Dictionary<long, long>();
            dict.Add(0, 0);
            long max = 0;
            for (int i = 0; i < vws.GetLength(0); i++)
            {
                var nextDict = new Dictionary<long, long>();
                foreach (long key in dict.Keys)
                {
                    if (nextDict.ContainsKey(key))
                    {
                        nextDict[key] = Math.Max(nextDict[key], dict[key]);
                    }
                    else
                    {
                        nextDict.Add(key, dict[key]);
                    }

                    long val = key + vws[i][0];
                    long weight = dict[key] + vws[i][1];
                    if (w < weight) continue;

                    if (dict.ContainsKey(val))
                    {
                        weight = Math.Min(weight, dict[val]);
                    }
                    if (nextDict.ContainsKey(val))
                    {
                        nextDict[val] = Math.Max(weight, nextDict[val]);
                    }
                    else
                    {
                        nextDict.Add(val,weight);
                    }
                    max = Math.Max(max, val);
                }
                dict = nextDict;
            }
            return max;
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