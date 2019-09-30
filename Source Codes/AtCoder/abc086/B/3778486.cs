using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Jpken_Kyogi1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] inputs = Console.ReadLine().Split(' ');

            int a = int.Parse(inputs[0]);
            int b = int.Parse(inputs[1]);
            int union_number;
            if (b == 100)
                union_number = a * 1000 + b;
            else if (b >= 10)
                union_number = a * 100 + b;
            else
                union_number = a * 10 + b;

            int base_number = 0;
            while (base_number <= 100100)
            {
                base_number++;
                if (base_number * base_number == union_number)
                {
                    Console.WriteLine("Yes");
                    break;
                }
                else if (base_number == 100100)
                {
                    Console.WriteLine("No");
                }

            }
        }
    }
}