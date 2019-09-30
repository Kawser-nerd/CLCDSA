using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int A = int.Parse(input[0]);
            int B = int.Parse(input[1]);
            int C = int.Parse(input[2]);


            if (B>A)
            {
                Console.WriteLine(C / A);
            }
            else
            {
                Console.WriteLine(C / B);
            }
        }
    }
}