using System;
namespace AGC014A
{
    class Program
    {
        static bool Check(long a, long b, long c)
        {
            return a % 2 == 0 && b % 2 == 0 && c % 2 == 0;
        }
        static void Main()
        {
            string[] s = Console.ReadLine().Split(' ');
            long a, b, c;
            a = long.Parse(s[0]);
            b = long.Parse(s[1]);
            c = long.Parse(s[2]);
            if (a == b && b == c && Check(a, b, c))
            {
                Console.WriteLine(-1);
                Environment.Exit(0);
            }
            for (long i = 0; ; i++)
            {
                if (!Check(a, b, c))
                {
                    Console.WriteLine(i);
                    Environment.Exit(0);
                }
                long at = a, bt = b, ct = c;
                a = (bt + ct) / 2;
                b = (at + ct) / 2;
                c = (at + bt) / 2;
            }
        }
    }
}