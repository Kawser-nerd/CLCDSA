using System;

namespace B___Around_Square
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());

            Console.WriteLine(Math.Pow((int)Math.Sqrt(N), 2));
        }
    }
}