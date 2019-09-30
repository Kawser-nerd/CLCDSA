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
            public string Solve(MyIO io)
            {
                int N = io.NextInt, M = io.NextInt;
                List<long> e = new List<long>() , o = new List<long>(), p=new List<long>();
                long p1 = 0, p2 = 0;
                List<long> l = new List<long>();
                for (int i = 0; i < M; i++)
                {
                    
                    e.Add(io.NextInt);
                    o.Add(io.NextInt);
                    p.Add(io.NextInt);
                    l.Add(e[i]); l.Add(o[i]);
                    long pr = N * (o[i] - e[i]) - (o[i] - e[i]) * (o[i] - e[i] - 1) / 2;
                    pr %= mod;
                    pr *= p[i];
                    pr %= mod;
                    p1 += pr;
                    p1 %= mod;
                }
                Dictionary<long, long> dic = new Dictionary<long, long>();
                l.Sort();
                for (int i = 0; i < l.Count; i++)
                {
                    if(!dic.ContainsKey(l[i]))dic.Add(l[i], i);
                }
                long[] cnt = new long[2 * M - 1];
                for (int i = 0; i < M; i++)
                {
                    for (int j = (int)dic[(long)e[i]]; j < dic[(long)o[i]]; j++)
                    {
                        cnt[j] += p[i];
                        //cnt[j] %= mod;
                    }
                }
                while (true)
                {
                lab:;
                    long start = -1, end = 0;
                    long min = long .MaxValue;
                    for (int i = 0; i < cnt.Length; i++)
                    {
                        if (cnt[i] > 0)
                        {
                            start = i;
                            for (end = i; end < cnt.Length && cnt[end] > 0; end++) 
                            {
                                min = Math.Min(min,cnt[end]);
                            }
                            break;
                        }
                    }
                    if (start == -1) break;
                    end--;
                    for (long i = start; i <= end; i++)
                    {
                        cnt[i] -= min;
                    }
                    long dis = l[(int)end + 1] - l[(int)start];
                    long pr = dis * N - (dis - 1) * dis / 2;
                    min %= mod;
                    pr *= min;
                    pr %= mod;
                    p2 += pr;
                    p2 %= mod;
                }
                long res = (p1 + mod - p2) % mod;

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
