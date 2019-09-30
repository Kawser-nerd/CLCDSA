using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_024
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            long n = long.Parse(input[0]);
            int d = int.Parse(input[1]);
            int k = int.Parse(input[2]);
            var lr = new long[d, 2];
            for (int i = 0; i < d; i++)
            {
                input= Console.ReadLine().Split(' ');
                lr[i, 0] = long.Parse(input[0]) - 1;
                lr[i, 1] = long.Parse(input[1]) - 1;
            }
            var st = new int[k, 2];
            for (int i = 0; i < k; i++)
            {
                input = Console.ReadLine().Split(' ');
                st[i, 0] = int.Parse(input[0]) - 1;
                st[i, 1] = int.Parse(input[1]) - 1;
            }

            for(int i = 0; i < k; i++)
            {
                long now = st[i, 0];
                bool minus = st[i, 1] - st[i, 0] < 0;
                for(int j = 0; j < d; j++)
                {
                    if (now < lr[j, 0] || now > lr[j, 1]) continue;

                    if (st[i, 1] >= lr[j, 0] && st[i, 1] <= lr[j, 1])
                    {
                        Console.WriteLine(j + 1);
                        break;
                    }
                    else
                    {
                        now = minus ? lr[j, 0] : lr[j, 1];
                    }
                }
            }
        }
    }
}