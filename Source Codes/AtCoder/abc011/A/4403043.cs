using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            if (N==12)
            {
                Console.WriteLine(1);
            }
            else
            {
                Console.WriteLine(N + 1);
            }
        }
    }
}