using System;
using System.Collections.Generic;
using System.Linq;
namespace CsProgramSpace
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> list = RLl();
            Console.WriteLine((double)list[0] / list[1]);
        }
        private static List<int> RLl() => Console.ReadLine().Split(' ').Select(_ => int.Parse(_)).ToList();
    }
}