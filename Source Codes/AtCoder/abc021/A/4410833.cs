using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int answer=N / 2 + N%2;
            Console.WriteLine(N / 2 + N % 2);
            if (N%2==1)
            {
                Console.WriteLine(1);
            }

            for (int i = 0; i < N/2; i++)
            {
                Console.WriteLine(2);
            }
        }
    }
}