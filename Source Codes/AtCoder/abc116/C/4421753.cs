using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var s = Console.ReadLine().Split(' ');

        var d = new int[n];
        for (int i = 0; i < n; i++)
        {
            d[i] = int.Parse(s[i]);
        }

        var p = 0;
        var ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (p < d[i])
            {
                ans += d[i] - p;
                p = d[i];
            }
            else
            {
                p = d[i];
            }
        }

        Console.WriteLine(ans);
    }
}