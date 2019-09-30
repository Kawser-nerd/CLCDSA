using System;

class Atcoder62
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int a = int.Parse(Console.ReadLine());

        int grid = n * n;
        Console.WriteLine(grid - a);
    }
}