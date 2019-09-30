using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Good_Luck
{
    class Program
    {
        private static void Main(string[] args)
        {
            //string filename = @"sample.in.txt";
            string filename = @"C-small-1-attempt0.in.txt";
            //string filename = @"B-large.in.txt";

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
            int R = int.Parse(s[0]);
            int N = int.Parse(s[1]);
            int M = int.Parse(s[2]);
            int K = int.Parse(s[3]);

            Console.WriteLine("Case #{0}:", C);
            writer.WriteLine("Case #{0}:", C);

            


            for (; R > 0; R--)
            {
                s = reader.ReadLine().Split(' ');
                int[] kk = new int[K];

                for (int i = 0; i < K; i++)
                {
                    kk[i] = int.Parse(s[i]);
                }
                
                for (int n1 = 2; n1 <= M; n1++)
                        for (int n2 = 2; n2 <= M; n2++)
                            for (int n3 = 2; n3 <= M; n3++)
                            {
                                List<int> list = new List<int>();
                                list.Add(1);
                                list.Add(n1);
                                list.Add(n2);
                                list.Add(n3);
                                list.Add(n1*n2);
                                list.Add(n1 * n3);
                                list.Add(n3 * n2);
                                list.Add(n1 * n2*n3);

                                bool f = true;
                                for (int i = 0; i < K; i++)
                                {
                                    if (!list.Contains(kk[i]))
                                    {
                                        f = false;
                                        break;
                                    }
                                }

                                if (f)
                                {
                                    Console.WriteLine("{0}{1}{2}", n1,n2,n3);
                                    writer.WriteLine("{0}{1}{2}", n1, n2, n3);
                                    goto endloop;
                                }
                            }
                    Console.WriteLine("222");
                    writer.WriteLine("222");
                endloop:
                    ;
            }
        }
    }
}
