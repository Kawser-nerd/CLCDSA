using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int i = int.Parse(Console.ReadLine());
            Console.WriteLine(s[i - 1]);

        }
    }
}