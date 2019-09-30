using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;

namespace ProblemA
{
    class Program
    {
        class Solver
        {
            public int Solve(long a, int[] m, int index)
            {
                if (index == m.Length)
                {
                    return 0;
                }
                if (a > m[index])
                {
                    return Math.Min(m.Length - index, Solve(a + m[index], m, index + 1));
                }
                else
                {
                    return Math.Min(m.Length - index, 1 + Solve(a + a - 1, m, index));
                }
            }

            public int Solve(int a, int[] m)
            {
                Array.Sort(m);
                if (a == 1)
                    return m.Length;
                return Solve(a, m, 0);
            }
        }

        static void Main(string[] args)
        {
            //string filename = "sample";
            //string filename = "A-small-attempt1";
            string filename = "A-large";
            using (StreamReader reader = new StreamReader("..\\..\\" + filename + ".in"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\" + filename + ".out"))
                {
                    int T = Int32.Parse(reader.ReadLine());
                    Solver solver = new Solver();
                    for (int i = 0; i < T; i++)
                    {
                        string[] tmp = reader.ReadLine().Split();
                        int a = Int32.Parse(tmp[0]);
                        int n = Int32.Parse(tmp[1]);
                        int[] m = new int[n];
                        tmp = reader.ReadLine().Split();
                        for (int j = 0; j < n; j++)
                        {
                            m[j] = Int32.Parse(tmp[j]);
                        }
                        writer.WriteLine("Case #" + (i + 1) + ": " + solver.Solve(a, m));
                    }
                }
            }
        }
    }
}
