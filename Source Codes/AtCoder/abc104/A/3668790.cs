using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = int.Parse(Console.ReadLine());
            if (input < 2800)
            {
                if (input < 1200)
                {
                    Console.WriteLine("ABC");
                }
                else
                {
                    Console.WriteLine("ARC");
                }
            }
            else
            {
                Console.WriteLine("AGC");
            }
        }
    }
}