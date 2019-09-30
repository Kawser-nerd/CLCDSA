using System;

class Atcoder50
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int c = int.Parse(input[2]);

        if (c - a >= 0 && b - c >= 0)
            Console.WriteLine("Yes");
        else
            Console.WriteLine("No");
    }
}