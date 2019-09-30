using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int D = int.Parse(Console.ReadLine());
            switch (D)
            {
                case 25:
                    Console.WriteLine("Christmas");
                    break;
                case 24:
                    Console.WriteLine("Christmas Eve");
                    break;
                case 23:
                    Console.WriteLine("Christmas Eve Eve");
                    break;
                case 22:
                    Console.WriteLine("Christmas Eve Eve Eve");
                    break;
                default:
                break;
            }

        }
    }
}