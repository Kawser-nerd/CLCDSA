using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            var raw_inputs = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            var A = raw_inputs[0];
            var B = raw_inputs[1];

            if(B % A == 0){
                Console.WriteLine(A + B);
            }
            else
            {
                Console.WriteLine(B - A);
            }
        }
    }
}