using System;

namespace A___Bichrome_Cells
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var A = int.Parse(Console.ReadLine());

            Console.WriteLine(Math.Pow(N, 2) - A);
        }
    }
}