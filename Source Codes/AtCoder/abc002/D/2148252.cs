using System;
using System.Collections.Generic;

namespace abc002_4
{
    class program
    {
        static void Main(string[] args)
        {
            ChangeLocalDebugInput();

            string[] line1 = Console.ReadLine().Split(' ');
            int N = int.Parse(line1[0]);
            int M = int.Parse(line1[1]);

            bool[,] relation = new bool[N, N];

            if (M == 0)
            {
                Console.WriteLine("1");
                return;
            }
            

            for (int i = 0; i < M; i++)
            {
                string[] line = Console.ReadLine().Split(' ');
                int a = int.Parse(line[0]) - 1;
                int b = int.Parse(line[1]) - 1;
                relation[a,b] = true;
            }

            int max = 0;
            for (int i = 0; i < Math.Pow(2, N); i++)
            {
                int sum = 0;
                for (int j = 0; j < N; j++)
                {
                    for (int k = j+1; k < N; k++)
                    {
                        if(relation[j,k])
                        {
                            int t = (int) (Math.Pow(2, j) + Math.Pow(2, k));
                            if (BitCount(t&i) == 2)
                            {
                                sum++;
                            }
                        }
                    }
                }
                int c = BitCount(i);
                if (sum == c * (c - 1) / 2)
                {
                    if (c >= max)
                    {
                        max = c;
                    }
                }
            }
            
            Console.WriteLine(max);
        }


        [System.Diagnostics.Conditional("LOCAL_DEBUG")]
        static void ChangeLocalDebugInput()
        {
            Console.SetIn(new System.IO.StreamReader("../../stdin.txt"));
        }

        static int BitCount(int a)
        {
            int c = 0;
            for (int mask = 1; mask != 0; mask = mask << 1 )
            {
                if ( (a & mask) != 0)
                {
                    c++;
                }
            }
            return c;
        }
    }
}