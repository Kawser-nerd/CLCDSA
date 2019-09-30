using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            string output = "Yes";

            if (!input[0].Equals(input[2]))
            {
                output = "No";
            }

            // ???????
            Console.WriteLine(output);
        }
    }
}