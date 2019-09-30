using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC005_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            Console.Write("1");
            Console.Write(string.Concat(Enumerable.Repeat(0, n - 1)));
            Console.WriteLine("7");
        }
    }
}