using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Recycle
{
    class C
    {
        static int[] powers = new int[] { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("c:\\codejam\\2012\\qual\\C-large.in");
            StreamWriter sw = new StreamWriter("c:\\codejam\\2012\\qual\\C-large.out");

            Stopwatch watch = new Stopwatch();
            watch.Start();

            int T = Int32.Parse(sr.ReadLine());
            foreach (int caseN in Enumerable.Range(1, T))
            {
                int[] tmp = sr.ReadLine().Split(' ').Select(int.Parse).ToArray();
                int A = tmp[0];
                int B = tmp[1];

                HashSet<Tuple<int, int>> distinct = new HashSet<Tuple<int, int>>();
                for (int n = A; n <= B; n++)
                {
                    int len = n.ToString().Length;
                    if (len == 1)
                        continue;

                    int v = n;
                    for (int rot = 1; rot < len; rot++)
                    {
                        int unit = v % 10;
                        v /= 10;
                        v += unit * powers[len - 1];

                        if (unit != 0 && n < v && v <= B)
                            distinct.Add(Tuple.Create(n,v));
                    }
                }

                sw.WriteLine(String.Format("Case #{0}: {1}", caseN, distinct.Count));

                Console.WriteLine(String.Format("Case #{0}: {1}ms", caseN, watch.ElapsedMilliseconds));

                sw.Flush();
            }

            sr.Close();
            sw.Close();

        }

        private static string prettyPrint(IEnumerable<Tuple<int,int>> vals)
        {
            return vals.Aggregate("",(str,val) => str + val.Item1 + ":" + val.Item2 + Environment.NewLine);
        }
    }
}
