using System;
using System.Linq;
class c
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var count = new int[101];
        addPrime(n, ref count);
        int a, b, c, d, e, g, h;
        a = count.Where(f => f >= 4).Count();
        b = count.Where(f => f < 4 && f >= 2).Count();
        c = count.Where(f => f >= 14).Count();
        d = count.Where(f => f < 14 && f >= 4).Count();
        e = count.Where(f => f >= 24).Count();
        g = count.Where(f => f < 24 && f >= 2).Count();
        h = count.Where(f => f >= 74).Count();
        long ans = 0;
        ans += a * (a - 1) * (a - 2) / 2 + a * (a - 1) * b / 2;
        ans += c * (c - 1) + c * d;
        ans += e * (e - 1) + e * g;
        ans += h;
        Console.WriteLine(ans);
    }
    static void addPrime(int n, ref int[] count)
    {
        for (int i = 2; i <= n; i++)
        {
            int x = i;
            for (int j = 2; j <= n; j++)
            {
                while (x % j == 0)
                {
                    x /= j;
                    count[j]++;
                }
            }
        }
    }
}