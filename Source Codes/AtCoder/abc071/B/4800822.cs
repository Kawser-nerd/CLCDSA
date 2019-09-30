using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC071_B();
        }

        static void ABC071_B()
        {
            var S = Console.ReadLine();
            var list = new int[123];
            foreach (var s in S)
                list[s] = 1;

            for (var i = 97; i < list.Length; i++)
            {
                if (list[i] == 0)
                {
                    Console.WriteLine((char)i);
                    return;
                }
            }
            Console.WriteLine("None");
        }
    }
}