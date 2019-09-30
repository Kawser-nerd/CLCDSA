using System;

class Program
{
    static void Main(string[] args)
    {
        var abc = Console.ReadLine().Split();
        var a = int.Parse(abc[0]);
        var b = int.Parse(abc[1]);
        var c = int.Parse(abc[2]);

        if (a == b + c ||
            b == a + c ||
            c == a + b)
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}