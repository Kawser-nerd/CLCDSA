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
            if (int.Parse(imp[0]) + int.Parse(imp[1]) >= int.Parse(imp[2]))
            {
                Console.Write("Yes");
            }
            else
            {
                Console.Write("No");
            }
            //System.Threading.Thread.Sleep(1000);
        }
    }
}