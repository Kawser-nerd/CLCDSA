using System;

namespace c
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = new int[n + 1];

            string[] input = Console.ReadLine().Split();
            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(input[i]);
            }

            a[n] = 0;
            int sum = Sum(a, n);

            for (int i = 0; i < n; i++)
            {
                int before = i == 0 ? 0 : a[i-1];
                int current = a[i];
                int after = a[i + 1];
                int bigger = Math.Max(before, after);
                int smaller = Math.Min(before, after);
                int external = 2 * (Math.Abs(Math.Max(smaller, current) - current) +
                                    Math.Abs(Math.Min(bigger, current) - current));
                Console.WriteLine(sum - external);
            }
        }

        private static int Sum(int[] a, int n)
        {
            int sum = 0;
            int before = 0;
            for (int i = 0; i <= n; i++)
            {
                sum += Math.Abs(a[i] - before);
                before = a[i];
            }

            return sum;
        }
    }
}