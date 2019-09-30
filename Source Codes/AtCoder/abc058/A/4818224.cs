using System;

class Program
{
    static void Main(string[] args)
    {
        var abc = Console.ReadLine().Split();
        var a = int.Parse(abc[0]);
        var b = int.Parse(abc[1]);
        var c = int.Parse(abc[2]);

        if (b - a == c - b)
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}