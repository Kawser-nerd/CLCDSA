using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace a
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamWriter w = new StreamWriter(@"output-large.txt"))
            {
                using (StreamReader r = new StreamReader(@"A-large.in"))
                {
                    int t = int.Parse(r.ReadLine());
                    for (int i = 0; i < t; i++)
                    {
                        List<string> ls = new List<string>();
                        int n = int.Parse(r.ReadLine());
                        int[] p = r.ReadLine().Split().Select(int.Parse).ToArray();
                        int first = -1;
                        int second = -1;
                        for (int j = 0; j < p.Length; j++)
                        {
                            if (first == -1 || p[j] >= p[first])
                            {
                                second = first;
                                first = j;
                            }
                            else if (second == -1 || p[j] >= p[second])
                            {
                                second = j;
                            }
                        }
                        while(p[first]>p[second])
                        {
                            ls.Add(((char)('A' + first)).ToString());
                            p[first]--;
                        }

                        for (int j = 0; j < p.Length; j++)
                        {
                            if (j == first || j == second) continue;
                            for (int k = 0; k < p[j]; k++)
                            {
                                ls.Add(((char)('A' + j)).ToString());
                            }
                        }
                        for (int j = 0; j < p[first]; j++)
                        {
                            ls.Add(((char)('A' + first)).ToString()
                                + ((char)('A' + second)).ToString());
                        }

                        string ans = String.Join(" ", ls);

                        w.WriteLine("Case #{0}: {1}", i + 1, ans);
                    }
                }
            }
        }
    }
}
