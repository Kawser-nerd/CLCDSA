using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        long n = long.Parse(Console.ReadLine());
        Console.WriteLine(n - 1 + (n % 2) * 2);
    }
}