using System;

namespace B___Break_Number
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var n = 1;

            while (n * 2 <= N)
                n *= 2;

            Console.WriteLine(n);
        }
    }
}