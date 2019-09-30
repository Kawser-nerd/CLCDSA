using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Numerics;

namespace A
{
    class Program
    {
        static long Solve(string s, int nc)
        {
            int n = s.Length;
            int curr_counter = 0;

            List<int> possibleEnds = new List<int>();

            for (int i = 0; i < n; i++)
            {
                char c = s[i];
                bool v = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

                if(v)
                    curr_counter = 0;
                else
                {
                    curr_counter++;
                }

                if (curr_counter >= nc)
                    possibleEnds.Add(i);
            }

            possibleEnds.Add(n);

            long counter = 0;
            for (int i = 0; i < possibleEnds.Count - 1; i++)
            {
                int st = possibleEnds[i] - nc;
                long mul1 = st + 2;

                int mul2 = possibleEnds[i + 1] - possibleEnds[i];

                counter += mul1 * mul2;
            }


            return counter;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                string s = line[0];
                int n = int.Parse(line[1]);
                Console.WriteLine("Case #{0}: {1}", t, Solve(s, n));
            }
        }
    }
}
