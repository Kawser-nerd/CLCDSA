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
            struct Pair
            {
                public int x, y;
                public Pair(int x, int y)
                {
                    this.x = x; this.y = y;
                }
            }
            int GCD(int x, int y)
            {
                if (y == 0) return x;
                if (x < y) return GCD(y, x);
                return GCD(y, x % y);
            }
            Pair GetGCDPair(int x,int y)
            {
                int gcd = GCD(Math.Abs(x), Math.Abs(y));
                return new Pair(x / gcd, y / gcd);
            }
            public string Solve(MyIO io)
            {
                int H = io.NextInt, W = io.NextInt, D = io.NextInt;
                StringBuilder[] map = new StringBuilder[H];
                for (int i = 0; i < H; i++) map[i] = new StringBuilder(io.NextString);
                int x = 0, y =0 ;
                for (int i = 0; i < H; i++) for (int j = 0; j < W; j++)
                    {
                        if (map[i][j] == 'X') { x = i; y = j; map[i][j] = '.'; }
                    }
                HashSet<Pair> hash = new HashSet<Pair>();
                for (int i = -55; i <= 55; i++) for (int j = -55; j <= 55; j++)
                    {
                        if (i == 0 && j == 0) continue;
                        if (i * i + j * j <= D * D)
                        {
                            hash.Add(GetGCDPair(i, j));
                        }
                    }
                x -= 1; y -= 1; H -= 2; W -= 2;
                int res = 0;
                for (int i = -55; i <= 55; i++) for (int j = -55; j <= 55; j++)
                    {
                        if (i == 0 && j == 0) continue;
                        if (i * i + j * j <= D * D)
                        {
                            Pair p = GetGCDPair(i, j);
                            if (hash.Contains(p))
                            {
                                if ((i % (2 * H) == 0 || (2 * x + 1 + i) % (2 * H) == 0)
                                    && (j % (2 * W) == 0 || (2 * y + 1 + j) % (2 * W) == 0))
                                {
                                    hash.Remove(p);
                                    res++;
                                }
                            }
                            
                        }
                    }

                return res.ToString() + '\n';
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
                Console.Error.Write("Case #{0}: {1}", i + 1, res);
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
