using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;
using System.Numerics;

namespace A
{
    class Program
    {
        static void ConvertToGroups(string s)
        {

        }

        static int Solve(string[] s)
        {
            int N = s.Length;
            string[] chars = new string[N];
            List<int>[] freqs = new List<int>[N];

            for (int i = 0; i < N; i++)
            {
                List<char> cs = new List<char>();
                List<int> fs = new List<int>();

                foreach (var c in s[i])
                {
                    if (cs.Count == 0 || cs.Last() != c)
                    {
                        cs.Add(c);
                        fs.Add(1);
                    }
                    else
                    {
                        fs[fs.Count - 1]++;
                    }
                }

                chars[i] = new String(cs.ToArray());
                freqs[i] = fs;
            }

            for (int i = 1; i < N; i++)
                if (chars[i] != chars[i - 1])
                    return -1;

            int total = 0;
            int M = chars[0].Length;
            for (int j = 0; j < M; j++)
            {
                int best = int.MaxValue;
                for (int ca = 0; ca <= 100; ca++)
                {
                    int sum = 0;
                    for (int i = 0; i < N; i++)
                    {
                        sum += Math.Abs(ca - freqs[i][j]);
                    }

                    best = Math.Min(best, sum);
                }

                total += best;
            }

            return total;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                int N = int.Parse(Console.ReadLine());
                string[] s = new string[N];

                for (int i = 0; i < N; i++)
                    s[i] = Console.ReadLine();

                int result = Solve(s);
                Console.WriteLine("Case #{0}: {1}", t, result >= 0 ? result.ToString() : "Fegla Won");
            }
        }
    }
}
