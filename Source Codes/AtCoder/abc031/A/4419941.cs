using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int A = int.Parse(input[0]);
            int D = int.Parse(input[1]);

            if (A<D)
            {
                Console.WriteLine((A + 1) * D);
            }
            else
            {
                Console.WriteLine(A * (D + 1));
            }

        }
    }
}