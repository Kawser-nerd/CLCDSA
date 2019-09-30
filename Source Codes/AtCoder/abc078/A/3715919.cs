using System;

class Program
{
    static void Main()
    {
        var data = Console.ReadLine().ToCharArray();
        var x = (int)data[0];
        var y = (int)data[2];

        if (x < y)
        {
            Console.WriteLine("<");
        }
        else if (x > y)
        {
            Console.WriteLine(">");
        }
        else
        {
            Console.WriteLine("=");
        }
    }
}