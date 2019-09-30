using System;

class Program
{
    static void Main(string[] args)
    {
        var nx = Console.ReadLine().Split(' ');
        var n = int.Parse(nx[0]);
        var x = int.Parse(nx[1]);

        var d = new int[n + 1];
        d[n] = x;

        var s = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            d[i] = int.Parse(s[i]);
        }

        Array.Sort(d);

        var diff = new int[n];
        for (int i = 0; i < n; i++)
        {
            diff[i] = d[i + 1] - d[i];
        }

        var ans = diff[0];
        for (int i = 1; i < n; i++)
        {
            ans = gcd(ans, diff[i]);
        }

        Console.WriteLine(ans);
    }

    static int gcd(int a, int b)
    {
        if (a == 0) return b;
        else if (b == 0) return a;
        else if (a < b) return gcd(b % a, a);
        else return gcd(a % b, b);
    }
}