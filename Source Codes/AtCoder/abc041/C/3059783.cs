using System;
using System.Linq;

namespace AtTest.C_Challenge
{
    class ABC_041
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] input = Console.ReadLine().Split(' ');
            var heights = new int[n][];
            for (int i = 0; i < n; i++)
            {
                heights[i] = new int[2] { i, int.Parse(input[i]) };
            }
            Array.Sort(heights, (a, b) => b[1] - a[1]);
            for(int i = 0; i < n; i++)
            {
                Console.WriteLine(heights[i][0] + 1);
            }
        }
    }
}