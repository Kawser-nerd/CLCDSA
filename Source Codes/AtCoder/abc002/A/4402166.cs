using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            if (int.Parse(input[0])> int.Parse(input[1]))
            {
                Console.WriteLine(input[0]);
            }
            else
            {
                Console.WriteLine(input[1]);
            }
        }
    }
}