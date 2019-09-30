using System;

class Atcoder93
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int n = int.Parse(input[0]);
        int k = int.Parse(input[1]);

        if (n % k == 0)
            Console.WriteLine("0");
        else
            Console.WriteLine("1");
    }
}