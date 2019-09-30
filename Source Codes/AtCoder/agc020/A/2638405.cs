using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practice
{
    class Program
    {
        static void Main(string[] args)
        {
            string szLine = Console.ReadLine();
            string[] szArr = szLine.Split(' ');
            long n = long.Parse(szArr[0]);
            long a = long.Parse(szArr[1]);
            long b = long.Parse(szArr[2]);

            if((b -a) % 2 == 0)
            {
                Console.WriteLine("Alice");
            }
            else
            {
                Console.WriteLine("Borys");
            }
        }
    }
}