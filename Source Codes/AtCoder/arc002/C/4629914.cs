using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _002
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            char[] cs = Read().ToCharArray();
            char[][] cmds = new char[16][] {"AA".ToCharArray(),
                "BB".ToCharArray(),"XX".ToCharArray(),"YY".ToCharArray(),
                "AB".ToCharArray(),"AX".ToCharArray(),"AY".ToCharArray(),
                "BA".ToCharArray(),"BX".ToCharArray(),"BY".ToCharArray(),
                "XA".ToCharArray(),"XB".ToCharArray(),"XY".ToCharArray(),
                "YA".ToCharArray(),"YB".ToCharArray(),"YX".ToCharArray(),};
            int res = n;
            for(int i = 0; i < 16; i++)
            {
                for(int j = i + 1; j < 16; j++)
                {
                    int tmp = 0;
                    for (int k = 0; k < n; k++)
                    {
                        if (k + 1 < n
                            && ((cs[k] == cmds[i][0]
                            && cs[k + 1] == cmds[i][1])
                            || (cs[k] == cmds[j][0]
                            && cs[k + 1] == cmds[j][1])))
                        {
                            k++;
                        }
                        tmp++;
                    }
                    res = Min(res, tmp);
                }
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