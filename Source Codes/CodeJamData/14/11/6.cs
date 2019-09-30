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
            public string Solve(MyIO io)
            {
                int N = io.NextInt, L = io.NextInt;
                List<long> l = new List<long>(), l2 = new List<long>();
                for (int i = 0; i < N; i++)
                {
                    l.Add(convert( io.NextString));
                }
                for (int i = 0; i < N; i++)
                {
                    l2.Add(convert(io.NextString));
                }
                bool ok = false;
                l.Sort();
                int R = 9999;
                for (int i = 0; i < N; i++)
                {
                    List<long> ll2 = new List<long>();
                    for (int j = 0; j < N; j++)
                    {
                        ll2.Add(l2[j] ^ (l[0] ^ l2[i]));
                    }
                    ll2.Sort();
                    bool o1 = true;
                    for (int j = 0; j < N; j++)
                    {
                        if (ll2[j] != l[j]) o1 = false;
                    }
                    if (o1)
                    {
                        int r = 0;
                        long Z = l[0] ^ l2[i];
                        for (int j = 0; j < 64; j++)
                        {
                            if ((Z & (1L << j)) != 0)
                            {
                                r++;
                            }
                        }
                        R = Math.Min(R, r);
                    }
                }
                if (R == 9999) return "NOT POSSIBLE";
                return R.ToString();
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
