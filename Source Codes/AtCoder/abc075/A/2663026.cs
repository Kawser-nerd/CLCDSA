using System;
using System.Linq;

namespace ABC075_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Console.WriteLine(n[0] == n[1] ? n[2] : n[0] == n[2] ? n[1] : n[0]);
        }
    }
}