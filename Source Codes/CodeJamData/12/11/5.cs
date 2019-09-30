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
            public string Solve(MyIO io)
            {
                int N = io.NextInt, M = io.NextInt;
                double[] p = new double[N + 1];
                p[0] = 1;
                for (int i = 1; i < N + 1; i++) p[i] = io.NextDouble;
                for (int i = 1; i < N + 1; i++) p[i] *= p[i - 1];
                double best = double.MaxValue;
                best = Math.Min(best, M + 2);
                for (int i = 0; i <= N; i++)
                {
                    double pp = p[i];
                    best = Math.Min(best, (N - i) + (M - i) + 1 + (1 - p[i]) * (M + 1));
                }
                return best.ToString() + '\n';
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
                Console.Write(format, args);
                return true;
            }
            public void WriteLine(string format, params object[] args)
            {
                writer.WriteLine(format, args);
                Console.WriteLine(format, args);

            }
            public void WriteLine(object obj)
            {
                writer.WriteLine("{0}", obj);
                Console.WriteLine("{0}", obj);

            }
            public void WriteLine()
            {
                writer.WriteLine(); Console.WriteLine();
            }
            public void Write(object obj)
            {
                writer.Write("{0}", obj); Console.Write("{0}", obj);
            }
            public void Flush()
            {
                writer.Flush();
            }
        }
    }
}
