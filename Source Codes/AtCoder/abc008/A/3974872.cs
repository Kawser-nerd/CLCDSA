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

            // S, T?????
            int s = int.Parse(input.Split(' ')[0]);
            int t = int.Parse(input.Split(' ')[1]);

            // ???????
            Console.WriteLine(t - s + 1);
        }
    }
}