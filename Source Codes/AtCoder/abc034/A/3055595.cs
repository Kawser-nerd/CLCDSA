using System;

class Atcoder28
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int x = int.Parse(input[0]);
        int y = int.Parse(input[1]);

        if (x > y) {
            Console.WriteLine("Worse");
        }
        else {
            Console.WriteLine("Better");
        }
    }
}