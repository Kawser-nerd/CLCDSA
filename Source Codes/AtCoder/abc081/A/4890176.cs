using System;
using System.Linq;

namespace abc081_a
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Console.ReadLine().Count(c => c == '1'));
        }
    }
}