using System;

class Atcoder51
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);

        if (a + b >= 10)
            Console.WriteLine("error");
        else
            Console.WriteLine(a + b);
    }
}