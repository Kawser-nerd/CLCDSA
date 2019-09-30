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
            int A = int.Parse(imp[0]);
            int B = int.Parse(imp[1]);
            if (B < A)
            {
                Console.Write(A - 1);
            }
            else
            {
                Console.Write(A);
            }

            System.Threading.Thread.Sleep(1000);
        }
    }
}