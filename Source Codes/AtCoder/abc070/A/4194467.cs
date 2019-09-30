using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            for (int i = 0; i < (input.Length / 2); i++)
            {
                if (input[i] != input[input.Length - (i + 1)])
                {
                    Console.WriteLine("No");
                    return;
                }
            }

            Console.Write("Yes");
            return;
        }
    }
}