using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace C
{
    internal class Program
    {
        public static double[,] comb;
        private static void Main(string[] args)
        {
            int tst = Console.ReadLine().ToInt();
            comb = new double[42,42];
            comb[0,0] = 1;
            for (int i = 1; i < 42; i++)
            {
                comb[i, 0] = comb[i, i] = 1;
                for (int j = 1; j < i; j++)
                {
                    comb[i, j] = comb[i - 1, j - 1] + comb[i - 1, j];
                }
            }
            for (int cas = 1; cas < tst + 1; cas++)
            {
                var tokens = CInputUtility.NextIntArray();
                int C = tokens[1];
                int N = tokens[0];
                /*
                Calc ob = new Calc(C,N);
                 * */
                CalcLarge ob = new CalcLarge(C,N);
                double result = ob.result();
                Console.Write("Case #" + cas + ": ");
                Console.WriteLine(string.Format("{0:0.0000000}",result));
            }
        }
    }


    class CalcLarge
    {
        private int N;
        private int C;
        private int depth;
        private double[,] cache;

        public CalcLarge(int c,int n)
        {
            N = n;
            C = c;
        }

        double go(int cur,int h)
        {
            if (cur==N)
            {
                return 0.0;
            }
            if (h==depth)
            {
                return 0.0;
            }
            if (cache[cur,h]>=0)
            {
                return cache[cur, h];
            }
            double ret = 0;
            for (int i = 0; i <= C; i++)
            {
                if ((cur+C-i)>N)
                {
                    continue;
                }
                if (i>cur)
                {
                    continue;
                }
                double t1 = (Program.comb[cur, i]*Program.comb[N - cur, C-i]);
                t1 /= Program.comb[N, C];
                double t2 = go(cur + C - i, h + 1);
                ret = ret + t1*(1 + t2);

            }
            return cache[cur,h]=ret;
        }


        public double result()
        {
            depth = 1200;
            cache = (double[,]) CreateArray(-1.0, N, depth);
            return 1 + go(C, 0);
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


    internal class Calc
    {
        private int N;
        private int C;
        private double[,] cache;
        private int depth;
        private int[] NC;
        public Calc(int c,int n)
        {
            C = c;
            N = n;
            List<int> l = new List<int>();
            for (int i = 0; i < (1<<N); i++)
            {
                if (bits(i)==C)
                {
                    l.Add(i);
                }
            }
            NC = l.ToArray();

        }


        double go(int mask,int h)
        {
            if (h==depth)
            {
                return 0;
            }
            if (mask==((1<<N)-1))
            {
                return 0;                
            }
            if (cache[mask,h]>=0)
            {
                return cache[mask, h];
            }
            double ret = 0;
            int M = NC.Length;
            for (int i = 0; i < M; i++)
            {
                int t1 = mask | NC[i];
                ret = ret + (1 + go(t1, h + 1))/M;
            }
            return cache[mask, h] = ret;
            
        }

        public double result()
        {
            if (NC.Length==1)
            {
                return 1.0;
            }
            depth = 200;
            cache = (double[,]) CreateArray(-1.0, 1 << N, depth);
            return go(0, 0);
        }

        int bits(int p)
        {
            if (p==0)
            {
                return 0;
            }
            return bits(p/2) + p%2;
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

    class CInputUtility
    {
        public static int[] NextIntArray()
        {
            string[] s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int[] ret = new int[s.Length];
            for (int i = 0; i < ret.Length; i++)
            {
                ret[i] = s[i].ToInt();
            }
            return ret;
            
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
