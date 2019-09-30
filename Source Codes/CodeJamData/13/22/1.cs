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
            double[,] p = new double[3000, 3000];
            public string Solve(MyIO io)
            {
                p[0, 0] = 1;
                for (int j = 1; j < 3000; j++)
                {
                    p[j, 0] = p[j, j] = p[j-1, 0] / 2;
                    for (int k = 1; k < j; k++)
                    {
                        p[j, k] = (p[j - 1, k-1] + p[j -1, k]) / 2;
                    }
                }
                string res="";
                int N = io.NextInt, X = io.NextInt, Y = io.NextInt;
                int T =0;
                X = Math.Abs(X);
                
                for (int i = 0; i < 100000; i++)
                {
                    T = i;
                    if (N >= 4 * i + 1)
                    {
                        N -= 4 * i + 1;
                    }
                    else break;
                }
                if (X + Y < 2 * T) return "1\n";
                if (X + Y > 2 * T) return "0\n";
                if (Y == 2 * T) return "0\n";
                if (Y + 1 > N) return "0\n";
                if (N >= Y + 1 + 2 * T) return "1\n";
                double R = 0;
                for (int j = Y + 1; j <= N; j++)
                {
                    R += p[N,j];
                }
                return R.ToString() + '\n';
                    // C[N][Y+1]+...+C[N][N] / 2^n;
                    // N at least Y + 1;

                    //T Y;
                    return res.ToString() + '\n';
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
