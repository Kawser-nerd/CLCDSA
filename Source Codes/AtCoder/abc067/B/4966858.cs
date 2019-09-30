using System;
using System.Linq;

namespace B___Snake_Toy
{
    class Program
    {
        static void Main(string[] args)
        {
            var N_K = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var ln = Console.ReadLine().Split().Select(int.Parse).OrderByDescending(x => x).ToArray();
            int N = N_K[0], K = N_K[1];

            Console.WriteLine(ln.Where((e, i) => i < K).Sum());
        }
    }
}