using System;
using System.Linq;

namespace ARC089C
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            int[] before = {0, 0, 0};
            for (int i = 0; i < n; i++)
            {
                int[] query = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                int distance = Math.Abs(before[2] - query[2]) + Math.Abs(before[1] - query[1]);
                if (distance > query[0] - before[0] || distance % 2 != (query[0] - before[0]) % 2)
                {
                    Console.WriteLine("No");
                    return;
                }

                before = query;
            }

            Console.WriteLine("Yes");
        }
    }
}