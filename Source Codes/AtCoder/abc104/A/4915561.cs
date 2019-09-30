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
            int imp = int.Parse(Console.ReadLine());
            if(imp<1200)
            {
                Console.Write("ABC");
            }
            else if(imp<2800)
            {
                Console.Write("ARC");
            }
            else
            {
                Console.Write("AGC");
            }
            //System.Threading.Thread.Sleep(1000);
        }
    }
}