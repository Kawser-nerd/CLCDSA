using System;

class Atcoder60
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int x = int.Parse(input[0]);
        int t = int.Parse(input[1]);

        if (x >= t)
            Console.WriteLine(x - t);
        else
            Console.WriteLine("0");
    }
}