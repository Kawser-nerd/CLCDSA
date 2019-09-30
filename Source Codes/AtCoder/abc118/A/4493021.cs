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

            if(B%A==0)
            {
                Console.Write(A + B);
            }
            else
            {
                Console.Write(B - A);
            }

            System.Threading.Thread.Sleep(1000);
        }
    }
}