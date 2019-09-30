using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var n = long.Parse(Console.ReadLine());
        var len = int.MaxValue;
        for (long i = 1; i * i <= n; i++)
        {
            if (n % i != 0)
            {
                continue;
            }

            len = Math.Min(len, F(i, n / i));
        }

        Console.WriteLine(len);
    }

    static int F(long a, long b)
    {
        return Math.Max(a.ToString().Length, b.ToString().Length);
    }
}