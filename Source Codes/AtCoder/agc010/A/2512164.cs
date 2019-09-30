using System;
using System.Linq;

namespace AGC010_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var A = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Console.WriteLine(A.Where(a => a % 2 == 1).Count() % 2 == 0 ? "YES" : "NO");
        }
    }
}