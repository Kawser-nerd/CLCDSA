using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using KEY = System.Tuple<int, int>;

namespace GCJ
{
    class P
    {
        public int EC = 0;
        public int FC = 0;
    }

    class Program
    {
        static List<List<int>> t = new List<List<int>>();
        static List<P> p = new List<P>();
        static int SC = 0;

        static int solve (int ind)
        {
            if(ind == t.Count)
            {
                return SC;
            }
            foreach(var i in t[ind])
            {
                p[i].EC++;
                if(p[i].EC == 1 && p[i].FC > 0)
                {
                    SC++;
                }
            }
            var res1 = solve(ind + 1);
            foreach(var i in t[ind])
            {
                p[i].EC--;
                if(p[i].EC == 0 && p[i].FC > 0)
                {
                    SC--;
                }
            }


            foreach(var i in t[ind])
            {
                p[i].FC++;
                if(p[i].FC == 1 && p[i].EC > 0)
                {
                    SC++;
                }
            }
            var res2 = solve(ind + 1);
                        foreach(var i in t[ind])
            {
                p[i].FC--;
                if(p[i].FC == 0 && p[i].EC > 0)
                {
                    SC--;
                }
            }
            return Math.Min(res1, res2);
        }

        static void Main(string[] args)
        {
            var root = @"D:\gcj\p3\";

                
            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            long numCases = long.Parse(input[0]);
            long lineNum = 0;

            for(long nc = 0; nc < numCases; ++nc)
            {
                lineNum++;
                long N = long.Parse(input[lineNum]);
                int nt = 0;
                Dictionary<string ,int> map = new Dictionary<string,int>();
                List<string[]> tokens = new List<string[]>();
                t.Clear();
                for(int i = 0; i < N; ++i)
                {
                    lineNum++;
                    string[] s = input[lineNum].Trim().Split(' ');
                    tokens.Add(s);
                    t.Add(new List<int>());
                    foreach(var ss in s)
                    {
                        if(!map.ContainsKey(ss))
                        {
                            map.Add(ss, nt);
                            nt++;
                        }
                        t.Last().Add(map[ss]);
                    }
                }

                p.Clear();
                for(int i = 0; i < nt; ++i)
                {
                    p.Add(new P());
                }
                SC = 0;

                for(int i = 0; i < 2; ++i)
                {
                    for(int j = 0; j < t[i].Count; ++j)
                    {
                        if(i == 0)
                        {
                            p[t[i][j]].EC++;
                        }
                        else
                        {
                            p[t[i][j]].FC++;
                            if(p[t[i][j]].EC > 0)
                            {
                                SC++;
                            }
                        }
                    }
                }

                int res = solve(2);
                output.WriteLine("Case #{0}: {1}", nc + 1, res);
                Console.WriteLine("Case #{0}: {1}", nc + 1, res);
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
