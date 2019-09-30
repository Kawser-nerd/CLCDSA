using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj15r1c
{
    class Program
    {
        static void Main(string[] args)
        {
            {
                string root = @"C:\Users\Josiah\Downloads\";
                string problem = "C";
                string ptype = "small-attempt0";
                //string ptype = "Large";

                string[] lines = System.IO.File.ReadAllLines(string.Format("{0}{1}-{2}.in", root, problem, ptype));
                TextWriter tw = new StreamWriter(string.Format("{0}{1}-{2}.out", root, problem, ptype));

                int idx = 0;
                int t = int.Parse(lines[idx++]);
                for (int a = 0; a < t; a++)
                {
                    string[] line = lines[idx++].Split(' ');
                    int C = int.Parse(line[0]);
                    int D = int.Parse(line[1]);
                    int V = int.Parse(line[2]) + 1;
                    List<int> denoms = new List<int>();
                    string[] line2 = lines[idx++].Split(' ');
                    for (int b = 0; b < D; b++)
                    {
                        denoms.Add(int.Parse(line2[b]));
                    }
                    bool[] vals = generate(denoms, V);
                    bool done = false;
                    int ans = 0;
                    while (!done)
                    {
                        done = true;
                        for (int b = 1; b < V; b++)
                        {
                            if (vals[b] == false)
                            {
                                done = false;
                                denoms.Add(b);
                                ans++;
                                vals = generate(denoms, V);
                                break;

                            }
                        }
                    }
                    tw.WriteLine("Case #{0}: {1}", a + 1, ans);
                }

                tw.Close();
            }
        }

        private static bool[] generate(List<int> denoms, int V)
        {
            bool[] res = new bool[V];
            for (int i = 0; i < Math.Pow(2, denoms.Count); i++)
            {
                int total = 0;
                for (int j = 0; j < denoms.Count; j++)
                {
                    if ((i >> j) % 2 == 1)
                    {
                        total += denoms[j];
                    }
                }
                if (total > 0 && total < V)
                {
                    res[total] = true;
                }
            }
            return res;
        }  
    }
}
