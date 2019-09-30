using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int N = int.Parse(input[0]);
            int X = int.Parse(input[1]);

            if (X-1<N-X)
            {
                Console.WriteLine(X - 1);
            }
            else
            {
                Console.WriteLine(N - X);
            }
        }
    }
}