using System;

class Program
{
    static void Main(string[] args)
    {
        var nm = Console.ReadLine().Split(' ');
        var n = int.Parse(nm[0]);
        var m = int.Parse(nm[1]);

        var a = new int[n];
        var b = new int[n];
        for (int i = 0; i < n; i++)
        {
            var ab = Console.ReadLine().Split(' ');
            a[i] = int.Parse(ab[0]);
            b[i] = int.Parse(ab[1]);
        }

        var min = int.MaxValue;

        for (int i = 0; i < n; i++)
        {
            if (b[i] <= m)
            {
                min = Math.Min(min, a[i]);
            }
        }

        if (min != int.MaxValue) Console.WriteLine(min);
        else Console.WriteLine("TLE");
    }
}