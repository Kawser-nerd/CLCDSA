using System;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] yakusuu = new int[n + 1];
            for (int i = 2; i <= n; i++)
            {
                int x = i;
                for (int j = 2; j <= n; j++)
                {
                    int k = 0;
                    if (x % j == 0)
                    {
                        for (k = 0; x % j == 0; x /= j) k++;
                    }
                    yakusuu[j] += k;
                }
            }
            long ret = 1;
            for (int i = 2; i <= n; i++)
            {
                ret *= yakusuu[i] + 1;
                ret %= 1000000007;
            }
            Console.WriteLine(ret);
        }
    }
}