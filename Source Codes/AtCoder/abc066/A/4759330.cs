using System;

class Program
{
    static void Main(string[] args)
    {
        var abc = Console.ReadLine().Split(' ');
        var a = int.Parse(abc[0]);
        var b = int.Parse(abc[1]);
        var c = int.Parse(abc[2]);

        var ans = Math.Min(Math.Min(a + b, a + c), b + c);
        Console.WriteLine(ans);
    }
}