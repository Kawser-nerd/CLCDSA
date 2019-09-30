using System;
using System.Linq;

namespace A.Task_Scheduling_Problem
{
    class Program
    {
        static void Main(string[] args)
        {
            var A = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var res = 0;

            Array.Sort(A);

            for (int i = 1; i < A.Length; i++)
                res += Math.Abs(A[i] - A[i - 1]);

            Console.WriteLine(res);
        }
    }
}