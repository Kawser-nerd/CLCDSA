using System;

class Program
{
    static long n;
    static long s;

    static void Main()
    {
        n = long.Parse(Console.ReadLine());
        s = long.Parse(Console.ReadLine());

        long s_n = (long)Math.Pow(n, 0.5);
        for (long b = 2; b <= s_n; b++)
        {
            long n_ = n;
            long sum = 0;
            while (n_ > 0)
            {
                sum += n_ % b;
                n_ /= b;
            }
            if (s == sum)
            {
                Console.WriteLine(b);
                return;
            }
        }

        long u = (long)((n - s) / (Math.Pow(n, 0.5) - 1));
        for (long k = Math.Min(u, s); k > 0; k--)
        {
            if ((n - s) % k != 0) continue;
            long p = (n + k - s) / k;
            if (k >= p || (s - k) >= p) continue;
            Console.WriteLine(p);
            return;
        }

        if (s == n)
        {
            Console.WriteLine(n + 1);
            return;
        }

        Console.WriteLine(-1);
    }
}