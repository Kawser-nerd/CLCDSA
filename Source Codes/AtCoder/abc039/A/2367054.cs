using System;

class Atcoder03
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int c = int.Parse(input[2]);

        int ab = 2 * a * b;
        int ac = 2 * a * c;
        int bc = 2 * b * c;

        Console.WriteLine(ab + ac + bc);
    }
}