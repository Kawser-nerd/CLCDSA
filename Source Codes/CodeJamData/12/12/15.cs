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
        struct Level
        {
            public int a;
            public int b;
            public int earned;
        }
        static bool Complete(int N, Level[] levels, ref int star)
        {
            Array.Sort(levels, (x, y) => (x.b == y.b) ? y.a - x.a : y.b - x.b);
            for (int i = 0; i < N; i++)
            {
                if (star >= levels[i].b && levels[i].earned < 2)
                {
                    star += 2 - levels[i].earned;
                    levels[i].earned = 2;
                    return true;
                }
            }
            for (int i = 0; i < N; i++)
            {
                if (star >= levels[i].a && levels[i].earned < 1)
                {
                    star += 1 - levels[i].earned;
                    levels[i].earned = 1;
                    return true;
                }
            }
            return false;
        }
        static string Solve(int N, Level[] levels)
        {
            int count = 0;
            int star = 0;
            while (Complete(N, levels, ref star))
            {
                count++;
            }
            return (star == N * 2) ? count.ToString() : "Too Bad";
        }
        static void Main(string[] args)
        {
            string name = "../B-large";

            StreamReader sr = new StreamReader(name + ".in");
            StreamWriter sw = new StreamWriter(name + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                int N = int.Parse(sr.ReadLine());
                Level[] levels = new Level[N];
                int[] a = new int[N];
                int[] b = new int[N];
                for (int j = 0; j < N; j++)
                {
                    int[] n = sr.ReadArray(int.Parse);
                    levels[j].a = n[0];
                    levels[j].b = n[1];
                }
                sw.WriteLine("Case #{0}: {1}", i, Solve(N, levels));
                Console.WriteLine("Case #{0}: Done", i);
            }
            sw.Close();
            sr.Close();
        }
    }
}
