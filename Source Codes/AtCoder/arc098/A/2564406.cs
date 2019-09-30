using System;

namespace ARC098C
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string s = Console.ReadLine();

            int[] dpe = new int[n];
            int[] dpw = new int[n];

            int w = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'W')
                {
                    w++;
                }

                dpw[i] = w;
            }

            int e = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == 'E')
                {
                    e++;
                }

                dpe[i] = e;
            }

            int ans = 10000000;
            for (int i = 0; i < n; i++)
            {
//                Console.Write(i);
//                Console.Write(' ');
//                Console.Write(dpe[i]);
//                Console.Write(' ');
//                Console.WriteLine(dpw[i]);
                int score;

                if (i == 0)
                {
                    score = dpe[i];
                }
                else if (i == n - 1)
                {
                    score = dpw[i];
                }
                else
                {
                    score = dpw[i] + dpe[i] - 1;
                }

                if (ans > score)
                {
                    ans = score;
                }
            }

            Console.WriteLine(ans);
        }
    }
}