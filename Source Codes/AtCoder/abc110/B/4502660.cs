using System;

class Program
{
    static void Main(string[] args)
    {
        var nmxy = Console.ReadLine().Split(' ');
        var n = int.Parse(nmxy[0]);
        var m = int.Parse(nmxy[1]);
        var X = int.Parse(nmxy[2]);
        var Y = int.Parse(nmxy[3]);

        var s = Console.ReadLine().Split(' ');
        var max = int.MinValue;
        for (int i = 0; i < n; i++)
        {
            max = Math.Max(max, int.Parse(s[i]));
        }

        s = Console.ReadLine().Split(' ');
        var min = int.MaxValue;
        for (int i = 0; i < m; i++)
        {
            min = Math.Min(min, int.Parse(s[i]));
        }

        if (X < Y && X < min && max < Y && max < min)
        {
            Console.WriteLine("No War");
        }
        else
        {
            Console.WriteLine("War");
        }
    }
}