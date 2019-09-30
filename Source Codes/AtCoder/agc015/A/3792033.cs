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
            var N = cin.Long();
            var A = cin.Long();
            var B = cin.Long();

            long ans;
            if (A > B) ans = 0;
            else if (A == B) ans = 1;
            else
            {
                if (N == 1) ans = 0;
                else ans = A + (N - 1) * B - (N - 1) * A - B + 1;
            }
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