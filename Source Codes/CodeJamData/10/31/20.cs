using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ1
{
    class A
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            int T = int.Parse(input);
            for (int t = 1; t <= T; t++)
            {
                input = Console.ReadLine();
                int N = int.Parse(input);
                int[] A = new int[N], B = new int[N];
                for (int i = 0; i < N; i++)
                {
                    input = Console.ReadLine();
                    string[] sp = input.Split(' ');
                    A[i] = int.Parse(sp[0]);
                    B[i] = int.Parse(sp[1]);
                }
                int res = 0;
                for (int i = 0; i < N; i++)
                    for (int j = i + 1; j < N; j++)
                        if ((A[i] - A[j]) * (B[i] - B[j]) < 0)
                            res++;



                Console.WriteLine("Case #{0}: {1}", t,res);
            }
        }
    }
}
