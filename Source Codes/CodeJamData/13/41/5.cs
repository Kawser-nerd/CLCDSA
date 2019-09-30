#define WITH_TEST_NUMBERS

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
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
                int m = Convert.ToInt32(cur_test[0].Split(' ')[1]);
                for (int i = 0; i < m; ++i)
                {
                    cur_test.Add(sr.ReadLine());
                }
                tests.Add(cur_test);
            }
            while (answers.Count < tests.Count)
            {
                answers.Add("");
            }
        }

        private static long GetCost(long n, long q, long start, long finish)
        {
            return q * (finish - start) * (2 * n - finish + start + 1) / 2;
        }

        private static void Solve(int p)
        {
            const long mod = 1000002013;
            long honest = 0;
            long optimal = 0;
            int n = Convert.ToInt32(tests[p][0].Split(' ')[0]);
            int m = Convert.ToInt32(tests[p][0].Split(' ')[1]);
            SortedDictionary<int, long> passangers = new SortedDictionary<int, long>();
            List<Tuple<int, int>> enters = new List<Tuple<int, int>>();
            for (int i = 0; i < m; ++i)
            {
                string[] parts = tests[p][i + 1].Split(' ');
                int start = Convert.ToInt32(parts[0]);
                int finish = Convert.ToInt32(parts[1]);
                int q = Convert.ToInt32(parts[2]);
                honest += GetCost(n, q, start, finish);
                honest %= mod;
                enters.Add(new Tuple<int, int>(start, q));
                enters.Add(new Tuple<int, int>(finish, -q));
            }
            enters.Sort((lhs, rhs) =>
                {
                    if (lhs.Item1 < rhs.Item1)
                    {
                        return -1;
                    }
                    if (lhs.Item1 > rhs.Item1)
                    {
                        return 1;
                    }
                    if (lhs.Item2 < rhs.Item2)
                    {
                        return 1;
                    }
                    if (lhs.Item2 > rhs.Item2)
                    {
                        return -1;
                    }
                    return 0;
                });
            foreach (Tuple<int, int> _t in enters)
            {
                Tuple<int, int> t = _t;
                if (t.Item2 > 0)
                {
                    if (!passangers.ContainsKey(t.Item1))
                    {
                        passangers[t.Item1] = 0;
                    }
                    passangers[t.Item1] += t.Item2;
                }
                else
                {
                    while (t.Item2 < 0)
                    {
                        int x = passangers.Keys.Max();
                        int d = (int)Math.Min((long)-t.Item2, passangers[x]);
                        optimal += GetCost(n, d, x, t.Item1);
                        optimal %= mod;
                        passangers[x] -= d;
                        t = new Tuple<int, int>(t.Item1, t.Item2 + d);
                        if (passangers[x] == 0)
                        {
                            passangers.Remove(x);
                        }
                    }
                }
            }
            answers[p] = ((honest - optimal + mod) % mod).ToString();
        }

        private static void Test()
        {
            ParallelOptions po = new ParallelOptions(){ MaxDegreeOfParallelism = 12};
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
