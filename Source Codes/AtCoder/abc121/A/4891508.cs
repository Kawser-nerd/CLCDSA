using System;

class ABC121_A
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int H = int.Parse(input[0]);
        int W = int.Parse(input[1]);

        string[] input2 = Console.ReadLine().Split(' ');
        int h = int.Parse(input2[0]);
        int w = int.Parse(input2[1]);

        int ans = (H-h) * (W-w);

        Console.WriteLine(ans);
    }
}