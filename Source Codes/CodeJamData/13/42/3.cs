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
            bool canWin(int N, long pos, long cnt)
            {
                if (N == 1)
                {
                    if (pos < cnt) return true;
                    else return false;
                }
                if (pos == (1L << N) - 1)
                {
                    return cnt >= 1L << N;
                }
                return canWin(N - 1, pos - (pos) / 2, cnt);
            }
            bool sureWin(int N, long pos, long cnt)
            {
                if (N == 1)
                {
                    if (pos < cnt) return true;
                    else return false;
                }
                if (pos == 0)
                {
                    return cnt >= 1L;
                }
                return sureWin(N - 1, (pos - 1) / 2, cnt - (1L << (N - 1)));
            }
            long R1(int N, long P)
            {
                long l = 0, r = 1L << N;
                while (r - l != 1)
                {
                    long c = (l + r) / 2;
                    if (canWin(N, c, P))
                    {
                        l = c;
                    }
                    else
                    {
                        r = c;
                    }
                }
                return l;
            }
            long R2(int N, long P)
            {
                long l = 0, r = 1L << N;
                while (r - l != 1)
                {
                    long c = (l + r) / 2;
                    if (sureWin(N, c, P))
                    {
                        l = c;
                    }
                    else
                    {
                        r = c;
                    }
                }
                return l;
            }

            public string Solve(MyIO io)
            {
                long res = 0;
                int N = io.NextInt;
                long P = io.NextLong;
                long res1 = R1(N, P);
                long res2 = R2(N, P);
                return res2.ToString() + " " + res1.ToString() + '\n';
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
