using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            // ????a???
            int a = int.Parse(input);

            // ???????
            Console.WriteLine((a / 2) * (a / 2));
        }
    }
}