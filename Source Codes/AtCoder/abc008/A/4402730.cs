using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            Console.WriteLine(int.Parse(input[1]) - int.Parse(input[0]) + 1);
        }
    }
}