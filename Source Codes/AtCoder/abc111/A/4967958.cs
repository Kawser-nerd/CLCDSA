using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = Console.ReadLine();
            var c = n.ToCharArray();

            for (int i = 0; i < c.Length; i++)
            {
                if (c[i] == '1')
                {
                    c[i] = '9';
                }
                else
                {
                    c[i] = '1';
                }
            }

            Console.WriteLine(new string(c));
        }
    }
}