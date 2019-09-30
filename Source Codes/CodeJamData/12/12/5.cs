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
            class Pair : IComparable
            {
                public int X, Y;
                public Pair(int X,int Y)
                {
                    this.X = X;
                    this.Y = Y;
                }
                public int CompareTo(object p)
                {
                    return X - ((Pair)p).X;
                }
            }
        
            public string Solve(MyIO io)
            {
                int N = io.NextInt;
                int[] solved = new int[N], e1 = new int[N], e2 = new int[N];
                HashSet<int> solve1 = new HashSet<int>();
                HashSet<int> solve2 = new HashSet<int>();
                for (int i = 0; i < N; i++)
                {
                    solved[i] = 0;
                    e1[i] = io.NextInt; e2[i] = io.NextInt;
                }
                int star = 0;
                int res  = 0;
                for (int cc = 0; cc<10000 ; cc++ )
                {
                    if (star == 2 * N) break;
                    for (int i = 0; i < N; i++)
                    {
                        if (e1[i] <= star && solved[i]<1) solve1.Add(i);
                        if (e2[i] <= star&& solved[i]<2) solve2.Add(i);
                    }
                    if (solve2.Count != 0)
                    {
                        var v=solve2.GetEnumerator();
                        v.MoveNext();
                        int x = v.Current;
                        star += 2 - solved[x];
                        solved[x] = 2;
                        solve2.Remove(x);
                        res++;
                        continue;
                    }
                    if (solve1.Count != 0)
                    {
                        int min = -1,id=-1;
                        foreach (var x in solve1)
                        {
                            if (solved[x] >= 1) continue;
                            if (e2[x] > min)
                            {
                                min = e2[x]; id = x;
                            }
                        }
                        if (id != -1)
                        {
                            solved[id] = 1;
                            star++;
                            res++;
                            continue;
                        }
                        else
                        {
                            return "Too Bad\n";
                        }
                    }
                    return "Too Bad\n";
                }
                return res.ToString()
                    + '\n';
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
