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
            public string Solve(MyIO io)
            {
                int n = io.NextInt;
                int  X = io.NextInt;

                List<int> l = new List<int>();
                for (int i = 0; i < n; i++)
                {
                    l.Add(io.NextInt);
                }
                l.Sort();
                int l1 = 0, l2 = l.Count - 1;

                int R = 0;
                while (l1 <= l2)
                {
                    if (l1 == l2)
                    {
                        R++;
                        l2--;
                    }
                    else
                    {
                        if (l[l1] + l[l2] <= X)
                        {
                            l1++; l2--;
                            R++;

                        }
                        else
                        {
                            l2--;
                            R++;
                        }
                    }
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
