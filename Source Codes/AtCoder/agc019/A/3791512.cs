using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            Scanner cin = new Scanner();
            long Q = cin.Long();
            long H = cin.Long();
            long S = cin.Long();
            long D = cin.Long();
            long N = cin.Long();

            long[] price = { 8 * Q, 4 * H, 2 * S, D };
            Array.Sort(price);
            long ans = price[0] * (N / 2);
            N -= 2 * (N / 2);

            long[] rest_price = { 4 * Q, 2 * H, S };
            Array.Sort(rest_price);
            ans += N > 0 ? rest_price[0] : 0;
           
            Console.WriteLine(ans);
            Console.ReadLine();
        }
    }

    class Scanner //????
    {
        string[] s;
        int i;

        char[] cs = new char[] { ' ' };

        public Scanner()
        {
            s = new string[0];
            i = 0;
        }

        public string next()
        {
            if (i < s.Length) return s[i++];
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            if (s.Length == 0) return next();
            i = 0;
            return s[i++];
        }

        public int Int()
        {
            return int.Parse(next());
        }
        public int[] ArrayInt(int N, int add = 0)
        {
            int[] Array = new int[N];
            for (int i = 0; i < N; i++)
            {
                Array[i] = Int() + add;
            }
            return Array;
        }

        public long Long()
        {
            return long.Parse(next());
        }

        public long[] ArrayLong(int N, long add = 0)
        {
            long[] Array = new long[N];
            for (int i = 0; i < N; i++)
            {
                Array[i] = Long() + add;
            }
            return Array;
        }

        public double Double()
        {
            return double.Parse(next());
        }


        public double[] ArrayDouble(int N, double add = 0)
        {
            double[] Array = new double[N];
            for (int i = 0; i < N; i++)
            {
                Array[i] = Double() + add;
            }
            return Array;
        }
    }
}