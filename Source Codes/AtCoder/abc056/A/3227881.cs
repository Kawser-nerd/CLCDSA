using System;

class Atcoder47
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');

        if (input[0] == "H" && input[1] == "H")
            Console.WriteLine("H");
        else if (input[0] == "H" && input[1] == "D")
            Console.WriteLine("D");
        else if (input[0] == "D" && input[1] == "H")
            Console.WriteLine("D");
        else
            Console.WriteLine("H");
    }
}