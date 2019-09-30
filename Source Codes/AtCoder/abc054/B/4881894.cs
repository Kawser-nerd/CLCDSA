using System;

class Program
{
    static void Main(string[] args)
    {
        var nm = Console.ReadLine().Split();
        var n = int.Parse(nm[0]);
        var m = int.Parse(nm[1]);

        var a = new bool[n, n];
        for (int i = 0; i < n; i++)
        {
            var s = Console.ReadLine();
            for (int j = 0; j < n; j++)
            {
                a[i, j] = s[j] == '#';
            }
        }

        var b = new bool[m, m];
        for (int i = 0; i < m; i++)
        {
            var s = Console.ReadLine();
            for (int j = 0; j < m; j++)
            {
                b[i, j] = s[j] == '#';
            }
        }

        for (int i = 0; i < n - m + 1; i++)
        {
            for (int j = 0; j < n - m + 1; j++)
            {
                var all = true;
                for (int x = 0; x < m; x++)
                {
                    for (int y = 0; y < m; y++)
                    {
                        all &= a[i + x, j + y] == b[x, y];
                    }
                }
                if (all)
                {
                    Console.WriteLine("Yes");
                    return;
                }
            }
        }

        Console.WriteLine("No");
    }
}