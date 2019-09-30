using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        var min = int.MaxValue;
        for (int i = 2; i < s.Length; i++)
        {
            var n = int.Parse(s.Substring(i - 2, 3));
            min = Math.Min(min, Math.Abs(753 - n));
        }
        Console.WriteLine(min);
    }
}