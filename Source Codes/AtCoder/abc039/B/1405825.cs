using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp81
{
    class Program
    {
        static void Main(string[] args)
        {
            double  X = double.Parse(Console.ReadLine());

            double N = Math.Pow(X, 0.25);

            Console.WriteLine(N);

        }
    }
}