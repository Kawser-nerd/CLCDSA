using System;

namespace ConsoleApplication15
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();
            string C = input[0];
            string c = input[1];
            if (string.Compare(C, c, true) == 0)
                Console.WriteLine("Yes");
            else
                Console.WriteLine("No");
        }
    }
}