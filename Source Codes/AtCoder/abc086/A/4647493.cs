using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split(' ');
        var a = int.Parse(ab[0]);
        var b = int.Parse(ab[1]);
        if (a % 2 == 0 || b % 2 == 0)
        {
            Console.WriteLine("Even");
        }
        else
        {
            Console.WriteLine("Odd");
        }
    }
}