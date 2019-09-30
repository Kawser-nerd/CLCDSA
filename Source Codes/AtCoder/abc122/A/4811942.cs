using System;

class Atcoder116
{
    public static void Main()
    {
        string b = Console.ReadLine();

        if (b == "A")
            Console.WriteLine("T");
        else if (b == "T")
            Console.WriteLine("A");
        else if (b == "G")
            Console.WriteLine("C");
        else
            Console.WriteLine("G");
    }
}