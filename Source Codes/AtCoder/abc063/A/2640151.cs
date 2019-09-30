using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_TestCode
{
    class Program
    {
        static void Main(string[] args)
        {
            int a, b;
            string[] input = Console.ReadLine().Split();
            a = int.Parse(input[0]);
            b = int.Parse(input[1]);

            if (a + b >= 10) Console.WriteLine("error");
            else Console.WriteLine(a+ b);

        }

    }
}