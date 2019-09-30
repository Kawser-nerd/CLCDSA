using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ
{
    class Program
    {

        class Solver
        {
            int W, L;

            void DFS(out List<int> d1, out List<int> d2, List<int> r, int W, int L,int N = 0)
            {
                if (W > L)
                {
                    DFS(out d2, out d1, r, L, W, N);
                    return;
                }
                d1=new List<int>();d2=new List<int>();
                if (N == r.Count) return;
                int x = 0;
                int i;
                for (i = N; i < r.Count; i++)
                {
                    if (x < W)
                    {
                        d1.Add(x);
                        d2.Add(0);
                    }
                    else
                    {
                        break;
                    }
                    x += r[i];
                    if (i + 1 < r.Count) x += r[i + 1];
                }
                if (i == r.Count) return;
                List<int> d4 = new List<int>(), d3 = new List<int>();
                DFS(out d3, out d4, r, W, L - r[N] - r[i], i);
                for (int j = 0; j < d3.Count; j++)
                {
                    d1.Add(d3[j]);
                    d2.Add(d4[j] + r[N] + r[i]);
                }
                return;
            }
            struct PII:IComparable
            {
                public int a, b;
                public PII(int x, int y)
                {
                    a = x; b = y;
                }
                public int CompareTo(object obj)
                {
                    return a.CompareTo(((PII)obj).a);
                }
            }
            public string Solve(MyIO io)
            {
                StringBuilder sb = new StringBuilder();
                int N = io.NextInt;
                W = io.NextInt; L = io.NextInt;
                List<int> r = new List<int>();
                List<PII> lp = new List<PII>();


                for(int i=0;i<N;i++)
                {
                    r.Add(io.NextInt);
                }
                for (int i = 0; i < N; i++)
                {
                    lp.Add(new PII(r[i], i));
                }
                lp.Sort();
                lp.Reverse();

                for (int i = 0; i < N; i++)
                {
                    r[i] = lp[i].a;
                }
                r.Sort(); r.Reverse();
                List<int> d1,d2;
                DFS(out d1, out d2, r, W, L, 0);
                if (d1.Count != r.Count)
                {
                    Console.WriteLine("Wrong");
                }
                for (int i = 0; i < d1.Count; i++)
                {
                    if (d1[i] > W || d2[i] > L)
                    {
                        Console.WriteLine("Wrong");
                    }
                }
                for (int i = 0; i < d1.Count; i++)
                {
                    for (int j = i + 1; j < d1.Count; j++)
                    {
                        if (Math.Max(Math.Abs(d1[i] - d1[j]), Math.Abs(d2[i] - d2[j])) < r[i] + r[j])
                        {
                            Console.WriteLine("Wrong");
                        }
                    }
                }

                int[] dd1 = new int[N], dd2 = new int[N];
                for (int i = 0; i < N; i++)
                {
                    dd1[lp[i].b] = d1[i];
                    dd2[lp[i].b] = d2[i];
                }
                    for (int i = 0; i < d1.Count; i++)
                    {
                        sb.Append(dd1[i] + " ");
                        sb.Append(dd2[i] + (i == d1.Count - 1 ? "\n" : " "));
                    }
                return sb.ToString();
            }
        }
        static void Main(string[] args)
        {
            MyIO io = new MyIO(new StreamReader("in.txt"));
            int caseCount = io.NextInt;
            for (int i = 0; i < caseCount; i++)
            {
                Solver solve = new Solver();
                string res = solve.Solve(io);
                io.Write("Case #{0}: {1}", i + 1, res);
                Console.Write("Case #{0}: {1}", i + 1, res);
            }
            io.Flush();
        }


        class MyIO
        {
            TextReader reader;
            TextWriter writer = new StreamWriter("out.txt");
            string[] tokens;
            int pointer;
            public MyIO(TextReader rd)
            {
                reader = rd;
            }
            public string NextLine()
            {
                try
                {
                    return reader.ReadLine();
                }
                catch (IOException)
                {
                    return null;
                }
            }
            public string NextString
            {
                get
                {
                    try
                    {
                        while (tokens == null || pointer >= tokens.Length)
                        {
                            tokens = NextLine().Split(new char[] { ' ' }, System.StringSplitOptions.RemoveEmptyEntries);
                            pointer = 0;
                        }
                        return tokens[pointer++];
                    }
                    catch (IOException)
                    {
                        return null;
                    }
                }
            }
            public int NextInt
            {
                get { return int.Parse(NextString); }
            }
            public long NextLong
            {
                get { return long.Parse(NextString); }
            }
            public int NextDouble
            {
                get { return int.Parse(NextString); }
            }
            public bool Write(string format, params object[] args)
            {
                writer.Write(format, args);
                return true;
            }
            public void WriteLine(string format, params object[] args)
            {
                writer.WriteLine(format, args);
            }
            public void WriteLine(object obj)
            {
                writer.WriteLine("{0}", obj);
            }
            public void WriteLine()
            {
                writer.WriteLine();
            }
            public void Write(object obj)
            {
                writer.Write("{0}", obj);
            }
            public void Flush()
            {
                writer.Flush();
            }
        }
    }
}
