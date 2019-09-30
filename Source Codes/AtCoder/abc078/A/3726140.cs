using System;
using System.Linq;

public class Program
{
    public static void Main()
    {
        var data = Console.ReadLine().Split();
        var x = (int)data[0].ToCharArray()[0];
        var y = (int)data[1].ToCharArray()[0];

        if (x < y)
        {
            Console.WriteLine("<");
        }
        else if (x == y)
        {
            Console.WriteLine("=");
        }
        else
        {
            Console.WriteLine(">");
        }
    }
}