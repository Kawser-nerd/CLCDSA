using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace VirtualAtCorder
{
    class Program
    {



        static void Main(string[] args)
        {
            string[] inputs = Console.ReadLine().Split(' ');

            if ((int.Parse(inputs[0]) % 16 == 0) && (int.Parse(inputs[1]) % 9 == 0))
            {
                Console.WriteLine("16:9");
            }
            else if ((int.Parse(inputs[0]) % 4 == 0) && (int.Parse(inputs[1]) % 3 == 0))
            {
                Console.WriteLine("4:3");
            }

            Console.ReadKey();
        }





    }
}