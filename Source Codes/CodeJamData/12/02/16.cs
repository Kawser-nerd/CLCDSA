using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    static class Program
    {
        static T[] ReadArray<T>(this StreamReader sr, Converter<string, T> parse)
        {
            return Array.ConvertAll(sr.ReadLine().Split(' '), parse);
        }
        static int Solve(int S, int p, int[] t)
        {
            int count = 0;
            Array.Sort(t, (x, y) => y - x);
            foreach (int n in t)
            {
                int best = (n + 2) / 3;
                if (best >= p)
                {
                    count++;
                }
                else if (best == p - 1)
                {
                    if (1 < n && n < 28 && n % 3 != 1)
                    {
                        if (S > 0)
                        {
                            count++;
                            S--;
                        }
                    }
                }
            }
            return count;
        }
        static void Main(string[] args)
        {
            string name = "../B-large";

            StreamReader sr = new StreamReader(name + ".in");
            StreamWriter sw = new StreamWriter(name + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                int[] n = sr.ReadArray(int.Parse);
                int[] t = new int[n[0]];
                Array.Copy(n, 3, t, 0, n[0]);
                sw.WriteLine("Case #{0}: {1}", i, Solve(n[1], n[2], t));
                Console.WriteLine("Case #{0}: Done", i);
            }
            sw.Close();
            sr.Close();
        }
    }
}
