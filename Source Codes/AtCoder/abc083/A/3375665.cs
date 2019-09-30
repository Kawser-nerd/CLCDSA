using System;

class Atcoder71
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int c = int.Parse(input[2]);
        int d = int.Parse(input[3]);

        if ((a + b) > (c + d))
            Console.WriteLine("Left");
        else if ((a + b) < (c + d))
            Console.WriteLine("Right");
        else
            Console.WriteLine("Balanced");
    }
}