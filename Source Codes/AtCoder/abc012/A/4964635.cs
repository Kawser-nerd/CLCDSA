using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;

namespace ConsoleApp112 {
    class Program {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] inputArr = input.Split(' ');

            Console.WriteLine("{0} {1}", inputArr[1], inputArr[0]);

        }
    }
}