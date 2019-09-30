using System;
using System.Linq;

namespace AtTest.C_Challenge
{
    class ABC_031
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] input = Console.ReadLine().Split(' ');
            var array = new int[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = int.Parse(input[i]);
            }

            int tkPoint = -5000;
            for (int i = 0; i < n; i++)
            {
                int maxIndex = 0;
                int maxAoki = -5000;
                int maxTakahashi = -5000;

                for (int j = 0; j < n; j++)
                {
                    if (i == j) continue;

                    int takahashi = 0, aoki = 0;
                    if (j < i)
                    {
                        for (int k = j; k <= i; k++)
                        {
                            if ((k - j + 1) % 2 == 0)
                            {
                                aoki += array[k];
                            }
                            else
                            {
                                takahashi += array[k];
                            }
                        }
                    }
                    else
                    {
                        for (int k = i; k <= j; k++)
                        {
                            if ((k - i + 1) % 2 == 0)
                            {
                                aoki += array[k];
                            }
                            else
                            {
                                takahashi += array[k];
                            }
                        }
                    }

                    if (aoki > maxAoki)
                    {
                        maxAoki = aoki;
                        maxTakahashi = takahashi;
                        maxIndex = j;
                    }
                }

                if (maxTakahashi > tkPoint)
                {
                    tkPoint = maxTakahashi;
                }
            }

            Console.WriteLine(tkPoint);
        }
    }
}