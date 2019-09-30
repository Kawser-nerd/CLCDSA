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
        static List<int> Recycle(int n)
        {
            List<int> list = new List<int>();
            int j = 1;
            while (j * 10 <= n) { j *= 10; }
            for (int i = 10; i <= n; i *= 10, j /= 10)
            {
                int m = (n % i) * j + (n / i);
                if (m > n && !list.Contains(m))
                {
                    list.Add(m);
                }
            }
            return list;
        }
        static int Solve(int A, int B)
        {
            int count = 0;
            for (int i = A; i <= B; i++)
            {
                count += Recycle(i).Count(x => x <= B);
            }
            return count;
        }
        static void Main(string[] args)
        {
            string name = "../C-large";

            StreamReader sr = new StreamReader(name + ".in");
            StreamWriter sw = new StreamWriter(name + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                int[] n = sr.ReadArray(int.Parse);
                sw.WriteLine("Case #{0}: {1}", i, Solve(n[0], n[1]));
                Console.WriteLine("Case #{0}: Done", i);
            }
            sw.Close();
            sr.Close();
        }
    }
}
