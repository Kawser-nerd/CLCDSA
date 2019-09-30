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

        class Solver
        {

            public string Solve(MyIO io)
            {
                int A = io.NextInt;
                int n = io.NextInt;
                List<int> l = new List<int>();
                for (int i = 0; i < n; i++) l.Add(io.NextInt);
                if (A == 1) return n.ToString()+'\n';
                l.Sort();
                int res = n;
                int t = 0;
                for (int i = 0; i < n; i++)
                {
                    while (A <= l[i])
                    {
                        A += A - 1;
                        t++;
                    }
                    A += l[i];
                    res = Math.Min(res, t + n - 1 - i);
                }

                return res.ToString()+'\n';
            }
        }
        static void Main(string[] args)
        {
            MyIO io = new MyIO(new StreamReader("in.txt"));
            int caseCount = io.NextInt;
            Solver solve = new Solver();
            for (int i = 0; i < caseCount; i++)
            {
                string res = solve.Solve(io);
                io.Write("Case #{0}: {1}", i + 1, res);
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
