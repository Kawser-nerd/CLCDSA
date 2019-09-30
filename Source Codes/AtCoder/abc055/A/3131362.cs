using System;
namespace WpfApp1
{
    using L = Library;
    using C = Console;
    using M = Math;
    class program:L.library
    {
        static void Main(string[] args)
        {
            int n = int.Parse(C.ReadLine());
            C.WriteLine(n * 800 - n / 15 * 200);
        }
        
    }
}
namespace Library
{
    class library
    {
        public static long Max(long a, long b)
        {
            return a < b ? b : a;
        }
        public static long Min(long a, long b)
        {
            return a < b ? a : b;
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