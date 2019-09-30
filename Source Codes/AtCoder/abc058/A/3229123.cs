using System;

class Atcoder49
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int c = int.Parse(input[2]);

        int difab = b - a;
        int difbc = c - b;

        if (difab == difbc)
            Console.WriteLine("YES");
        else
            Console.WriteLine("NO");
    }
}