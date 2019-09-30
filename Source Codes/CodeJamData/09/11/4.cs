using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace C
{
    internal class Program
    {
        private static int[,] a;
        static int next(int i,int b)
        {
            int ret = 0;
            while (i>0)
            {
                int t1 = i%b;
                i /= b;
                ret = ret + t1*t1;
            }
            return ret;
        }
        static int go(int p,int b)
        {
            if (a[b,p]>=0)
            {
                return a[b,p];
            }
            a[b,p] = 0;
            int ret = go(next(p,b), b);
            a[b,p] = ret;
            return ret;
        }

        static bool isSmile(int p,int b)
        {
            int t1 = p;
            while (t1>=1000)
            {
                t1 = next(t1, b);
            }
            return a[b, t1] == 1;
        }

        private static void Main(string[] args)
        {
            int tst = Console.ReadLine().ToInt();
            a = (int[,]) CreateArray(-1, 11,1000);
            for (int N = 2; N < 11; N++)
            {
                a[N,1] = 1;
                for (int i = 2; i < 1000; i++)
                {
                    if (a[N,i] >= 0)
                    {
                        continue;
                    }
                    a[N,i] = go(i, N);
                }
                
            }
            int[] precalc = (int[]) CreateArray(-1, 1 << 9);
            int target = (1 << 9) - 1;
            int cur = 1;
            precalc[0] = 0;
            while (precalc[target]==-1)
            {
                ++cur;
                int mask = 0;
                for (int i = 2; i < 11; i++)
                {
                    if (isSmile(cur,i))
                    {
                        mask |= (1 << (i - 2));
                    }
                }
                if (precalc[mask]>=0)
                {
                    continue;

                }
                for (int i = 1; i < (1<<9); i++)
                {
                    if (precalc[i]>=0)
                    {
                        continue;
                    }
                    int t1 = mask & i;
                    if (t1!=i)
                    {
                        continue;
                    }
                    precalc[i] = cur;
                }
            }
           


            
            for (int cas = 1; cas < tst + 1; cas++)
            {
                var tokens = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                int[] bases = new int[tokens.Length];
                int mask = 0;
                for (int i = 0; i < bases.Length; i++)
                {
                    bases[i] = tokens[i].ToInt();
                    mask = mask | (1 << (bases[i] - 2));
                }
                Console.Write("Case #" + cas + ": ");
                Console.WriteLine(precalc[mask]);

            }
        }

        private static Array CreateArray<T>(T defaultValue, params int[] length)
        {
            Array a = Array.CreateInstance(typeof (T), length);
            for (int i = 0; i < a.Length; ++i)
            {
                int N = length.Length;
                int[] b = new int[N];
                int ind = i;
                for (int j = N - 1; j >= 0; --j)
                {
                    b[j] = ind%length[j];
                    ind = ind/length[j];
                }
                a.SetValue(defaultValue, b);
            }
            return a;
        }


    }

    internal static class Extensions
    {
        public static int ToInt(this string s)
        {
            return int.Parse(s);
        }
    }


}
