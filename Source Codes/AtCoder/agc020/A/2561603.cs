using System;

namespace AGC020A
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int a = int.Parse(input[1]);
            int b = int.Parse(input[2]);

            Console.WriteLine((b - a) % 2 != 0 ? "Borys" : "Alice");
        }
    }
}