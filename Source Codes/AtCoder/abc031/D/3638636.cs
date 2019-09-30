using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_031
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] kn = ReadInts();
            int k = kn[0];
            int n = kn[1];
            var v = new string[n];
            var w = new string[n];
            for(int i = 0; i < n; i++)
            {
                string[] str = Read().Split();
                v[i] = str[0];
                w[i] = str[1];
            }
            int allPat = (int)Math.Pow(3, k);
            for(int i = 0; i < allPat; i++)
            {
                int now = i;
                var cnts = new int[k];
                for(int j = 0; j < k; j++)
                {
                    cnts[j] = now % 3 + 1;
                    now /= 3;
                }
                var strs = new string[k];
                bool invalid = false;
                for(int j = 0; j < n; j++)
                {
                    int cnt = 0;
                    for(int l = 0; l<v[j].Length; l++)
                    {
                        int num = v[j][l] - '1';
                        if (cnt+cnts[num] > w[j].Length)
                        {
                            invalid = true;
                            break;
                        }
                        if (strs[num] == null)
                        {
                            strs[num] = w[j].Substring(cnt, cnts[num]);
                        }
                        else if(
                            !strs[num].Equals(w[j].Substring(cnt,cnts[num])))
                        {
                            invalid = true;
                            break;
                        }
                        cnt += cnts[num];
                    }
                    if (cnt!=w[j].Length) invalid = true;
                    if (invalid) break;
                }
                if (!invalid)
                {
                    for(int j = 0; j < k; j++)
                    {
                        Console.WriteLine(strs[j]);
                    }
                    return;
                }
            }
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