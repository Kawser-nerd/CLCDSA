using System;
class Program
{
    static void Main(string[] args)
    {
        string[] input1 = Console.ReadLine().Split(' ');
        int H = int.Parse(input1[0]);
        int W = int.Parse(input1[1]);
        input1 = Console.ReadLine().Split(' ');
        int h = int.Parse(input1[0]);
        int w = int.Parse(input1[1]);
        Console.WriteLine((H - h) * (W - w));
    }
}