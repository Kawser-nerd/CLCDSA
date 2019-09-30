using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R1CProblemA
{
    class Program
    {
        struct Cake: IComparable<Cake>
        {
            public long R;
            public long H;

            public int CompareTo(Cake other)
            {
                return (R * H).CompareTo(other.R * other.H);
            }
        }
        static void SolveAllTests(TextReader input, TextWriter output)
        {
            int TT = int.Parse(input.ReadLine());
            for (int testCase = 1; testCase <= TT; testCase++)
            {
                string[] s = input.ReadLine().Split();
                int N = int.Parse(s[0]);
                int K = int.Parse(s[1]);
                Cake[] cakes = new Cake[N];
                for (int i = 0; i < N; ++i)
                {
                    s = input.ReadLine().Split();
                    long RR = long.Parse(s[0]);
                    long HH = long.Parse(s[1]);
                    cakes[i] = new Cake() { R = RR, H = HH };
                }

                Array.Sort(cakes);
                long bestS = 0;
                for (int i = 0; i < N; ++i)
                {
                    long S = cakes[i].R * cakes[i].R + 2 * cakes[i].R * cakes[i].H;
                    int cnt = 1;
                    for (int j = N - 1; j >= 0 && cnt < K; --j)
                    {
                        if (j != i && cakes[j].R <= cakes[i].R)
                        {
                            S += 2 * cakes[j].R * cakes[j].H;
                            cnt++;
                        }
                    }
                    bestS = Math.Max(bestS, S);
                }
                double res = bestS * Math.PI;
                output.WriteLine("Case #{0}: {1}", testCase, res.ToString("G30"));
            }
        }

        static void Main(string[] args)
        {
            try
            {
                SolveAllTests(Console.In, Console.Out);
                /*using (TextReader input = File.OpenText("test.in"))
                {
                    using (TextWriter output = File.CreateText("C-test.out"))
                        SolveAllTests(input, output);
                }*/
            }
            catch (Exception e)
            {
                Console.Error.WriteLine("ERROR: " + e.Message);
            }
        }
    }
}
