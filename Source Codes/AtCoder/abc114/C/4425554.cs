using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var ans = m1(0, n);
        Console.WriteLine(ans);
    }

    static int[] d = new[] { 7, 5, 3 };
    static int m1(int x, int max)
    {
        var sum = m2(x) ? 1 : 0;
        for (int i = 0; i < 3; i++)
        {
            var n = 10 * x + d[i];
            if (0 < n && n <= max)
            {
                sum += m1(n, max);
            }
        }
        return sum;
    }

    static bool m2(int x)
    {
        var s = x.ToString();
        return s.Contains('7') && s.Contains('5') && s.Contains('3');
    }
}