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
            List<int> solve(List<int> id,int[,] p)
            {
                if (id.Count == 0) return new List<int>();

                bool[] check = new bool[id.Count];
                int[] res = new int[id.Count];
                int used = -1;
                for (int i = 0; i < id.Count; i++)
                {
                    if (check[i]) continue;
                    int cnt = 0;
                    List<int> nid = new List<int>();
                    List<int> pos = new List<int>();
                    for (int j = i + 1; j < id.Count; j++)
                    {
                        if (check[j]) continue;
                        if (p[id[j], id[i]] == 1)
                        {
                            nid.Add(id[j]);
                            pos.Add(j);
                            cnt++;
                            check[j] = true;
                        }
                    }
                    int x = used + 1;
                    used += cnt + 1;
                    res[i] = used;
                    List<int> R = solve(nid, p);
                    for (int j = 0; j < R.Count; j++)
                    {
                        res[pos[j]] = R[j] + x;
                    }
                    

                }


                return res.ToList();
            }

            public string Solve(MyIO io)
            {
                int N = io.NextInt;
                List<int> a = new List<int>(), b = new List<int>();
                List<int> edge1 = new List<int>(),edge2=new List<int>();
                for (int i = 0; i < N; i++)
                {
                    a.Add(io.NextInt);
                    
                }
                for (int i = 0; i < N; i++)
                {
                    b.Add(io.NextInt);
                }
                for (int i = 0; i < N; i++)
                {
                    for (int j = i + 1; j < N; j++)
                    {
                        if (a[i] >= a[j])
                        {
                            edge1.Add(j);
                            edge2.Add(i);
                        }
                        if (b[i] <= b[j])
                        {
                            edge1.Add(i);
                            edge2.Add(j);
                        }
                    }
                }

                for (int i = 0; i < N; i++)
                {
                    for (int j = i + 1; j < N; j++)
                    {
                        if (b[i] == b[j] + 1)
                        {
                            edge1.Add(j);
                            edge2.Add(i);
                            break;
                        }
                    }
                }
                for (int j = 0; j < N; j++)
                {
                    for (int i = j - 1; i >= 0; i--)
                    {
                        if (a[i] + 1 == a[j])
                        {
                            edge1.Add(i);
                            edge2.Add(j);
                            break;
                        }
                    }
                }

            
                int[,] p = new int[N, N];
                //for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) p[i, j] = (int)1e9;
                        for (int i = 0; i < edge1.Count; i++)
                        {
                            p[edge1[i], edge2[i]] = 1;
                        }
                for (int k = 0; k < N; k++)
                    for (int i = 0; i < N; i++)
                        for (int j = 0; j < N; j++)
                        {
                            p[i, j] = Math.Max(p[i, j], p[i, k] * p[k, j]);
                        }
                bool[] used = new bool[N], check = new bool[N];
                int x = -1;
                
                List<int> ll =new List<int>();
                for(int i=0;i<N;i++)
                {
                    ll.Add(i);
                }
                List<int> res = solve(ll, p);
                for (int i = 0; i < res.Count; i++) res[i]++;

                int[] aa = new int[N], bb = new int[N];
                for (int i = 0; i < res.Count; i++)
                {
                    int R = 1;
                    for (int j = 0; j < i; j++)
                    {
                        if (res[i] > res[j])
                        {
                            R = Math.Max(R, aa[j] + 1);
                        }
                    }
                    aa[i] = R;
                } 
                for (int i = res.Count-1; i >=0; i--)
                {
                    int R = 1;
                    for (int j = i+1; j < res.Count; j++)
                    {
                        if (res[i] > res[j])
                        {
                            R = Math.Max(R, bb[j] + 1);
                        }
                    }
                    bb[i] = R;
                }
                for (int i = 0; i < N; i++)
                {
                    if (aa[i] != a[i])
                    {

                    }
                    if (bb[i] != b[i])
                    {

                    }
                }

                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < res.Count; i++)
                {
                    sb.Append(res[i]);
                    if (i == res.Count - 1) sb.Append('\n');
                    else sb.Append(' ');
                }
                return sb.ToString();
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
