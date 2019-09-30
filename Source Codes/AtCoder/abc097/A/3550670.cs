using System;

class Atcoder85
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int c = int.Parse(input[2]);
        int d = int.Parse(input[3]);

        if (System.Math.Abs(a - c) <= d)
            Console.WriteLine("Yes");
        else if (System.Math.Abs(a - b) <= b && System.Math.Abs(b - c) <= d)
            Console.WriteLine("Yes");
        else
            Console.WriteLine("No");
    }
}