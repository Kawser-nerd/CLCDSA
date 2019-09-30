using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            Console.WriteLine(input[1] + " " + input[0]);
        }
    }
}