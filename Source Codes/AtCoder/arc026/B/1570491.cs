using System;

namespace arc026_2
{
    class Program
    {
        static void Main(string[] args)
        {
            long n = long.Parse(Console.ReadLine());
            long input = n;
            double ret = 1;
            for (long i = 2; i <= Math.Sqrt(n); i++)
            {
                if (input % i == 0)
                {
                    long x = 1;
                    long a = i;
                    for (long now = i; input % now == 0;)
                    {
                        input /= i;
                        x += a;
                        a *= i;
                    }
                    ret *= x;
                }
            }
            if (input != 1)
            {
                ret *= 1 + input;
            }
            ret -= n;
            if (ret == n)
            {
                Console.WriteLine("Perfect");
            }
            else
            {
                Console.WriteLine(ret > n ? "Abundant" : "Deficient");
            }
        }
    }
}