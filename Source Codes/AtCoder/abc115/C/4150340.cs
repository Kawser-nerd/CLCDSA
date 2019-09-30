using System;
using System.Linq;

namespace C_Christmas_Eve
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var raw_input = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int N = raw_input[0];
            int K = raw_input[1];
            var h = Enumerable.Range(0, N)
                .Select(x => Console.ReadLine())
                .Select(int.Parse)
                .ToArray();

            h = h.OrderBy(x => x).ToArray();

            var min = Enumerable.Range(0, N - K + 1)
                .Select(x => h[x + K - 1] - h[x])
                .Min();

            Console.WriteLine(min);
        }
    }
}