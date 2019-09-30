using System;
using System.Linq;

namespace A___K_City
{
    class Program
    {
        static void Main(string[] args)
        {
            var n_m = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int n = n_m[0], m = n_m[1];

            Console.WriteLine((n - 1) * (m - 1));
        }
    }
}