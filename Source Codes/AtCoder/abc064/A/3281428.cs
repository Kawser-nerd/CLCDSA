using System;

class Atcoder52
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int r = int.Parse(input[0]);
        int g = int.Parse(input[1]);
        int b = int.Parse(input[2]);

        int mark = 10 * g + b;
        if (mark % 4 == 0)
            Console.WriteLine("YES");
        else
            Console.WriteLine("NO");
    }
}