using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A.Discount_Fare
{
    class Program
    {
        static void Main(string[] args)
        {
            var num = Console.ReadLine().Split(' ').ToArray();
            var num_X = int.Parse(num[0]);
            var num_Y = int.Parse(num[1]);

            var sum = num_X + num_Y / 2;

            Console.WriteLine(sum);
            
        }
    }
}