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
            var imp = Console.ReadLine().Split(' ');
            string str1 = imp[0];
            string str2 = imp[1];
            string str3 = imp[2];

            Console.Write(str1[0]);
            Console.Write(str2[0]);
            Console.Write(str3[0]);
        }
    }
}