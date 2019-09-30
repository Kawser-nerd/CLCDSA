using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static double P;
        static void Main(string[] args)
        {
            P = double.Parse(Console.ReadLine());
            double x = 1.5 * Math.Log(P * Math.Log(2.0) / 1.5, 2.0);
            if (x > 0)
            {
                Console.WriteLine(x + P * Math.Pow(2.0, -x / 1.5));
            }else
            {
                Console.WriteLine(P);
            }
        }
    }
}