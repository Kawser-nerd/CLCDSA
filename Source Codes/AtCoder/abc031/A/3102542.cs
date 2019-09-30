using System;
namespace WpfApp1
{
    using l=library;
    class program:l
    {
        static void Main(string[] args)
        {
            string[] a = Console.ReadLine().Split(' ');
            int x = int.Parse(a[0]);
            int y = int.Parse(a[1]);
            Console.WriteLine((Min(x, y) + 1) * Max(x, y));
            Console.ReadLine();
        }
        
    }
    class library
    {
        public static long Max(long a, long b)
        {
            if (a <= b) return b;
            else return a;
        }
        public static long Min(long a, long b)
        {
            if (a == Max(a, b)) return b;
            else return a;
        }
        public static long GCD(long a, long b)
        {
            while (Max(a, b) % Min(a, b) != 0)
            {
                if (a < b) b %= a;
                else a %= b;
            }
            return Min(a, b);
        }
        public static long LCM(long a, long b)
        {
            return a / GCD(a, b) * b;
        }
    }
}