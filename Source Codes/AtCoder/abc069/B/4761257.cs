using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            var imp = Console.ReadLine();
            int S = imp.Length;
            char firstS = imp[0];
            char lastS = imp[S-1];
            //Console.Write(lastS);
            Console.Write(firstS);
            Console.Write(S - 2);
            Console.Write(lastS);


            //System.Threading.Thread.Sleep(1000);
        }
    }
}