using System;

namespace A.Multiple_of_2_and_N
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());

            Console.WriteLine(N % 2 == 0 ? N : N * 2);
        }
    }
}