using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Console.SetIn(new System.IO.StreamReader("in.txt"));
            Console.SetOut(new System.IO.StreamWriter("out.txt") { AutoFlush = true });

            int t = int.Parse(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                var ss = Console.ReadLine().Split();
                int n = int.Parse(ss[0]);
                int k = int.Parse(ss[1]);

                double x = double.Parse(Console.ReadLine().Replace('.',','));
                ss = Console.ReadLine().Split();
                var p = new double[n+1];
                for (int j=0;j< n;j++)
                {
                    p[j] = double.Parse(ss[j].Replace('.', ','));
                }
                p[n] = 1.0;
                Array.Sort(p);

                for(int now = 0;now < n; now++)
                {
                    if ((p[now+1] - p[now]) * (now+1) < x)
                    {
                        x -= (p[now + 1] - p[now]) * (now + 1);
                        for (int jj = 0; jj <= now; jj++)
                            p[jj] = p[now + 1];
                    }
                    else
                    {
                        for (int jj = 0; jj <= now; jj++)
                            p[jj] += x / (now+1);

                        x = 0;
                        break;
                    }
                }
                p[n - 1] = Math.Min(1, p[n-1] + x);

                double result = 1;
                for (int j = 0; j < n; j++)
                    result *= p[j];

                Console.WriteLine($"Case #{i + 1}: {result.ToString().Replace(',', '.')}");
            }
        }
    }
}