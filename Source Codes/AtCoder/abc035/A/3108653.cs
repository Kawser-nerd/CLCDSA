using System;
namespace WpfApp1
{
    using l=Library;
    class program:l.library
    {
        static void Main(string[] args)
        {
            string[] x = Console.ReadLine().Split(' ');
            int w = int.Parse(x[0]);
            int h = int.Parse(x[1]);
            if (w / 4 * 3 == h)
            {
                Console.WriteLine("4:3");
            }
            else
            {
                Console.WriteLine("16:9");
            }
        }
        
    }
}
namespace Library
{
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