using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Ticket_Swapping
{
    class Program
    {
        private static void Main(string[] args)
        {
            //string filename = @"sample.in.txt";
            //string filename = @"A-small-attempt0.in.txt";
            string filename = @"A-large.in.txt";

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (StreamReader reader = new StreamReader(filename))
            {
                using (StreamWriter writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] s = reader.ReadLine().Split(' ');
            int n = int.Parse(s[0]);
            int m = int.Parse(s[1]);

            int[] p = new int[m];
            int[] p2 = new int[m];
            int[] c = new int[m];

List<pair> list1 = new List<pair>();
List<pair> list2 = new List<pair>();

            for (int i = 0; i < m; i++)
            {
                s = reader.ReadLine().Split(' ');
                p[i] = int.Parse(s[0]);
                p2[i] = int.Parse(s[1]);
                c[i] = int.Parse(s[2]);

                list1.Add(new pair(p[i], p2[i], c[i]));
                list2.Add(new pair(p[i], p2[i], c[i]));
            }

            

            long total = 0;
            for (int i = 0; i < m; i++)
            {
                int nn = p2[i] - p[i];
                total += ((long)c[i] * (((long)nn * (2 * n - (nn - 1)) / 2) % 1000002013)) % 1000002013;

                    total = total % 1000002013;

            }

            total += 1000002013;

            list1.Sort(new psort());
            list2.Sort(new p2sort());

            long z = 0;
            for (int i = 0; i < list2.Count; i++)
            {
                int todel = list2[i].c;

                for (int j = list1.Count - 1; j >= 0; j--)
                {
                    if (list1[j].p <= list2[i].p2)
                    {
                        int nn = list2[i].p2 - list1[j].p;
                        if (list1[j].c < todel)
                        {
                            z += ((long)list1[j].c * (((long)nn * (2 * n - (nn - 1)) / 2) % 1000002013)) % 1000002013;
                            z = z % 1000002013;
                            todel -= list1[j].c;
                            list1[j].c = 0;
                        }
                        else
                        {
                            z += ((long)todel * (((long)nn * (2 * n - (nn - 1)) / 2) % 1000002013)) % 1000002013;
                            z = z % 1000002013;
                            list1[j].c -= todel;
                            break;
                        }
                    }
                }
            }


            Console.WriteLine("Case #{0}: {1}", C, (total - z) % 1000002013);
            writer.WriteLine("Case #{0}: {1}", C, (total - z) % 1000002013);

        }

        class psort : IComparer<pair>
        {

            #region IComparer<pair> Members

            public int Compare(pair x, pair y)
            {
                return x.p.CompareTo(y.p);
            }

            #endregion
        }

        class p2sort : IComparer<pair>
        {

            #region IComparer<pair> Members

            public int Compare(pair x, pair y)
            {
                return x.p2.CompareTo(y.p2);
            }

            #endregion
        }

        class pair 
        {
            public int p;
            public int p2;
            public int c;

            public pair(int p,
            int p2,
            int c)
            {
                this.p = p;
                this.p2 = p2;
                this.c = c;
            }
        }

    }
}
