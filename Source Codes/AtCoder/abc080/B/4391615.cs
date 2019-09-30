using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            var z = 0;
            for (int i = 0; i < s.Length; i++)
            {
                z += int.Parse(s[i].ToString());
            }
            if (long.Parse(s) % z == 0)
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}