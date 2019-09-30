using System;
using System.Collections.Generic;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1????
            string input = Console.ReadLine();

            // ?????
            string output = "NO";

            // ????
            int year = int.Parse(input);

            // 400???????????
            if (year % 400 == 0)
            {
                output = "YES";
            }
            // 100???????????????
            else if (year % 100 == 0)
            {
                // ?????
            }
            // 4???????????
            else if (year % 4 == 0)
            {
                output = "YES";
            }

            // ???????
            Console.WriteLine(output);
        }
    }
}