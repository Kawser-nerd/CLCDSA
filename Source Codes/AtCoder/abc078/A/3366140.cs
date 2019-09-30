using System;

class Atcoder66
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int x = Convert.ToInt32(input[0], 16);
        int y = Convert.ToInt32(input[1], 16);

        if (x < y)
            Console.WriteLine("<");
        else if (x > y)
            Console.WriteLine(">");
        else
            Console.WriteLine("=");
    }
}