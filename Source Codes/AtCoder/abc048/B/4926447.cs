using System;

class Program
{
    static void Main(string[] args)
    {
        var abx = Console.ReadLine().Split();
        var a = long.Parse(abx[0]);
        var b = long.Parse(abx[1]);
        var x = long.Parse(abx[2]);
        Console.WriteLine(f(b, x) - f(a - 1, x));
    }

    static long f(long n, long x)
    {
        return n < 0 ? 0 : n / x + 1;
    }
}