using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string name = "../C-small-attempt1";

            StreamReader sr = new StreamReader(name + ".in");
            StreamWriter sw = new StreamWriter(name + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                string[] str = sr.ReadLine().Split(' ');
                int N = int.Parse(str[0]);
                long L = long.Parse(str[1]);
                long H = long.Parse(str[2]);
                long[] f = Array.ConvertAll(sr.ReadLine().Split(' '), x => long.Parse(x));
                Array.Resize(ref f, N);
                sw.WriteLine(string.Format("Case #{0}: {1}", i, Solve(f, L, H)));
                Console.WriteLine(string.Format("Case #{0}: Done", i));
            }
            sw.Close();
            sr.Close();
        }
        static string Solve(long[] f, long L, long H)
        {
            for (long i = L; i <= H; i++)
            {
                if (!Array.Exists(f, x => x % i != 0 && i % x != 0)) return i.ToString();
            }
            return "NO";
        }
    }
}
