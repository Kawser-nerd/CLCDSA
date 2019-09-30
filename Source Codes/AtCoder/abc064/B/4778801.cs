using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var s = Console.ReadLine().Split(' ');

        var min = int.MaxValue;
        var max = int.MinValue;
        for (int i = 0; i < n; i++)
        {
            var x = int.Parse(s[i]);
            min = Math.Min(min, x);
            max = Math.Max(max, x);
        }

        Console.WriteLine(max - min);
    }
}