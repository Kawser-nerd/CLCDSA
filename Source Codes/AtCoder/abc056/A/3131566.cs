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
            string[] a = C.ReadLine().Split(' ');
            C.WriteLine(a[0] == a[1] ? 'H' : 'D');
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