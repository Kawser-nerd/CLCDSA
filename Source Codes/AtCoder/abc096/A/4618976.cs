using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split(' ');
        var a = int.Parse(ab[0]);
        var b = int.Parse(ab[1]);
        if (b < a)
        {
            Console.WriteLine(a - 1);
        }
        else
        {
            Console.WriteLine(a);
        }
    }
}