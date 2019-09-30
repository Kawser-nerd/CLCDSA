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
            int cmp(KeyValuePair<long, long> a, KeyValuePair<long, long> b)
            {
                return a.Key.CompareTo(b.Key);
            }

            long convert(string s)
            {
                long R = 0;
                for(int i=0;i<s.Length;i++)
                {
                    R = R * 2 + s[i] - '0';
                }
                return R;
            }
            int S(List<int>[] tree,int node,int fnode = -1)
            {
                List<int> snode = new List<int>();
                for (int i = 0; i < tree[node].Count; i++)
                {
                    if (tree[node][i] != fnode)
                    {
                        snode.Add(tree[node][i]);
                    }
                }
                if (snode.Count <= 1)
                {
                    return 1;
                }
                List<int > R= new List<int>();
                for (int i = 0; i < snode.Count; i++)
                {
                    R.Add(S(tree, snode[i], node));
                }
                R.Sort();
                return 1 + R[R.Count - 1] + R[R.Count - 2];
            }
            public string Solve(MyIO io)
            {
                int N = io.NextInt;
                List<int>[] l = new  List<int>[N];
                for(int i=0;i<N;i++)
                {
                    l[i] = new List<int>();
                }
                for (int i = 0; i < N - 1; i++)
                {
                    int x = io.NextInt - 1;
                    int y = io.NextInt - 1;
                    l[x].Add(y); l[y].Add(x);
                }
                int R = 0;
                for (int i = 0; i < N; i++)
                {
                    R = Math.Max(R, S(l, i));
                }
                return (N - R).ToString();
                    return "NOT POSSIBLE";
               
            }
        }
        static void Main(string[] args)
        {
            MyIO io = new MyIO(new StreamReader(@"C:\Users\zaq1xsw2tk\Documents\Visual Studio 2012\Projects\codejam\codejam\in.txt"));
            int caseCount = io.NextInt;
            Solver solve = new Solver();
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
