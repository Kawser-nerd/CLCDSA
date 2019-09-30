using System;

namespace B___Addition_and_Multiplication
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var K = int.Parse(Console.ReadLine());
            var res = 1;

            for (int i = 0; i < N; i++)
                res = Math.Min(res * 2, res + K);

            Console.WriteLine(res);
        }
    }
}