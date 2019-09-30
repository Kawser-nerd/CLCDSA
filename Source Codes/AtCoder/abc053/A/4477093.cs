using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int Number = int.Parse(Console.ReadLine());
            if (Number<1200)
            {
                Console.WriteLine("ABC");
            }
            else
            {
                Console.WriteLine("ARC");
            }
        }  
    }
}