using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamCandySplitting
{
    class Program
    {
        static void Main(string[] args)
        {
            string line = Console.ReadLine();
            int testCount = int.Parse(line);
            for (int testNumber = 1; testNumber <= testCount; testNumber++)
            {
                int candyCount = int.Parse(Console.ReadLine());
                var candies = Console.ReadLine().Split();
                int min = int.MaxValue;
                int sum = 0;
                int mask = 0;
                foreach (var item in candies)
                {
                    int v = int.Parse(item);
                    mask ^= v;
                    if (v < min)
                        min = v;
                    sum += v;
                }

                Console.Write("Case #{0}: ", testNumber);
                Console.Write(mask == 0 ? (sum - min).ToString() : "NO");
                Console.WriteLine();
            }
        }
    }
}
