using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int A = int.Parse(input[0]);
            int B = int.Parse(input[2]);
            if (input[1]=="+")
            {
                Console.WriteLine(A + B);
            }
            else
            {
                Console.WriteLine(A - B);
            }

        }  
    }
}