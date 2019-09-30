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
            int a = int.Parse(imp[0]);
            int b = int.Parse(imp[1]);
            int c = int.Parse(imp[2]);

            if(a+b==c)
            {
                Console.Write("Yes");
            }
            else if(a+c==b)
            {
                Console.Write("Yes");
            }
            else if(b+c==a)
            {
                Console.Write("Yes");
            }
            else
            {
                Console.Write("No");
            }
            System.Threading.Thread.Sleep(1000);
        }
    }
}