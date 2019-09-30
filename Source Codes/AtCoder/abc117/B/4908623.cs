using System;
using System.Linq;


namespace AtC
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var L = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int max = int.MinValue, sum = 0;
            for (var i = 0; i < L.Length; i++)
            {
                if (L[i] > max) max = L[i];
                sum += L[i];
            }

            Console.WriteLine(sum - max > max ? "Yes" : "No");
        }
    }
}