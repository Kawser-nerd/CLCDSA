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
            int[] inputIntArr = new int[3];
            int i = 0;

            foreach(string n in inputArr)
            {
                inputIntArr[i] = int.Parse(n);
                i += 1;
            }

            Array.Sort(inputIntArr);

            Console.WriteLine(inputIntArr[1]);
        }
    }
}