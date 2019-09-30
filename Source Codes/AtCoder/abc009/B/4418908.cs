using System;
using System.Linq;

namespace ABC009B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            int[] A = new int[N];
            for(var i = 0; i < N; i++)
            {
                A[i] = int.Parse(Console.ReadLine());
            }

            var As = A.OrderByDescending(a => a).Distinct().ElementAt(1);
            Console.WriteLine(As);
        }
    }
}