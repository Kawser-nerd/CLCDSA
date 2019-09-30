using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC022B
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

            IEnumerable<int> setA = A.Distinct();

            var len = setA.ToArray().Length;

            Console.WriteLine(N - len);
        }
    }
}