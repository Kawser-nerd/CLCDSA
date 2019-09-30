using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int[] zahyou = new int[4];
            for (int i = 0; i < input.Length; i++)
            {
                zahyou[i] = int.Parse(input[i]);
            }
            int x3 = zahyou[2] - zahyou[3] + zahyou[1];
            int y3 = zahyou[3] + zahyou[2] - zahyou[0];
            int x4 = zahyou[0] - zahyou[3] + zahyou[1];
            int y4 = zahyou[1] + zahyou[2] - zahyou[0];

            Console.WriteLine($"{x3} {y3} {x4} {y4}");
        }
    }
}