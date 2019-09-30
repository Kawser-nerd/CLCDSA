using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());

            if (a%b==0)
            {
                Console.WriteLine(0);
            }
            else
            {
                Console.WriteLine(b - a % b);
            }
        }
    }
}