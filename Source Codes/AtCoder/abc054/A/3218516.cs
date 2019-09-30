using System;

class Atcoder45
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);

        if (a == 1)
            a += 13;
        if (b == 1)
            b += 13;

        if (a > b)
            Console.WriteLine("Alice");
        else if (a < b)
            Console.WriteLine("Bob");
        else
            Console.WriteLine("Draw");
    }
}