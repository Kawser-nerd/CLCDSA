using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        int c = int.Parse(Console.ReadLine());
        int d = int.Parse(Console.ReadLine());
        Console.WriteLine(Math.Min(a,b)+Math.Min(c,d));
    }
}