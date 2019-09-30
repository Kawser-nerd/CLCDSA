using System;

class Atcoder82
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int x = int.Parse(input[2]);

        if (x >= a && x <= (a + b))
            Console.WriteLine("YES");
        else
            Console.WriteLine("NO");
    }
}