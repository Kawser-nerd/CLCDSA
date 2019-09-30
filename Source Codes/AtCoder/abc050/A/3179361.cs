using System;

class Atcoder42
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        string op = input[1];
        int b = int.Parse(input[2]);

        if (op == "+")
            Console.WriteLine(a + b);
        else
            Console.WriteLine(a - b);
    }
}