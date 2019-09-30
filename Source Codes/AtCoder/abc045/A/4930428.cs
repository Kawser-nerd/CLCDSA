using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp9
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] input = new int[3]; 
            for (int a = 0; a < 3; a++) {
                input[a] = int.Parse(Console.ReadLine());
            }
            int result = (input[0] + input[1]) * input[2]/2;
            Console.WriteLine(result);

            Console.ReadKey();
        }
    }
}