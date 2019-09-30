using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var min = int.MaxValue;
        var max = int.MinValue;
        var s = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            var ai = int.Parse(s[i]);
            min = Math.Min(min, ai);
            max = Math.Max(max, ai);
        }
        Console.WriteLine(Math.Abs(max - min));
    }
}