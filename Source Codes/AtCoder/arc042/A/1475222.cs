using System;
using System.Linq;

namespace arc042_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] input = new int[x[1]];
            for (int i = 0; i < x[1]; i++)
            {
                input[i] = int.Parse(Console.ReadLine()) - 1;
            }
            bool[] used = new bool[x[0]];
            Array.Reverse(input);
            for (int i = 0; i < x[1]; i++)
            {
                if (!used[input[i]])
                {
                    used[input[i]] = true;
                    Console.WriteLine(input[i] + 1);
                }
            }
            for (int i = 0; i < x[0]; i++)
            {
                if (!used[i]) Console.WriteLine(i + 1);
            }
        }
    }
}