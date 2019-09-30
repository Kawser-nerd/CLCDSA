using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();

            switch (input)
            {
                case "A":
                    Console.WriteLine(1);
                    break;
                case "B":
                    Console.WriteLine(2);
                    break;
                case "C":
                    Console.WriteLine(3);
                    break;
                case "D":
                    Console.WriteLine(4);
                    break;
                case "E":
                    Console.WriteLine(5);
                    break;
                default:
                    break;
            }
        }
    }
}