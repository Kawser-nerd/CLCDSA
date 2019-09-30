using System;

class Atcoder53
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int x = int.Parse(input[0]);
        int a = int.Parse(input[1]);
        int b = int.Parse(input[2]);

        if (b <= a)
            Console.WriteLine("delicious");
        else if (b > a && b <= x + a)
            Console.WriteLine("safe");
        else
            Console.WriteLine("dangerous");
    }
}