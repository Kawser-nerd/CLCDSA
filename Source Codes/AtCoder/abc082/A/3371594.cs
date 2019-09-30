using System;

class Atcoder70
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        double a = double.Parse(input[0]);
        double b = double.Parse(input[1]);

        double average = (a + b) / 2.0;

        Console.WriteLine(Math.Ceiling(average));
    }
}