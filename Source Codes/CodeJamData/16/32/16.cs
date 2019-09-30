using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TUP = System.Tuple<long, long>;


namespace GCJ.P1
{
    class Program
    {



        static void Main(string[] args)
        {
            var root = @"C:\projects\comp\gcj\p1\";


            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            long[] data = input.SelectMany(x => x.Split(' ').Select(y => Int64.Parse(y))).ToArray();
            IEnumerator<long> scanner = data.AsEnumerable<long>().GetEnumerator();
            scanner.MoveNext();
            long numCases = scanner.Current;

            
            for (long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                long B = scanner.Current;
                scanner.MoveNext();
                long M = scanner.Current;

                bool[,] m = new bool[B, B];

                bool pos = (1L << (int)(B - 2)) >= M;
                if(pos)
                {

                    for(long i = 0; i < B; ++i)
                    {
                        if((1L << (int)i) < M)
                        {
                            long si = B - i - 2;
                            for(long j = si + 1; j < B; ++ j)
                            {
                                m[si, j] = true;
                            }
                        }
                        else if ((1L << (int)(i + 1)) > M)
                        {
                            if ((1L << (int)i) == M)
                            {
                                m[0, B - 1] = true;
                                M--;
                            }

                            for (long j = 0; j < B; ++j)
                            {
                                long val = (1L << (int)j);
                                if((val & M) > 0)
                                {
                                    long si = B - j - 2;
                                    m[0, si] = true;
                                }
                            }
                        }
                    }
                }

                if (pos)
                {
                    output.WriteLine("Case #{0}: {1}", nc + 1, "POSSIBLE");
                    Console.WriteLine("Case #{0}: {1}", nc + 1, "POSSIBLE");
                    for(int i = 0; i < B; ++i)
                    {
                        for(int j = 0; j < B; ++j)
                        {
                            output.Write(m[i,j] ? "1" : "0");
                            Console.Write(m[i, j] ? "1" : "0");
                            if(i == B - 1 && m[i,j])
                            {
                                throw new Exception("Assert");
                            }
                        }
                        output.Write("\n");
                        Console.Write("\n");
                    }
                }
                else
                {
                    output.WriteLine("Case #{0}: {1}", nc + 1, "IMPOSSIBLE");
                    Console.WriteLine("Case #{0}: {1}", nc + 1, "IMPOSSIBLE");
                }
            }

            output.Close();

            string readOut = File.ReadAllText(root + "out.txt");
            string pOut = File.ReadAllText(root + "outP.txt");

            if (readOut.Equals(pOut))
            {
                Console.WriteLine("Match found");
            }
            else
            {
                Console.WriteLine("Match not found");
                Console.WriteLine("v1 is: {0}\nv2 is: {1}", readOut, pOut);
            }
        }

        private static bool dfs(List<List<long>> g, bool[] vis, long i)
        {
            foreach(var v in g[(int)i])
            {
                if(vis[v])
                {
                    return true;
                }
                vis[v] = true;
                if (dfs(g, vis, v))
                {
                    return true;
                }
            }
            return false;
        }
    }
}
