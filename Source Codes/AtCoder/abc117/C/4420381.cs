using System;

class Program
{
    static void Main(string[] args)
    {
        var nm = Console.ReadLine().Split(' ');
        var n = int.Parse(nm[0]);
        var m = int.Parse(nm[1]);
        var d = new int[m];
        var s = Console.ReadLine().Split(' ');
        for (int i = 0; i < m; i++)
        {
            d[i] = int.Parse(s[i]);
        }

        Array.Sort(d);

        var e = new int[m - 1];
        for (int i = 1; i < m; i++)
        {
            e[i - 1] = d[i] - d[i - 1];
        }

        Array.Sort(e, (a, b) => b - a);

        var ans = 0;
        for (int i = n - 1; i < m - 1; i++)
        {
            ans += e[i];
        }

        Console.WriteLine(ans);
    }
}