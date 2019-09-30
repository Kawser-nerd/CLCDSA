using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _010
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nmyz = ReadInts();
            int n = nmyz[0];
            int m= nmyz[1];
            long y = nmyz[2];
            long z = nmyz[3];
            char[] cs = new char[m];
            var pDict = new Dictionary<char, int[]>();
            for(int i = 0; i < m; i++)
            {
                string[] s = Read().Split();
                cs[i] = s[0][0];
                pDict.Add(cs[i], new int[2] { i, int.Parse(s[1]) });
            }
            string bs = Read();
            var dict = new Dictionary<char, Dictionary<int, long>>();
            dict.Add('0', new Dictionary<int, long>());
            dict['0'].Add(0, 0);
            long res = 0;
            for (int i = 0; i < n; i++)
            {
                var nextDict = new Dictionary<char, Dictionary<int, long>>();
                foreach(char key in dict.Keys)
                {
                    foreach(int key2 in dict[key].Keys)
                    {
                        //not summation
                        if (!nextDict.ContainsKey(key))
                        {
                            nextDict.Add(key, new Dictionary<int, long>());
                        }
                        if (!nextDict[key].ContainsKey(key2))
                        {
                            nextDict[key].Add(key2, long.MinValue);
                        }
                        nextDict[key][key2] 
                            = Max(nextDict[key][key2], dict[key][key2]);

                        //summation
                        long score = dict[key][key2] + pDict[bs[i]][1];
                        if (key == bs[i]) score += y;
                        if ((key2 & (1 << pDict[bs[i]][0])) == 0
                            && key2 + (1 << pDict[bs[i]][0]) == (1 << m) - 1)
                            score += z;
                        int pat = key2 | (1 << pDict[bs[i]][0]);
                        if (!nextDict.ContainsKey(bs[i]))
                        {
                            nextDict.Add(bs[i], new Dictionary<int, long>());
                        }
                        if (!nextDict[bs[i]].ContainsKey(pat))
                        {
                            nextDict[bs[i]].Add(pat, long.MinValue);
                        }
                        nextDict[bs[i]][pat]
                            = Max(nextDict[bs[i]][pat], score);
                        res = Max(res, nextDict[bs[i]][pat]);
                    }
                }
                dict = nextDict;
            }
            WriteLine(res);
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}