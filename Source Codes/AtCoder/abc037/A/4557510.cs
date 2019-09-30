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
            int C = int.Parse(imp[2]);

            if (A <= B)
            {
                Console.Write(C / A);
            }
            else
            {
                Console.Write(C / B);
            }

           // System.Threading.Thread.Sleep(1000);
        }
    }
}