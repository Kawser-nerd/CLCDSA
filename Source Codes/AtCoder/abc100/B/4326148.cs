using System;
using System.Linq;

namespace B.Ringo_s_Favorite_Numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            var DN = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int D = DN[0];
            int N = DN[1] == 100 ? 101 : DN[1];

            Console.WriteLine(Math.Pow(100, D) * N);
        }
    }
}