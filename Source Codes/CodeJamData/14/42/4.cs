using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
namespace GCJ
{
    class Program
    {
        const long mod = 1000002013;
        class Solver
        {

            public Solver()
            {
            }
            int cal(List<int> l)
            {
                int R = 0;
                for (int i = 0; i < l.Count; i++)
                {
                    for (int j = i + 1; j < l.Count; j++)
                    {
                        if (l[i] > l[j])
                        {
                            R++;
                        }
                    }
                }
                return R;
            }
            int cal2(List<int> l)
            {
                int R = 0;
                for (int i = 0; i < l.Count; i++)
                {
                    for (int j = i + 1; j < l.Count; j++)
                    {
                        if (l[i] < l[j])
                        {
                            R++;
                        }
                    }
                }
                return R;
            }
            int cmp(KeyValuePair<int, int> a1, KeyValuePair<int, int> a2)
            {
                return a1.Key.CompareTo(a2.Key);
            }
            public string Solve(MyIO io)
            {
                int N = io.NextInt;
                List<int> l = new List<int>();
                for (int i = 0; i < N; i++)
                {
                    l.Add(io.NextInt);

                }
                int R = 0;
                for (int i = 0; i < N; i++)
                {
                    int minval = (int)(2 * 1e9), pos = -1;
                    for (int j = 0; j < l.Count; j++)
                    {
                        if (l[j] < minval)
                        {
                            minval = l[j];
                            pos = j;
                        }
                    }
                    R += Math.Min(pos, N - 1 - i - pos);
                    List<int> ll = new List<int>();
                    for (int j = 0; j < l.Count; j++)
                    {
                        if (j != pos)
                        {
                            ll.Add(l[j]);
                        }
                    }
                    l = ll;
                }
                return R.ToString();
            }
       }
        static void Main(string[] args)
        {
            MyIO io = new MyIO(new StreamReader(@"C:\Users\zaq1xsw2tk\Documents\Visual Studio 2012\Projects\codejam\codejam\in.txt"));
            Solver solve = new Solver();
            int caseCount = io.NextInt;
            for (int i = 0; i < caseCount; i++)
            {
                string res = solve.Solve(io);
                io.WriteLine("Case #{0}: {1}", i + 1, res);
                Console.WriteLine("Case #{0}: {1}", i + 1, res);
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
            public double NextDouble
            {
                get { return double.Parse(NextString); }
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
