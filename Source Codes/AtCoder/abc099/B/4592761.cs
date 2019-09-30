using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split(' ');
        var a = int.Parse(ab[0]);
        var b = int.Parse(ab[1]);

        var n = m1(b - a);
        Console.WriteLine(n - b);
    }

    static int m1(int n)
    {
        if (n == 1) return 1;
        return n + m1(n - 1);
    }
}