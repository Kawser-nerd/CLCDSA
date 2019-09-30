using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string infile = "in.txt";
            string outfile = "out.txt";

            TextReader tr = new StreamReader(new FileStream(infile, FileMode.Open));
            if (File.Exists(outfile))
                File.Delete(outfile);
            TextWriter tw = new StreamWriter(new FileStream(outfile, FileMode.Create));

            int T = int.Parse(tr.ReadLine());

            for (int t = 0; t < T; t++)
            {
                string[] s = tr.ReadLine().Split(' ');
                int R = int.Parse(s[0]);
                int k = int.Parse(s[1]);
                int N = int.Parse(s[2]);

                long[] g = new long[N];

                string[] ss = tr.ReadLine().Split(' ');

                long[] sum = new long[N];

                for (int i = 0; i < N; i++)
                {
                    g[i] = long.Parse(ss[i]);
                    if (i == 0)
                        sum[i] = g[i];
                    else
                        sum[i] = sum[i - 1] + g[i];
                }

                long total = 0;
                int a = 0;

                long m = 10;

                for (int r = 0; r < R; r++)
                {
                    long goes = 0L;
                    int b = N;
                    if (goes + sum[b - 1] - sum[a] + g[a] <= k)
                    {
                        goes += sum[b - 1] - sum[a] + g[a];
                        b = a;
                        a = 0;
                    }

                    while (a < b)
                    {
                        int c = (a + b) / 2;

                        if (goes + sum[c] - sum[a] + g[a] <= k)
                        {
                            goes += sum[c] - sum[a] + g[a];
                            a = c + 1;
                        }
                        else
                            b = c;
                    }
                    total += goes;
                   
                }

                tw.WriteLine(string.Format("Case #{0}: {1}", (t + 1), total.ToString()));
                Console.WriteLine(t);
            }

            tw.Flush();
            tw.Close();
        }


    }
}
