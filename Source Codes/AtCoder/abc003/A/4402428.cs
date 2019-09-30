using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N=int.Parse(Console.ReadLine());
            int Answer = (1 + N) * 10000 / 2;
            Console.WriteLine(Answer);
        }
    }
}