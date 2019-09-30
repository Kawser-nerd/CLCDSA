using System;

class Program
{
    static void Main(string[] args)
    {
        var n = long.Parse(Console.ReadLine());
        var ans = long.MaxValue;
        for (long i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ans = Math.Min(ans,
                    Math.Max(f(i), f(n / i)));
            }
        }
        Console.WriteLine(ans);
    }

    static long f(long x)
    {
        var ans = 0;
        while (x != 0)
        {
            ans++;
            x /= 10;
        }
        return ans;
    }
}