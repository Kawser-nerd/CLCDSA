using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC086_A
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] strs = Console.ReadLine().Split(' ');
            int a = int.Parse(strs[0]);
            int b = int.Parse(strs[1]);

            Console.WriteLine(a * b % 2 == 0 ? "Even" : "Odd");
        }
    }
}