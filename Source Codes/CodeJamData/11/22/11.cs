using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace B1_cs_
{
    class Program
    {
        public static Int64[,] data;
        public static int c, d;

        public static bool IsOK(Int64 time)
        {
            Int64 pos = (data[0,0]) - time - d;
            for (int i = 0; i < c; i++)
            {
                if (pos + data[i, 1] * d > data[i, 0] + time) return false;
                else pos = Math.Max(data[i, 0] - time + (data[i, 1] - 1) * d, pos + data[i, 1] * d);
                if (pos - data[i, 0] > time) return false;  
            }
            return true;
        }

        static void Main()
        {
            TextReader fin = File.OpenText("input.txt");
            TextWriter fout = File.CreateText("output.txt");
             int t = int.Parse(fin.ReadLine());
            for (int q = 0; q < t; q++)
            {
                fout.Write("Case #{0}: ", q + 1);
                string[] s = fin.ReadLine().Split();
                c = int.Parse(s[0]);
                d = int.Parse(s[1]) * 2;
                data = new Int64[c, 2];
                for (int i = 0; i < c; i++)
                {
                    s = fin.ReadLine().Split();
                    data[i,0] = int.Parse(s[0]) * 2;
                    data[i,1] = int.Parse(s[1]);
                }
                Int64 lo = 0;
                Int64 hi = Int64.MaxValue;
                while (lo < hi)
                {
                    Int64 av = (lo + hi) / 2;
                    if (IsOK(av)) hi = av;
                    else lo = av + 1;
                }
                fout.WriteLine((double)(lo)/2);
            }
            fin.Close();
            fout.Close();
        }
    }
}
