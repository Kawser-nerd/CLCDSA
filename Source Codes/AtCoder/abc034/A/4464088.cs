using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int X = int.Parse(input[0]);
            int Y = int.Parse(input[1]);
            if (Y-X>0)
            {
                Console.WriteLine("Better");
            }
            else
            {
                Console.WriteLine("Worse");
            }
        }
    }
}