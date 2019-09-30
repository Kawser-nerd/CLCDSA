using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ASmall
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            int tst = Console.ReadLine().ToInt();
            for (int cas = 1; cas < tst + 1; cas++)
            {
                int N = Console.ReadLine().ToInt();
                int[] x = new int[N];
                int[] y = new int[N];
                int[] r = new int[N];
                for (int i = 0; i < N; i++)
                {
                    var ar = Console.ReadLine().ToIntArray();
                    x[i] = ar[0];
                    y[i] = ar[1];
                    r[i] = ar[2];
                }
                double res = r[0];
                if (N==2)
                {
                    res = Math.Max(r[0], r[1]);
                }
                else if(N==3)
                {
                    res = 1e100;
                    for (int i = 0; i < 3; i++)
                    {
                        List<int> l = new List<int>();
                        for (int j = 0; j < 3; j++)
                        {
                            if (j==i)
                            {
                                continue;
                            }
                            l.Add(j);
                        }
                        int a = l[0];
                        int b = l[1];
                        double dx = x[a] - x[b];
                        double dy = y[a] - y[b];
                        double d = Math.Sqrt(dx*dx + dy*dy);
                        double res1 = (d + r[a] + r[b])*0.5;
                        res1 = Math.Max(res1, r[i]);
                        res = Math.Min(res, res1);
                        
                    }
                }
                Console.WriteLine("Case #" + cas + ": " + res);

            }
        }



    }


    

    internal static class Extensions
    {
        public static int ToInt(this string s)
        {
            return int.Parse(s);
        }

        public static int[] ToIntArray(this string s)
        {
            var tokens = s.Split(" \t".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            return tokens.Select(ob => ob.ToInt()).ToArray();
        }
    }


    
}
