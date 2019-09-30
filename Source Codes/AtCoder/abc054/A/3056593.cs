using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtcoderTemplateForCSharp
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ');

            var a = int.Parse(input[0]);
            var b = int.Parse(input[1]);

            if (a == 1 && b == 1)
            {
                Console.WriteLine("Draw");
            }
            else if (a == 1)
            {
                Console.WriteLine("Alice");
            }
            else if (b == 1)
            {
                Console.WriteLine("Bob");
            }
            else if (a == b)
            {
                Console.WriteLine("Draw");

            }
            else if (a > b)
            {
                Console.WriteLine("Alice");
            }
            else
            {
                Console.WriteLine("Bob");
            }
        }
    }
}