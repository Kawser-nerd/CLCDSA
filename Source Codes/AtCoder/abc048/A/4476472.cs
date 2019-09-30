using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();
            Console.WriteLine("A"+input[1].Substring(0, 1)+"C");
        }  
    }
}