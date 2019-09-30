using System;

class Atcoder55
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);

        if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0)
            Console.WriteLine("Possible");
        else
            Console.WriteLine("Impossible");
    }
}