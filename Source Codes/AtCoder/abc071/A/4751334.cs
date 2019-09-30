using System;

class Program
{
    static void Main(string[] args)
    {
        var xab = Console.ReadLine().Split(' ');
        var x = int.Parse(xab[0]);
        var a = int.Parse(xab[1]);
        var b = int.Parse(xab[2]);

        if (Math.Abs(x - a) < Math.Abs(x - b))
        {
            Console.WriteLine("A");
        }
        else
        {
            Console.WriteLine("B");
        }
    }
}