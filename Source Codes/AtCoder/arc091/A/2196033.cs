using System;

namespace c
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            long n = int.Parse(input[0]);
            long m = int.Parse(input[1]);

            long a = Math.Max(n, m);
            long b = Math.Min(n, m);

            if (a == 1)
            {
                Console.WriteLine(1);
                return;
            }

            if (b == 1)
            {
                Console.WriteLine(a - 2);
                return;
            }
            
            Console.WriteLine((a - 2) * (b - 2));
        }
    }
}