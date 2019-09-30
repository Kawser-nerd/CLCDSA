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

            if (input % 2 != 0)
            {
                input++;
            }

            Console.WriteLine(input / 2);
        }
    }
}