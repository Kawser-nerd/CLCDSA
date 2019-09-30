using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');
            int a = int.Parse(str[0]);
            int b = int.Parse(str[1]);

            if (a <= 8 && b <= 8)
            {
                Console.WriteLine("Yay!");
            }
            else
            {
                Console.WriteLine(":(");
            }

        }
    }
}