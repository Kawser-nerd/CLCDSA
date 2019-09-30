using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split(' ');
        var a = int.Parse(ab[0]);
        var b = int.Parse(ab[1]);
        var ans = Math.Max(Math.Max(
            a + b,
            a - b),
            a * b);
        Console.WriteLine(ans);
    }
}