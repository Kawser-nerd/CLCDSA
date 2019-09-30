using System;

class Atcoder57
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int n = int.Parse(input[0]);
        int m = int.Parse(input[1]);

        Console.WriteLine((n - 1) * (m - 1));
    }
}