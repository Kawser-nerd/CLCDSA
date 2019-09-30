using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split(' ');
        var n = int.Parse(ab[0]) + int.Parse(ab[1]);

        if (n % 2 == 0)
        {
            Console.WriteLine(n / 2);
        }
        else
        {
            Console.WriteLine(n / 2 + 1);
        }
    }
}