using System;
using System.Collections.Generic;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            string n = Console.ReadLine();
            switch (n)
            {
                case "1":
                    Console.WriteLine("Hello World");
                    break;
                case "2":
                    int a = int.Parse(Console.ReadLine());
                    int b = int.Parse(Console.ReadLine());
                    int sum = a + b;
                    Console.Write(sum);
                    break;
            }
        }
    }
}