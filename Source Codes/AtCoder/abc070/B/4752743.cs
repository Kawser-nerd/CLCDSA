using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine().Split(' ');
        var ans = Math.Min(int.Parse(s[1]), int.Parse(s[3])) - Math.Max(int.Parse(s[0]), int.Parse(s[2]));
        Console.WriteLine(Math.Max(0, ans));
    }
}