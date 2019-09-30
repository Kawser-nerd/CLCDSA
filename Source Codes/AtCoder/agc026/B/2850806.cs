using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC026
{
    class B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            long[,] query = new long[t, 4];
            for (int i = 0; i < t; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                query[i, 0] = long.Parse(input[0]);
                query[i, 1] = long.Parse(input[1]);
                query[i, 2] = long.Parse(input[2]);
                query[i, 3] = long.Parse(input[3]);
            }

            for (int i = 0; i < t; i++)
            {
                if (Eternal(query[i, 0], query[i, 1], query[i, 2], query[i, 3]))
                {
                    Console.WriteLine("Yes");
                }
                else
                {
                    Console.WriteLine("No");
                }
            }
        }

        static bool Eternal(long a, long b, long c, long d)
        {
            if (b > d || b > a) return false;//?????????
            if (b <= c) return true;//??ok?????

            long margin = a % b;
            if (c < margin) return false;
            if (d % b == 0) return true;
            Stack<long> stack = new Stack<long>();
            long delta = d % b;

            while (!stack.Contains(margin))
            {
                stack.Push(margin);
                long cnt = (c - margin) / delta + 1;
                margin += delta * cnt;
                margin %= b;
                if (c < margin) return false;
            }
            return true;
        }
    }
}