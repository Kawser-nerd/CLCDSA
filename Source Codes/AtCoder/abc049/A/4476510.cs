using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            if (input=="a"|| input == "i"|| input == "u" || input == "e" || input == "o" )
            {
                Console.WriteLine("vowel");
            }
            else
            {
                Console.WriteLine("consonant");
            }
        }  
    }
}