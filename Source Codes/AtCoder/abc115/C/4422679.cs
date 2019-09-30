using System;

class Program
{
    static void Main(string[] args)
    {
        var nm = Console.ReadLine().Split(' ');
        var n = int.Parse(nm[0]);
        var m = int.Parse(nm[1]);

        var d = new int[n];
        for (int i = 0; i < n; i++)
        {
            d[i] = int.Parse(Console.ReadLine());
        }

        Array.Sort(d);

        var min = int.MaxValue;
        for (int i = m - 1; i < n; i++)
        {
            min = Math.Min(min, d[i] - d[i - m + 1]);
        }

        Console.WriteLine(min);
    }
}