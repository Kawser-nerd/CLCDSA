#define WITH_TEST_NUMBERS

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static List<List<string>> tests = new List<List<string>>();
        static List<string> answers = new List<string>();

        static void Main(string[] args)
        {
            ReadTests();
            Test();
            OutAnswers();
        }

        private static void ReadTests()
        {
            System.IO.StreamReader sr = new System.IO.StreamReader("input.txt");
#if WITH_TEST_NUMBERS
            sr.ReadLine();
#endif
            while (!sr.EndOfStream)
            {
                List<string> cur_test = new List<string>();
                cur_test.Add(sr.ReadLine());
                tests.Add(cur_test);
            }
            while (answers.Count < tests.Count)
            {
                answers.Add("");
            }
        }

        private static bool can(int n, long m, long p)
        {
            long rem_better = m;
            long position = 0;
            for (int i = 0; i < n; ++i)
            {
                position <<= 1;
                if (rem_better > 0)
                {
                    rem_better = (rem_better - 1) / 2;
                    position |= 1;
                }
            }
            return position < p;
        }

        private static long SolveGuaranteed(int n, long p)
        {
            if (p == 0)
            {
                return -1;
            }
            long l = 0;
            long r = ((long)(1)) << n;
            while (r - l > 1)
            {
                long m = (l + r) / 2;
                if (can(n, m, p))
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
            return l;
        }

        private static void Solve(int num)
        {
            int n = Convert.ToInt32(tests[num][0].Split(' ')[0]);
            long p = Convert.ToInt64(tests[num][0].Split(' ')[1]);
            long two_n = ((long)(1)) << n;
            answers[num] = SolveGuaranteed(n, p).ToString() + ' ' + (two_n - SolveGuaranteed(n, two_n - p) - 2).ToString();
        }

        private static void Test()
        {
            ParallelOptions po = new ParallelOptions() { MaxDegreeOfParallelism = 12 };
#if DEBUG
            po.MaxDegreeOfParallelism = 1;
#endif
            Parallel.For(0, tests.Count, Solve);
        }

        private static void OutAnswers()
        {
            System.IO.StreamWriter sw = new System.IO.StreamWriter("output.txt");
            for (int i = 0; i < answers.Count; ++i)
            {
                sw.WriteLine("Case #{0}: {1}", i + 1, answers[i]);
            }
            sw.Flush();
            sw.Close();
        }
    }
}
