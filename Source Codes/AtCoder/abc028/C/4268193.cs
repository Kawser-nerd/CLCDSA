using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine();

            int[] values = Array.ConvertAll(input.Split(' '), int.Parse);

            int candidate1 = values[1] + values[2] + values[4]; //BCE
            int candidate2 = values[0] + values[3] + values[4]; //ADE

            Console.Write(Math.Max(candidate1, candidate2));
            Console.WriteLine();

        }
    }
}