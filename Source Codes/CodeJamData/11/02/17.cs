using System;
using System.IO;
using System.Text;

namespace Magicka
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string filename = @"B-large.in.txt";

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
            int N = int.Parse(s[0]);
            
            char[] c1 = new char[N];
            char[] c2 = new char[N];
            char[] c3 = new char[N];

            int indexS = 1;
            for(int i=0; i<N; i++)
            {
                string pr = s[indexS];
                indexS++;
                c1[i] = pr[0];
                c2[i] = pr[1];
                c3[i] = pr[2];
            }

            int K = int.Parse(s[indexS]);
            indexS++;

            char[] o1 = new char[K];
            char[] o2 = new char[K];

            for (int i = 0; i < K; i++)
            {
                string pr = s[indexS];
                indexS++;
                o1[i] = pr[0];
                o2[i] = pr[1];
            }

            int L = int.Parse(s[indexS]);
            indexS++;

            string text = s[indexS];

            StringBuilder b = new StringBuilder();
            for (int i = 0; i < L; i++)
            {
                char c = text[i];

                if (b.Length == 0)
                {
                    b.Append(c);
                    continue;
                }

                for (int j = 0; j < N; j++)
                {
                    if ((c1[j] == c && b[b.Length - 1] == c2[j])
                        ||
                        (c2[j] == c && b[b.Length - 1] == c1[j]))
                    {
                        b[b.Length - 1] = c3[j];
                        goto M;
                    }
                }

                for (int j = 0; j < K; j++)
                {
                    if (o1[j] == c)
                    {
                        for(int k=0; k<b.Length; k++)
                        {
                            if (o2[j]==b[k])
                            {
                                b = new StringBuilder();
                                goto M;
                            }
                        }
                    }
                    else if (o2[j] == c)
                    {
                        for (int k = 0; k < b.Length; k++)
                        {
                            if (o1[j] == b[k])
                            {
                                b = new StringBuilder();
                                goto M;
                            }
                        }
                    }
                }

                b.Append(c);

                M:
                continue;
            }


            Console.Write("Case #{0}: [", C);
            writer.Write("Case #{0}: [", C);

            for (int i = 0; i < b.Length; i++ )
            {
                if (i != 0)
                {
                    Console.Write(", ");
                    writer.Write(", ");
                }

                Console.Write(b[i]);
                writer.Write(b[i]);
            }

            Console.WriteLine("]");
            writer.WriteLine("]");

        }
    }
}