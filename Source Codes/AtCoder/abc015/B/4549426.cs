using System;
using System.Linq;

namespace ABC015B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var A = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int counter = 0; int total = 0;

            for(var i = 0; i < A.Length; i++)
            {
                if(A[i] != 0)
                {
                    counter++;
                    total += A[i];
                }
            }

            double answer = (double)total / (double)counter;
            
            Console.WriteLine(Math.Ceiling(answer));
        }
    }
}