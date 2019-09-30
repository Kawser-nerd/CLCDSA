using System;
using System.Collections.Generic;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());

            for (int c = 1; c <= t; c++)
            {
                int n = int.Parse(Console.ReadLine());
                int[] vals = new int[n];

                for (int i = 0; i < n; i++)
                {
                    string line = Console.ReadLine();
                    int val = 0;
                    for (int j = 0; j < line.Length; j++)
                    {
                        if (line[j] == '1') val = j + 1;
                    }
                    vals[i] = val;
                }

                int cont = 0;

                for (int i = 0; i < n; i++)
                {
                    int col = i + 1;
                    if (vals[i] > col)
                    {
                        //Console.WriteLine("Vals[i] = {0} col = {1}", vals[i], col);
                        int k = -1;
                        for (int j = i + 1; j < n; j++)
                        {
                            if (vals[j] <= col)
                            {
                                k = j;
                                break;
                            }
                        }
                        if (k < 0) Console.WriteLine("Error: k < 0");
                        for (int j = k; j > i; j--)
                        {
                            int temp = vals[j];
                            vals[j] = vals[j - 1];
                            vals[j - 1] = temp;
                            cont++;
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1}", c, cont);
            }
        }
    }
}
