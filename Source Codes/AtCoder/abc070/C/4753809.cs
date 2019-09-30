using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var ans = 1L;
        for (int i = 0; i < n; i++)
        {
            ans = lcm(ans, long.Parse(Console.ReadLine()));
        }
        Console.WriteLine(ans);
    }

    static long lcm(long n, long m) => n / gcd(n, m) * m;
    static long gcd(long n, long m) => m == 0 ? n : gcd(m, n % m);
}