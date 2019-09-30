using System;

class Atcoder63
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int c = int.Parse(input[2]);

        if (a == b)
            Console.WriteLine(c);
        else if (a == c)
            Console.WriteLine(b);
        else
            Console.WriteLine(a);
    }
}