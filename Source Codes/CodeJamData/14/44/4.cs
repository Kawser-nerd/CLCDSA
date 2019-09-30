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
            class Node
            {
                public
                Dictionary<char, Node> dic;
                public Node()
                {
                    dic = new Dictionary<char, Node>();
                }
            }
            int cal(List<string> l)
            {
                if (l.Count == 0) return 0;
                int R = 1;
                Node n = new Node();
                foreach (string s in l)
                {
                    Node nn=  n;
                    foreach (char c in s)
                    {
                        if (!nn.dic.ContainsKey(c))
                        {
                            nn.dic.Add(c, new Node());
                            R++;
                        }
                        nn = nn.dic[c];
                    }
                }
                return R;
            }
            public string Solve(MyIO io)
            {
                int R = 0;
                int N = io.NextInt, M = io.NextInt;
                List<string> l = new List<string>();
                for (int i = 0; i < N; i++)
                {
                    l.Add(io.NextString);
                }
                int k = 1;
                for (int i = 0; i < N; i++)
                {
                    k *= M;
                }

                int max = 0;
                R = 0;

                for (int i = 0; i < k; i++)
                {
                    List<string>[] ll = new List<string>[M];
                    for(int j=0;j<M;j++)
                    {
                        ll[j] = new List<string>();
                    }
                    int x = i;
                    for (int j = 0; j < N; j++)
                    {
                        int t = x % M;
                        x /= M;
                        ll[t].Add(l[j]);
                    }
                    int q = 0;
                    for (int j = 0; j < M; j++)
                    {
                        q += cal(ll[j]);
                    }
                    if (max < q)
                    {
                        max = q;
                        R=1;
                    }
                    else if (max == q)
                    {
                        R++;
                    }
                }


                return max.ToString() +" " +R.ToString();
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
