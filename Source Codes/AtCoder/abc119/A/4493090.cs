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
            var imp = Console.ReadLine().Split('/');

            if((int.Parse(imp[0])*10000)+(int.Parse(imp[1])*100)+(int.Parse(imp[2]))<=20190430)
            {
                Console.Write("Heisei");
            }
            else
            {
                Console.Write("TBD");
            }

           // System.Threading.Thread.Sleep(1000);
        }
    }
}