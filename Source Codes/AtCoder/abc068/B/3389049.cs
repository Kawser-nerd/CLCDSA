using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = int.Parse(Console.ReadLine());

            if (input == 1) { Console.WriteLine(input);return; }

            var MaxCounter = 0;
            var result = 0;
           

                for (int i = 1; i<= input; i++)
            {
                var counter = 0;
                var x = i;
                while (x % 2 == 0)
                {
                    x = x / 2;
                    counter++;
                }
                if (MaxCounter < counter)
                {
                    MaxCounter = counter;
                    result = i;
                }

            }
            Console.WriteLine(result);
        }

    }
}