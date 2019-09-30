using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            // ????????
            int no = int.Parse(input);

            // ??????
            string output = string.Empty;

            // 1111???????????
            if(no % 1111 == 0)
            {
                output = "SAME";
            }
            else
            {
                output = "DIFFERENT";
            }

            // ???????
            Console.WriteLine(output);
        }
    }
}