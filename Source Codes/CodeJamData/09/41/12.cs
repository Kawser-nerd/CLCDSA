using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam2
{
    class Program
    {
        static void Main(string[] args)
        {
            CrazyRows();
        }

        static void CrazyRows()
        {
            int cases = int.Parse(Console.ReadLine());
            for (int rep = 0; rep < cases; rep++)
            {
                int n = int.Parse(Console.ReadLine());
                int[] x = new int[n];
                for (int i = 0; i < n; i++)
                {
                    x[i] = Console.ReadLine().LastIndexOf('1');
                }

                int result = 0;
                for (int i = 0; i < n; i++)
                {
                    if (x[i] > i)
                    {
                        int j;
                        for (j = i + 1; j < n; j++)
                        {
                            if (x[j] <= i)
                            {
                                break;
                            }
                        }
                        int temp = x[j];
                        for (int k = j; k > i; k--)
                        {
                            x[k] = x[k - 1];
                            result++;
                        }
                        x[i] = temp;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", rep + 1, result);
            }
        }
    }
}
