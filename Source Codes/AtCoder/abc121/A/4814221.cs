using System;

class Program
{
    static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int h = int.Parse(input[0]);
        int w = int.Parse(input[1]);
        string[] input2 = Console.ReadLine().Split(' ');
        int h2 = int.Parse(input2[0]);
        int w2 = int.Parse(input2[1]);
        int ans = h * w - h2 * w - w2 * h + h2 * w2;
        Console.WriteLine(ans);
    }
}