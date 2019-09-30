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
            if (imp%2==0)
            {
                Console.Write(imp);
            }
            else
            {
                Console.Write(2*imp);
            }



          
        }
    }
}