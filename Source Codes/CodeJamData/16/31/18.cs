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
                long N = scanner.Current;

                int[] sums = new int[N];
                for(int i = 0; i < N; ++i)
                {
                    scanner.MoveNext();
                    sums[i] = (int)scanner.Current;
                }
                List<string> plan = new List<string>();
                while(true)
                {
                    
                    int totSum = sums.Sum();
                    if(totSum == 2)
                    {
                        string res = "";
                        for (int i = 0; i < N; ++i)
                        {
                            if (sums[i] > 0)
                            {
                                res = res + (char)('A' + i);
                            }
                        }
                        plan.Add(res);
                        break;
                    }
                    else
                    {
                        int maxIndex = -1;
                        int maxV = -1;
                        int maxIndex2 = -1;
                        for(int i = 0; i < N; ++i)
                        {
                            if(sums[i] > maxV)
                            {
                                maxV = sums[i];
                                maxIndex = i;
                                maxIndex2 = -1;
                            }
                            else if(sums[i] == maxV)
                            {
                                maxIndex2 = i;
                            }
                        }
                        sums[maxIndex]--;
                        if (maxIndex2 == -1 || totSum == 3)
                        {
                            plan.Add("" + (char)('A' + maxIndex));
                        }
                        else
                        {
                            sums[maxIndex2]--;
                            plan.Add("" + (char)('A' + maxIndex) + (char)('A' + maxIndex2));
                        }

                        if(totSum == 1)
                        {
                            break;
                        }
                    }
                }

                output.WriteLine("Case #{0}: {1}", nc + 1, String.Join(" ", plan));
                Console.WriteLine("Case #{0}: {1}", nc + 1, String.Join(" ", plan));
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
