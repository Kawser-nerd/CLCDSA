using System;

class Atcoder68
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int n = int.Parse(input[0]);
        int a = int.Parse(input[1]);
        int b = int.Parse(input[2]);

        int plana = n * a;

        if (plana < b)
            Console.WriteLine(plana);
        else
            Console.WriteLine(b);
    }
}