using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            int a = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine(n * n - a);
        }
    }
}