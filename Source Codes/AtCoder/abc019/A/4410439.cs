using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int[] Age = new int[3];

            for (int i = 0; i < 3; i++)
            {
                Age[i] = int.Parse(input[i]);
            }
            Array.Sort(Age);
            Console.WriteLine(Age[1]);
        }
    }
}