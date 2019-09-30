using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var x = 1;
        while (x * 2 <= n)
        {
            x *= 2;
        }
        Console.WriteLine(x);
    }
}