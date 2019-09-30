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
            int x = cin.Int();
            int[] a = cin.ArrayInt(N);

            Array.Sort(a);
            int ans = 0, index = 0;
            while(x >= a[index])
            {
                if (index != a.Length - 1)
                {
                    x -= a[index++];
                    ans++;
                }
                else
                {
                    if (a[index] == x) ans++;
                    break;
                }
            }

            Console.WriteLine(ans);
            Console.ReadLine();
        }

        static int GCD(int a, int b) //a,b?????????
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

        static int LCM(int a, int b) //a,b?????????
        {
            return a / GCD(a, b) * b;
        }
    

        static int BinarySearch<T>(T[] array, T target) where T : IComparable<T> //2???
        {
            int min = 0;
            int max = array.Length - 1;

            while (true)
            {
                // ????????????
                if (max < min) return -1;
                // ????????????
                int mid = min + (max - min) / 2;
                switch (target.CompareTo(array[mid]))
                {
                    case -1:    // ????????
                        max = mid - 1;
                        break;
                    case 1:     // ????????
                        min = mid + 1;
                        break;
                    case 0:     // ?????
                        return mid;
                }
            }
        }

        static void Swap<T>(ref T a, ref T b)
        {
            T tmp = a;
            a = b;
            b = tmp;
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