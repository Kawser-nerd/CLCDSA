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
            int N = cin.Int();
            int K = cin.Int();
            int[] A = cin.ArrayInt(N);

            int gcd = A[0]; //A_sub??????????
            for (int i = 0; i < N; i++)
            {
                gcd = GCD(gcd, A[i]);
            }

            Console.WriteLine(K <= A.Max() && K % gcd == 0 ? "POSSIBLE" : "IMPOSSIBLE");
            Console.ReadLine();
        }
        static int GCD(int a, int b) //a,b??????
        {
            if (a < b)
                // ??????????????
                return GCD(b, a);
            while (b != 0)
            {
                var remainder = a % b;
                a = b;
                b = remainder;
            }
            return a;

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