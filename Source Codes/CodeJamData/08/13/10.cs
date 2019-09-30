using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace Numbers
{
    class Program
    {
        TextReader cin = Console.In;
        TextWriter cout = Console.Out;

        public Program(string s)
        {
            cin = new StreamReader(s);
            s = s.Substring(0, s.Length - 2) + "out";
            cout = new StreamWriter(s);
        }

        public static void Main(string[] args)
        {
            foreach (string s in Directory.GetFiles(@"C:\Users\Michael\Desktop\GCJ", "*.in"))
            {
                new Program(s).run();
            }
        }

        private int[] cache = { 1, 5, 27, 143, 751,
                                  935, 607, 903, 991, 335,
                                  47, 943, 471, 55, 447,
                                  463, 991, 95, 607, 263,
                                  151, 855, 527, 743, 351,
                                  135, 407, 903, 791, 135, 647 };
        private void run()
        {
            int T = readInt();
            decimal d = (decimal)(3 + Math.Sqrt(5));
            decimal[] ds = new decimal[32];
            ds[0] = d;
            for (int i = 1; i < 6; i++)
                ds[i] = ds[i - 1] * ds[i - 1];
            for (int cn = 1; cn <= T; cn++)
            {
                int n = readInt();
                cout.WriteLine("Case #{0}: {1:000}", cn, cache[n]);
            }
            cout.Close();
        }

        int readInt()
        {
            return int.Parse(cin.ReadLine().Trim());
        }

        int[] readInts()
        {
            return Array.ConvertAll<string, int>(cin.ReadLine().Split(), int.Parse);
        }

        double readDouble()
        {
            return double.Parse(cin.ReadLine().Trim());
        }

        double[] readDoubles()
        {
            return Array.ConvertAll<string, double>(cin.ReadLine().Split(), double.Parse);
        }
    }
}
