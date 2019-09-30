using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace R2C
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader reader = Console.In;

            int T = int.Parse(reader.ReadLine());

            for (int t = 0; t < T; t++)
            {
                int R = int.Parse(reader.ReadLine());

                int[,] array = new int[101,101];

                for (int i = 0; i < R; i++)
                {
                    int[] line = reader.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                    int x1 = line[0];
                    int y1 = line[1];
                    int x2 = line[2];
                    int y2 = line[3];
                    for (int j = x1; j <= x2; j++)
                    {
                        for (int k = y1; k <= y2; k++)
                        {
                            array[j, k] = 1;
                        }
                    }
                }

                for (int i = 0; i < 1000; i++)
                {
                    bool flag = true;
                    for (int j = 100; j > 0; j--)
                    {
                        for (int k = 100; k > 0; k--)
                        {
                            if (array[j, k] == 1
                                && array[j - 1, k] == 0
                                && array[j, k - 1] == 0)
                                array[j, k] = 0;

                            if (array[j, k] ==0
                                && array[j - 1, k] == 1
                                && array[j, k - 1] == 1)
                                array[j, k] = 1;

                            if (array[j, k] == 1)
                                flag = false;
                        }
                    }

                    if (flag)
                    {
                        Console.WriteLine("Case #{0}: {1}", t + 1, i+1);
                        break;
                    }
                }


            }
        }
    }
}
