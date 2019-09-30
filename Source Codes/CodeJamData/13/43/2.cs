using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Erdős_Szekeres
{
    class Program
    {
        private static void Main(string[] args)
        {
            //string filename = @"sample.in.txt";
            string filename = @"C-small-attempt1.in.txt";
            //string filename = @"A-large.in.txt";

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
            int n = int.Parse(reader.ReadLine());

            int[] a = new int[n];
            string[] s = reader.ReadLine().Split(' ');

            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(s[i]);
            }

            int[] b = new int[n];
            s = reader.ReadLine().Split(' ');

            for (int i = 0; i < n; i++)
            {
                b[i] = int.Parse(s[i]);
            }

            List<point> points = new List<point>();

            for (int i = 0; i < n; i++)
            {
                if (a[i] == 1 && b[i] == 1)
                {
                    points.Add(new point(new int[] { i }));
                    break;
                }
            }

            point res = points[0];
            if (n == 1)
                goto end;

            for (int nn = 2; nn <= n; nn++)
            {
                List<point> points2 = new List<point>();

                foreach (point point in points)
                {
                    for (int ii = 0; ii < point.indexs.Length; ii++)
                    {

                        int aa = 1;
                        int bb = 1;
                        for (int j = 0; j < ii; j++)
                        {
                            if (aa < a[point.indexs[j]] + 1)
                                aa = a[point.indexs[j]] + 1;

                        }

                        for (int j = ii; j < point.indexs.Length; j++)
                        {
                            if (bb < b[point.indexs[j]] + 1)
                                bb = b[point.indexs[j]] + 1;

                        }

                        for (int i = ii == 0 ? 0 : point.indexs[ii - 1] + 1; i < point.indexs[ii]; i++)
                        {
                            if (a[i] == aa && b[i] == bb)
                            {
                                int[] cc = new int[point.indexs.Length + 1];
                                Array.Copy(point.or, cc, point.indexs.Length);
                                cc[point.indexs.Length] = i;
                                if (nn == n)
                                {
                                    res = new point(cc); ;
                                    goto end;
                                }
                                else
                                    points2.Add(new point(cc));
                            }
                        }
                    }
                    {
                        int aa = 1;
                        int bb = 1;
                        for (int j = 0; j < point.indexs.Length; j++)
                        {
                            if (aa < a[point.indexs[j]] + 1)
                                aa = a[point.indexs[j]] + 1;

                        }

                        for (int i = point.indexs[point.indexs.Length - 1] + 1; i < n; i++)
                        {
                            if (a[i] == aa && b[i] == bb)
                            {
                                int[] cc = new int[point.indexs.Length + 1];
                                Array.Copy(point.or, cc, point.indexs.Length);
                                cc[point.indexs.Length] = i;
                                if (nn == n)
                                {
                                    res = new point(cc); ;
                                    goto end;
                                }
                                else
                                    points2.Add(new point(cc));
                            }
                        }
                    }
                }

                points = points2;
            }

            end:

                
            Console.Write("Case #{0}: ", C);
            writer.Write("Case #{0}: ", C);

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < res.or.Length; j++)
                {
                    if (res.or[j] == i)
                    {
                        if (i != 0)
                        {
                            Console.Write(" ");
                            writer.Write(" ");
                        }
                        Console.Write("{0}", j+1);
                        writer.Write("{0}", j+1);
                    }
                }
            }

            Console.WriteLine();
            writer.WriteLine();
        }

        class point
        {
            public int[] indexs;
            public int[] or;
            public point(int[] indexs)
            {
                this.indexs = indexs;
                or = (int[])indexs.Clone();
                Array.Sort(this.indexs);
            }
        }
    }
}
