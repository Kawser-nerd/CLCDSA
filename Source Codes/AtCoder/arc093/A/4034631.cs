using System;
using System.Collections.Generic;
using System.Linq;

namespace ARC093_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var A = new List<int>();
            A.Add(0);
            A.AddRange(Console.ReadLine().Split().Select(int.Parse).ToList());
            A.Add(0);

            N = N + 1;

            var sum = 0;
            for (int i = 0; i < N; i++)
            {
                sum += Math.Abs(A[i] - A[i + 1]);
            }

            for (int i = 1; i < N; i++)
            {
                var result = sum + Math.Abs(A[i - 1] - A[i + 1]) - Math.Abs(A[i - 1] - A[i]) - Math.Abs(A[i] - A[i + 1]);
                Console.WriteLine(result);
            }
        }
    }
}