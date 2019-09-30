using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine();
            var counter = 0;
            for (int i = 0; i < input.Length; i++)
            {
                counter = counter + int.Parse(input[i].ToString());
            }

            if (int.Parse(input) % counter == 0) Console.WriteLine("Yes");
            else Console.WriteLine("No");
        }
    }
}