using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using KEY = System.Tuple<int, int>;

// The solution might use the C5 C# library, available at http://www.itu.dk/research/c5/

namespace GCJ
{
    class Program
    {

        public static int Recurse(List<int>[] compat, List<List<int>> cycles, List<int> choices, int j)
        {
            int result = 0;
            choices.Add(j);
            bool foundRes = false;
            foreach(var i in compat[j])
            {
                if(!choices.Contains(i) && choices.All(x => compat[x].Contains(i)))
                {
                    foundRes = true;
                    result = Math.Max(result, Recurse(compat, cycles, choices, i));
                }
            }

            if(!foundRes)
            {
                result = choices.Sum(x => cycles[x].Count);
            }

            choices.Remove(choices.Count - 1);
            return result;
        }


        public static int Recurse(int N, int[] bffs, bool[] vis, List<int> cur)
        {
            int res = 0;
            int bff = cur.Count > 0 ? bffs[cur.Last()] : -1;
            if (cur.Count == 0 || (cur.Count > 1 && bff == cur[cur.Count - 2]))
            {
                res = cur.Count;
                for(int i = 1; i <= N; ++i)
                {
                    if(!vis[i])
                    {
                        cur.Add(i);
                        vis[i] = true;
                        res = Math.Max(res, Recurse(N, bffs, vis, cur));
                        cur.RemoveAt(cur.Count - 1);
                        vis[i] = false;
                    }
                }
            }
            else if (vis[bff])
            {
                if (cur[0] == bff || bff == cur[cur.Count - 2])
                {
                    res = cur.Count;
                }
            }
            else
            {
                cur.Add(bff);
                vis[bff] = true;
                res = Math.Max(res, Recurse(N, bffs, vis, cur));
                cur.RemoveAt(cur.Count - 1);
                vis[bff] = false;
            }

            return res;
        }

        static void Main(string[] args)
        {



            var root = @"C:\projects\comp\gcj\p3\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            long[] data = input.SelectMany(x => x.Split(' ').Select(y => Int64.Parse(y))).ToArray();
            IEnumerator<long> scanner = data.AsEnumerable<long>().GetEnumerator();
            scanner.MoveNext();
            long numCases = scanner.Current;

            for (long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                int N = (int)scanner.Current;

                int[] bffs = new int[N + 1];

                List<int>[] rev = new List<int>[N + 1];
                for(int i = 0; i <= N; ++i)
                {
                    rev[i] = new List<int>();
                }

                for(int i = 1; i <= N; ++i)
                {
                    scanner.MoveNext();
                    bffs[i] = (int)scanner.Current;
                    rev[(int)scanner.Current].Add(i);
                }

                int bestSoFar = 0;

                bool[] vis = new bool[N + 1];

                /*
                for (int i = 1; i <= N; ++i)
                {
                    for(int j = 0; j < N + 1; ++j)
                    {
                        vis[j] = false;
                    }


                    int first = i;
                    int cc = 0;
                    int index = i;
                    int prev = -1;
                    List<List<int>> cycles = new List<List<int>>();
                    while (true)
                    {
                        vis[index] = true;
                        cc++;
                        if (bffs[index] == i || prev == bffs[index])
                        {
                            bestSoFar = Math.Max(cc, bestSoFar);
                        }
                        if (vis[bffs[index]])
                        {
                            if (prev == bffs[index] && rev[index].Any(x => !vis[x]))
                            {
                                bestSoFar = Math.Max(cc + 1, bestSoFar);
                                List<int> cycle = new List<int>();
                                for(int j = 1; j <= N; ++j)
                                {
                                    if(vis[j])
                                    {
                                        cycle.Add(j);
                                    }
                                }
                                cycles.Add(cycle);
                            }
                            break;
                        }
                        prev = index;
                        index = bffs[index];
                        
                    }

                    List<int>[] compat = new List<int>[cycles.Count];

                    for(int j = 0; j < cycles.Count; ++j)
                    {
                        compat[j] = new List<int>();
                        for(int k = 0; k < cycles.Count; ++k)
                        {
                            if(cycles[j].Union(cycles[k]).Distinct().Count() == cycles[j].Count + cycles[k].Count)
                            {
                                compat[j].Add(k);
                            }
                        }
                    }

                    List<int> choices = new List<int>();
                    for(int j = 0; j < cycles.Count; ++j)
                    {
                        choices.Add(j);
                        //bestSoFar = Math.Max(bestSoFar, Recurse(compat, cycles, choices, j));
                    }

                    
                }*/

                bestSoFar = Recurse(N, bffs, vis, new List<int>());





                output.WriteLine("Case #{0}: {1}", nc + 1, bestSoFar);
                Console.WriteLine("Case #{0}: {1}", nc + 1, bestSoFar);
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
    }
}
