using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

using System.Numerics;

namespace ExampleApp
{
    class Program
    {
        class Task
        {
            public int Number;

            public BigInteger M;
            public BigInteger N;
            public BigInteger[] O;
            public BigInteger[] E;
            public BigInteger[] P;

            public static BigInteger Modulo = 1000002013;

            public static BigInteger[] ReadInts(string s)
            {
                string[] splitted = s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int num = splitted.Length;
                BigInteger[] r = new BigInteger[num];
                for (int i = 0; i < num; i++)
                    r[i] = BigInteger.Parse(splitted[i]);
                return r;
            }

            public static Task ReadMe(int num, StreamReader sr)
            {
                Task t = new Task() { Number = num };

                BigInteger[] q = ReadInts(sr.ReadLine());

                t.N = q[0];
                t.M = q[1];

                t.O = new BigInteger[(int)t.M];
                t.E = new BigInteger[(int)t.M];
                t.P = new BigInteger[(int)t.M];

                for (int i = 0; i < t.M; i++)
                {
                    q = ReadInts(sr.ReadLine());
                    t.O[i] = q[0];
                    t.E[i] = q[1];
                    t.P[i] = q[2];
                }

                return t;
            }

            private BigInteger Fare(BigInteger dist)
            {
                return ((N + N - dist + 1) * dist) / 2;
            }

            private string SolveInner()
            {
                BigInteger mustPay = 0;
                SortedList<BigInteger, BigInteger[]> stops = new SortedList<BigInteger, BigInteger[]>();
                for (int i = 0; i < (int)M; i++)
                {
                    if (!stops.ContainsKey(O[i]))
                    {
                        stops.Add(O[i], new BigInteger[2]);
                    }
                    if (!stops.ContainsKey(E[i]))
                    {
                        stops.Add(E[i], new BigInteger[2]);
                    }

                    stops[O[i]][0] += P[i];
                    stops[E[i]][1] += P[i];

                    mustPay += P[i] * Fare(E[i] - O[i]);
                }

                BigInteger paid = 0;
                List<BigInteger> currentStops = new List<BigInteger>();
                List<BigInteger> cards = new List<BigInteger>();


                foreach (BigInteger stop in stops.Keys)
                {
                    var oe = stops[stop];
                    BigInteger oo = oe[0];
                    BigInteger ee = oe[1];
                    if (oo == ee)
                        continue;
                    if (oo > ee)
                    {
                        cards.Add(oo - ee);
                        currentStops.Add(stop);
                    }
                    else
                    {
                        BigInteger shod = ee - oo;
                        while (shod != 0)
                        {
                            BigInteger givestop = currentStops[currentStops.Count - 1];
                            BigInteger num = cards[currentStops.Count - 1];

                            BigInteger curshod = (num > shod) ? shod : num;
                            paid += curshod * Fare(stop - givestop);
                            if (curshod == num)
                            {
                                int iii = currentStops.Count - 1;
                                currentStops.RemoveAt(iii);
                                cards.RemoveAt(iii);
                            }
                            else
                            {
                                cards[currentStops.Count - 1] -= curshod; 
                            }
                            shod -= curshod;
                        }
                    }
                }


                return ((mustPay - paid) % Modulo).ToString();
            }

            public IEnumerable<string> Solve()
            {
                yield return String.Format("Case #{0}: {1}", Number, SolveInner());
            }
        }

        static void Main(string[] args)
        {
            using (StreamWriter sw = new StreamWriter(args.Length > 0 ? new FileStream(args[1], FileMode.Create) : Console.OpenStandardOutput()))
            {
                int tasksCount;

                List<Task> tasks = new List<Task>();
                using (StreamReader sr = new StreamReader(args.Length > 0 ? new FileStream(args[0], FileMode.Open) : Console.OpenStandardInput()))
                {
                    tasksCount = int.Parse(sr.ReadLine());
                    for (int i = 0; i < tasksCount; i++)
                        tasks.Add(Task.ReadMe(i + 1, sr));
                }

                foreach (Task t in tasks)
                {
                    string[] solution = t.Solve().ToArray();
                    WriteLinesToOutput(sw, solution);
                }
            }
        }

        private static void WriteLinesToOutput(StreamWriter sw, params string[] lines)
        {
            foreach (string line in lines)
                sw.WriteLine(line);
        }


        public static class Viborka
        {
            public static IEnumerable<bool[]> GetAllSubsets(int len)
            {
                bool[] v = Enumerable.Range(0, len).Select(i => false).ToArray();
                while (true)
                {
                    bool[] next = new bool[len];
                    v.CopyTo(next, 0);
                    yield return next;

                    int i;
                    for (i = len - 1; i >= 0; i--)
                    {
                        if (v[i] == false)
                            break;
                    }
                    if (i < 0) break;

                    v[i] = true;
                    for (int j = i + 1; j < len; j++)
                        v[j] = false;
                }
            }

            public static IEnumerable<int[]> GetAllWithoutRepeats(int all, int take)
            {
                int[] v = Enumerable.Range(0, take).ToArray();
                while (true)
                {
                    int[] next = new int[take];
                    v.CopyTo(next, 0);
                    yield return next;
                    int i;
                    for (i = take - 1; i >= 0; i--)
                    {
                        if (v[i] != all + i - take)
                            break;
                    }
                    if (i < 0) break;
                    int k = v[i];
                    for (; i < take; i++)
                        v[i] = ++k;
                }
            }

            public static IEnumerable<int[]> GetAllWithRepeats(int all, int take)
            {
                int[] v = Enumerable.Range(0, take).Select(i => 0).ToArray();
                while (true)
                {
                    int[] next = new int[take];
                    v.CopyTo(next, 0);
                    yield return next;

                    int i;
                    for (i = take - 1; i >= 0; i--)
                    {
                        if (v[i] != all - 1)
                            break;
                    }
                    if (i < 0) break;
                    int k = v[i] + 1;
                    for (; i < take; i++)
                        v[i] = k;
                }
            }
        }

        public static BigInteger Cnk(BigInteger n, BigInteger k)
        {
            if (k <= 0 || k >= n)
                return 1;
            if (n - k < k)
                k = n - k;
            BigInteger a = 1;
            BigInteger b = 1;
            for (BigInteger i = 0; i < k; i++)
            {
                a *= (n - i);
                b *= i + 1;
            }
            return a / b;
        }
    }
}
