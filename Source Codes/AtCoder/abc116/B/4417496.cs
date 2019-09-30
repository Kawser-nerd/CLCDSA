using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        public static void Main(string[] args)
        {
            int s = int.Parse(Console.ReadLine());
            int n = 1;
            int[] a = new int[1000001];
            for (int i = 0; i < 1000001; i++) { a[i] = 0; }
            a[s] = 1;
            while (n <= 1000000)
            {
                n++;
                s = f(s);
                if (a[s] == 1) { break; }
                a[s] = 1;
            }
            Console.WriteLine("{0}", n);
        }

        public static int f(int n)
        {
            return ((n % 2) == 0) ? n / 2 : 3 * n + 1;
        }
    }
}