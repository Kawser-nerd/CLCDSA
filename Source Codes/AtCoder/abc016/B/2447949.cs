using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20180502_pra
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] a = Console.ReadLine().Split(' ');
            int[] b = a.Select(int.Parse).ToArray();

            if (b[0] + b[1] == b[2] && b[0] - b[1] == b[2])
            {
                Console.WriteLine('?');
            }
            else if(b[0] + b[1] == b[2])
            {
                Console.WriteLine('+');
            }
            else if (b[0] - b[1] == b[2])
            {
                Console.WriteLine('-');
            }
            else
            {
                Console.WriteLine('!');
            }

            
        }
    }
}