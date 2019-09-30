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
            var imp = Console.ReadLine().Split(' ');
            int A = int.Parse(imp[0]);
            int B = int.Parse(imp[1]);
            int[] whitch = new int[3];
            whitch[0] = A + B;
            whitch[1] = A - B;
            whitch[2] = A * B;

            Array.Sort(whitch);
            Console.Write(whitch[2]);
        }
    }
}