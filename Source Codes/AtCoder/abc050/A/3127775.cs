using System;
namespace WpfApp1
{
    using l = Library;
    using C = Console;
    class program:l.library
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split();
            long a = long.Parse(s[0]);
            long b = long.Parse(s[2]);
            if (s[1] == "+")
            {
                C.WriteLine(a + b);
            }
            else if (s[1] == "-")
            {
                C.WriteLine(a - b);
            }
            else if (s[1] == "*")
            {
                C.WriteLine(a * b);
            }
            else
            {
                C.WriteLine(a / b);
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