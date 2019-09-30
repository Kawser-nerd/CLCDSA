using System;

namespace ABC057_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = long.Parse(Console.ReadLine());

            var min = int.MaxValue;
            for (long i = 1; i * i <= N; i++)
            {
                if (N % i != 0) continue;

                var B = N / i;
                var F = Math.Max(i.ToString().Length, B.ToString().Length);

                min = Math.Min(min, F);
            }

            Console.WriteLine(min);
        }
    }
}