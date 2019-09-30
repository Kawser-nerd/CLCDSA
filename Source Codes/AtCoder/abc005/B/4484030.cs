using System;
using System.Linq;

namespace ABC005B
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] T = new int[N];

            for(var i = 0; i < N; i++)
            {
                T[i] = int.Parse(Console.ReadLine());
            }

            var S = T.OrderBy(t => t).Distinct();

            Console.WriteLine(S.ElementAt(0));
        }
    }
}