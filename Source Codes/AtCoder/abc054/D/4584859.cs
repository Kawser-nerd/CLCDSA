using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_D
{
    class D054
    {
        public static void Main(string[] args)
        {
            int[] h = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int N = h[0], Ma = h[1], Mb = h[2];

            List<int[]> list = new List<int[]>();
            int sumA = 0, sumB = 0;
            for(int i = 0; i < N; i++)
            {
                int[] p = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                list.Add(p);
                int a = p[0], b = p[1], c = p[2];
                sumA += a;sumB += b;
            }

            int[,] price = new int[sumA + 1, sumB + 1];

            for(int i = 0; i <= sumA; i++)
            {
                for(int j = 0; j <= sumB; j++)
                {
                    price[i, j] = int.MaxValue;
                }
            }
            price[0, 0] = 0;

            foreach (int[] p in list)
            {
                int a = p[0], b = p[1], c = p[2];
                for (int i = sumA; i >= a; i--)
                {
                    for (int j = sumB; j >= b; j--)
                    {
                        if (price[i - a, j - b] != int.MaxValue)
                            price[i, j] = Math.Min(price[i, j], price[i - a, j - b] + c);
                    }
                }
            }

            int min = int.MaxValue;
            for(int i = 1; i <= sumA; i++)
            {
                for(int j = 1; j <= sumB; j++)
                {
                    if (i * Mb == j * Ma)
                    {
                        if (price[i, j] < min) min = price[i, j];
                    }
                }
            }
            if (min == int.MaxValue) min = -1;
            Console.WriteLine(min);
        }

    }
}