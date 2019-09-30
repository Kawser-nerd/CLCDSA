using System;

namespace d
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int k = int.Parse(input[1]);

            if (k == 0)
            {
                Console.WriteLine(Math.Pow(n, 2));
                return;
            }

            long count = 0;
            for (int b = k + 1; b <= n; b++)
            {
                int m = 0;
                int countByA = 0;
                while (m * b <= n)
                {
                    if ((m + 1) * b <= n)
                    {
                        countByA += b - k;
                        m++;
                        continue;
                    }

                    countByA += Math.Max(0, n - (m * b + k) + 1);
                    m++;
                }

                count += countByA;
            }

            Console.WriteLine(count);
        }
    }
}