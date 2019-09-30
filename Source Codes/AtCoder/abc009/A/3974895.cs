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

            // N?????
            double n = double.Parse(input);

            // ???????
            Console.WriteLine((int)Math.Floor(n / 2.0 + 0.5));
        }
    }
}