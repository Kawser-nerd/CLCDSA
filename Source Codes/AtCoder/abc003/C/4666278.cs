using System;
using System.Linq;

namespace BeginnerContest_003_C
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int[] rates = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            int n = input[0];
            int k = input[1];
            if (n != k) { rates = rates.OrderByDescending(x => x).Take(k).ToArray(); }

            Array.Sort(rates);
            double myRate = 0;
            for (int i = 0; i < k; i++) { myRate = (myRate + rates[i]) / 2; }

            Console.WriteLine(myRate);
        }
    }
}