using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ACprac
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] num1 = Console.ReadLine().Split(' ');
            int A = int.Parse(num1[0]);
            int B = int.Parse(num1[1]);
            int C = int.Parse(num1[2]);

            Console.WriteLine((B/A) < C ? (B/A) : C);
        }
    }
}