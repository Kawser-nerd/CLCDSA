using System;

class Program
{
    static void Main()
    {
        var data = Console.ReadLine().Split();
        var a = int.Parse(data[0]);
        var b = int.Parse(data[1]);

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