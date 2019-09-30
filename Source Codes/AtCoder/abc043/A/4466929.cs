using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            Console.WriteLine(N * (N + 1) / 2);
        }
    }
}