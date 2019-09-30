using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj13qr
{
    class Program
    {
        public static double[,] ch;
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"C:\GCJ\B.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\B.out");
            for (int a = 0; a < t; a++)
            {
                string[] firstline = lines[idx++].Split(' ');
                int N = int.Parse(firstline[0]);
                int X = int.Parse(firstline[1]);
                int Y = int.Parse(firstline[2]);
                double answer;
                int tri = 1;
                while ((tri * (tri + 1)) / 2 <= N)
                {
                    tri+=2;
                }
                tri-=2;
                if(Math.Abs(X) + Math.Abs(Y) <= tri - 1){
                    answer = 1;
                }
                else if (!(Math.Abs(X) + Math.Abs(Y) <= tri + 1))
                {
                    answer = 0;
                }
                else
                {
                    int remaining = N - ((tri * (tri + 1)) / 2);
                    if (remaining == 0)
                    {
                        answer = 0;
                    }
                    else
                    {
                        int max = tri + 1;
                        ch = new double[remaining + 1, remaining + 1];
                        if (remaining > Y + max)
                        {
                            answer = 1;
                        }
                        else
                        {
                            double num = 0;
                            double denum = 0;
                            for (int i = Math.Max(0, remaining - max); i <= Y; i++)
                            {
                                num += choose(remaining, i);
                            } for (int i = Math.Max(0, remaining - max); i <= Math.Min(max, remaining); i++)
                            {
                                denum += choose(remaining, i);
                            }
                            answer = 1 - (num / denum);
                        }
                    }
                }
                tw.WriteLine("Case #{0}: {1}", a + 1, answer);
            }
            tw.Close();
            //Console.ReadLine();
        }

        private static double choose(int n, int k)
        {
           if(k==0){
               return 1;
           }
           if (n == 0)
           {
               return 0;
           }
           if (ch[n, k] != 0)
           {
               return ch[n, k];
           }

           return (ch[n, k] = choose(n - 1, k - 1) + choose(n - 1, k));
        }

    }
}
