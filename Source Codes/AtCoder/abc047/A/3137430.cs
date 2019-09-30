using System;

class Atcoder39
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int c = int.Parse(input[2]);

        if (a + b == c || b + c == a || c + a == b)
            Console.WriteLine("Yes");
        else
            Console.WriteLine("No");
    }
}