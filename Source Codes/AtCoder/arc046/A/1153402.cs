using System;

namespace arc046_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < (n - 1) / 9 + 1; i++)
            {
                Console.Write(n % 9 != 0 ? n % 9 : 9);
            }
            Console.WriteLine();
        }
    }
}