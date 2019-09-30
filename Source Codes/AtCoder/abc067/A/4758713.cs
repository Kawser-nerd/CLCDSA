using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split(' ');
        var a = int.Parse(ab[0]);
        var b = int.Parse(ab[1]);
        if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0)
        {
            Console.WriteLine("Possible");
        }
        else
        {
            Console.WriteLine("Impossible");
        }
    }
}