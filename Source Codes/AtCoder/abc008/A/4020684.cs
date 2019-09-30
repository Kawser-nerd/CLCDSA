using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {

            string[] array = Console.ReadLine().Split(' ');
            int X = int.Parse(array[0]);
            int Y = int.Parse(array[1]);
            Console.WriteLine(Y-X+1);
            Console.ReadKey();
        }
    }
}