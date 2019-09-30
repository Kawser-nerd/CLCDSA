using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            if (input[0]==input[1])
            {
                Console.WriteLine(input[2]);
            }
            else if (input[0] == input[2])
            {
                Console.WriteLine(input[1]);
            }
            else
            {
                Console.WriteLine(input[0]);
            }
        }
    }
}