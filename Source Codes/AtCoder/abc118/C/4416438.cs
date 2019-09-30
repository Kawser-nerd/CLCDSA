using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var d = new int[n];
        var s = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            d[i] = int.Parse(s[i]);
        }

        var ans = gcd(d);
        Console.WriteLine(ans);
    }

    static int gcd(int[] d)
    {
        var ans = d[0];
        for (int i = 1; i < d.Length; i++)
        {
            ans = gcd(ans, d[i]);
        }
        return ans;
    }

    static int gcd(int x, int y)
    {
        if (x == 0) return y;
        if (y == 0) return x;
        if (x < y) return gcd(x, y % x);
        else return gcd(x % y, y);
    }
}