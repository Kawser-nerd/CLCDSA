using System;

class Atcoder115
{
    public static void Main()
    {
        string[] inputa = Console.ReadLine().Split(' ');
        int H = int.Parse(inputa[0]);
        int W = int.Parse(inputa[1]);

        string[] inputb = Console.ReadLine().Split(' ');
        int h = int.Parse(inputb[0]);
        int w = int.Parse(inputb[1]);

        Console.WriteLine((H - h) * (W - w));
    }
}