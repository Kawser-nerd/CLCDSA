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

            public int R;
            public int N;
            public int M;
            public int K;
            public int[][] Sets;

            public static int[] ReadInts(string s)
            {
                string[] splitted = s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int num = splitted.Length;
                int[] r = new int[num];
                for (int i = 0; i < num; i++)
                    r[i] = int.Parse(splitted[i]);
                return r;
            }

            public static Task ReadMe(int num, StreamReader sr)
            {
                Task t = new Task() { Number = num };

                int[] q = ReadInts(sr.ReadLine());

                t.R = q[0];
                t.N = q[1];
                t.M = q[2];
                t.K = q[3];

                t.Sets = new int[t.R][];

                for (int i = 0; i < t.R; i++)
                    t.Sets[i] = ReadInts(sr.ReadLine());
                
                return t;
            }

            public struct Outcome
            {
                public int A1;
                public int A2;
                public int A3;

                public static Outcome First()
                {
                    return new Outcome { A1 = 2, A2 = 2, A3 = 2 };
                }
                public Outcome Next(int max)
                {
                    Outcome r = new Outcome { A1 = this.A1, A2 = this.A2, A3 = this.A3 + 1};
                    if (r.A3 > max)
                    {
                        r.A3 = 2;
                        r.A2 += 1;
                        if (r.A2 > max)
                        {
                            r.A2 = 2;
                            r.A1++;
                        }
                    }
                    return r;
                }
                public string Validate()
                {
                    Outcome r = new Outcome { };
                    int[] a = new int[] { A1, A2, A3};
                    string b = string.Join("", a.OrderBy(x => x));
                    return b;
                }

                public static Dictionary<int, int> Nablud(string o)
                {
                    Dictionary<int, int> r = new Dictionary<int, int>();
                    for (int i = 0; i < 2; i++)
                    for (int j = 0; j < 2; j++)
                        for (int k = 0; k < 2; k++)
                        {
                            int n = 1;
                            if (i == 1)
                                n *= int.Parse(o[0].ToString());
                            if (j == 1)
                                n *= int.Parse(o[1].ToString());
                            if (k == 1)
                                n *= int.Parse(o[2].ToString());
                            if (r.ContainsKey(n))
                            {
                                r[n] = r[n] + 1;
                            }
                            else
                            {
                                r[n] = 1;
                            }
                        }
                    return r;
                }

                public struct Distrib
                {
                    public int Prob;
                    public Dictionary<int, int> Nabl;
                }
                public static Dictionary<string, Distrib> AllOutcomes = CalcAllOutcomes();

                public static Dictionary<string, Distrib> CalcAllOutcomes()
                {
                    Dictionary<string, int> r = new Dictionary<string, int>();
                    Outcome o = Outcome.First();
                    for (int i = 0; i < 64; i++)
                    {
                        string v = o.Validate();
                        if (r.ContainsKey(v))
                        {
                            r[v] = r[v] + 1;
                        }
                        else
                        {
                            r[v] = 1;
                        }
                        o = o.Next(5);
                    }

                    Dictionary<string, Distrib> k = new Dictionary<string, Distrib>();
                    foreach (string s in r.Keys)
                    {
                        Distrib d = new Distrib { Prob = r[s], Nabl = Nablud(s) };
                        k[s] = d;
                    }
                    return k;
                }
            }

            private double likelyhood(string o, int[] set)
            {
                Outcome.Distrib d = Outcome.AllOutcomes[o];
                double r = Math.Log(d.Prob);
                foreach (int s in set)
                {
                    if (d.Nabl.ContainsKey(s))
                    {
                        r += Math.Log(d.Nabl[s]);
                    }
                    else
                    {
                        return double.MinValue;
                    }
                }
                return r;
            }

            private string SolveSet(int[] set)
            {
                return Outcome.AllOutcomes.Keys.OrderByDescending(o => likelyhood(o, set)).First();
            }

            private IEnumerable<string> SolveInner()
            {
                return Sets.Select(set => SolveSet(set));
            }

            public IEnumerable<string> Solve()
            {
                yield return String.Format("Case #{0}:", Number);
                foreach (string s in SolveInner())
                    yield return s;
            }
        }

        static void Main(string[] args)
        {
            using (StreamWriter sw = new StreamWriter(new FileStream(args[1], FileMode.Create)))
            {
                int tasksCount;

                List<Task> tasks = new List<Task>();
                using (StreamReader sr = new StreamReader(new FileStream(args[0], FileMode.Open)))
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
    }
}
