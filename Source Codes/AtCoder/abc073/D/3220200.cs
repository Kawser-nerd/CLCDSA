using System;
using System.Collections;

namespace ABC073D
{

    class Program
    {
        static int INFTY = 0x30000000;

        static void Main(string[] args)
        {
            int N, M, R;
            int[,] cost;
            int[] r;
            string[] str = Console.ReadLine().Split(' ');
            N = int.Parse(str[0]);
            M = int.Parse(str[1]);
            R = int.Parse(str[2]);
            cost = new int[N, N];
            r = new int[R];

            for (int i = 0; i < N; ++i)
            {
                cost[i, i] = 0;
                for (int j = i + 1; j < N; ++j)
                {
                    cost[i, j] = cost[j, i] = INFTY;
                }
            }

            str = Console.ReadLine().Split(' ');
            for (int i = 0; i < R; ++i)
            {
                r[i] = int.Parse(str[i]) - 1;
            }

            for (int k = 0; k < M; ++k)
            {
                int i, j;
                str = Console.ReadLine().Split(' ');
                i = int.Parse(str[0]) - 1;
                j = int.Parse(str[1]) - 1;
                cost[i, j] = cost[j, i] = int.Parse(str[2]);
            }

            // Set connected costs
            for (int k = 0; k < N; ++k)
            {
                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < N; ++j)
                    {
                        int wc = cost[i, k] + cost[k, j];
                        if (wc < cost[i, j])
                        {
                            cost[i, j] = wc;
                        }
                    }
                }
            }

            // Salesman's Problem
            /*
            int[,] costR = new int[R, R];
            int ir = 0;
            for (int i = 0; i < N && ir < R; i++)
            {
                bool hit = false;
                int jr = 0;
                for (int j = 0; j < N && jr < R; j++)
                {
                    if (i == r[ir] && j == r[jr])
                    {
                        hit = true;
                        costR[ir, jr] = cost[i, j];
                        jr++;
                    }
                }

                if (hit)
                {
                    ir++;
                }

            }
            */

            Stack stack = new Stack(R);
            int pushNum = 0;
            int sum = 0;
            int res = INFTY;

            do
            {
                if (pushNum >= R)
                {
                    pushNum = (int)stack.Pop();
                    if (stack.Count > 0)
                    {
                        sum -= cost[r[(int)stack.Peek()], r[pushNum]];
                    }
                    pushNum++;
                }
                else if (stack.Count == R)
                {
                    if (res > sum)
                    {
                        res = sum;
                    }
                    pushNum = (int)stack.Pop();
                    sum -= cost[r[(int)stack.Peek()], r[pushNum]];
                    pushNum++;
                }
                else if (!stack.Contains(pushNum))
                {
                    if (stack.Count > 0)
                    {
                        sum += cost[r[(int)stack.Peek()], r[pushNum]];
                    }
                    stack.Push(pushNum);
                    pushNum = 0;
                }
                else
                {
                    pushNum++;
                }

            } while (stack.Count > 0 || pushNum < R);


            Console.WriteLine(res);
        }

    }
}