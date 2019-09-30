using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_005
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var d = new int[n, n];
            string[] input;
            for (int i = 0; i < n; i++)
            {
                input = Console.ReadLine().Split(' ');
                for(int j = 0; j < n; j++)
                {
                    d[i, j] = int.Parse(input[j]);
                }
            }
            int q= int.Parse(Console.ReadLine());
            var p = new int[q];
            for(int i = 0; i < q; i++)
            {
                p[i] = int.Parse(Console.ReadLine());
            }

            //0????????????????
            var squareDel = new int[n, n];
            squareDel[0, 0] = d[0, 0];
            for(int i = 1; i < n; i++)
            {
                squareDel[i, 0] = squareDel[i - 1, 0] + d[i, 0];
                squareDel[0, i] = squareDel[0, i - 1] + d[0, i];
            }
            for(int i = 1; i < n; i++)
            {
                for(int j = 1; j < n; j++)
                {
                    squareDel[i, j] = d[i, j]
                        + squareDel[i - 1, j] + squareDel[i, j - 1]
                        - squareDel[i - 1, j - 1];
                }
            }

            var cntDel = new int[n * n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 1; k <= n - i; k++)
                    {
                        for (int l = 1; l <= n - j; l++)
                        {
                            int val = squareDel[i + k - 1, j + l - 1];
                            if (i > 0)
                            {
                                val -= squareDel[i - 1, j + l - 1];
                            }
                            if (j > 0)
                            {
                                val -= squareDel[i + k - 1, j - 1];
                            }
                            if (i > 0 && j > 0)
                            {
                                val += squareDel[i - 1, j - 1];
                            }
                            int square = k * l;
                            if (cntDel[square - 1] < val)
                            {
                                cntDel[square - 1] = val;
                            }
                        }
                    }
                }
            }

            for (int i = 1; i < n * n; i++)
            {
                if (cntDel[i] < cntDel[i - 1])
                {
                    cntDel[i] = cntDel[i - 1];
                }
            }


            for(int i = 0; i < q; i++)
            {
                Console.WriteLine(cntDel[p[i] - 1]);
            }
        }
    }
}