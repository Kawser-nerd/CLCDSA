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
            string[] s = C.ReadLine().Split(' ');
            int a = int.Parse(s[0]);
            int b = int.Parse(s[1]);
            if (a == b)
            {
                C.WriteLine("Draw");
            }
            else if (a == 1)
            {
                C.WriteLine("Alice");
            }
            else if (b == 1)
            {
                C.WriteLine("Bob");
            }
            else
            {
                C.WriteLine(a < b ? "Bob" : "Alice");
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