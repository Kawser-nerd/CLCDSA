using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJamSharp
{

    class Program
    {
        static int BitCount(int x)
        {
            int ret = 0;
            while (x > 0)
            {
                x = x & (x - 1);
                ret++;
            }
            return ret;
        }

        static int Val(string bin)
        {
            int ret = 0;
            foreach (char c in bin)
            {
                ret *= 2;
                if (c == 'x') ret++;
            }
            return ret;
        }

        static void Main(string[] args)
        {
            using (StreamReader sr = File.OpenText(@"C:\Google\C.in"))
            using (StreamWriter sout = File.CreateText(@"C:\Google\C.out"))
            {
                string line = sr.ReadLine();
                int cases = int.Parse(line);
                for (int cas = 1; cas <= cases; cas++)
                {
                    line = sr.ReadLine();
                    string[] items = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                    int M = int.Parse(items[0]);
                    int N = int.Parse(items[1]);
                    int[] map = new int[M];

                    for (int i = 0; i < map.Length; i++)
                    {
                        line = sr.ReadLine().Trim();
                        map[i] = Val(line);
                    }
                    int states = 1 << N;
                    int[] prevCount = new int[1 << N];
                    int[] nextCount = new int[1 << N];

                    foreach (int broke in map)
                    {
                        for (int cur = 0; cur < states; cur++)
                        {
                            if (((cur & broke) == 0) && (((cur << 1) & cur) == 0))
                            {
                                int cnt = BitCount(cur);
                                for (int prev = 0; prev < states; prev++)
                                    if ((((cur << 1) & prev) == 0) && (((cur >> 1) & prev) == 0))
                                    {
                                        nextCount[cur] = Math.Max(nextCount[cur], cnt + prevCount[prev]);
                                    }
                            }
                        }
                        prevCount = nextCount;
                        nextCount = new int[1 << N];
                    }
                    int max = 0;
                    foreach (int val in prevCount) max = Math.Max(max, val);

                    sout.WriteLine("Case #{0}: {1}", cas, max);
                }
            }
        }
    }
}
