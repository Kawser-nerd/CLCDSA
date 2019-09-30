using System;

class Program
{
    static void Main(string[] args)
    {
        var xy = Console.ReadLine().Split(' ');
        if (0 < xy[0].CompareTo(xy[1]))
        {
            Console.WriteLine(">");
        }
        else if (0 > xy[0].CompareTo(xy[1]))
        {
            Console.WriteLine("<");
        }
        else
        {
            Console.WriteLine("=");
        }
    }
}