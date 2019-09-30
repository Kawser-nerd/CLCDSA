using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            int output = int.Parse(input.Substring(0, 1)) + int.Parse(input.Substring(1, 1));
            Console.WriteLine(output);
        }
    }
}