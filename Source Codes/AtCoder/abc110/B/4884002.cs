using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace AtCoderABC086
{
    class Program
    {
        public static void Main(string[] args)
        {
            int[] a = Console.ReadLine().Split(' ').Select(q => int.Parse(q)).ToArray();
            int N = a[0], M = a[1], X = a[2], Y = a[3];
            int[] x = Console.ReadLine().Split(' ').Select(q => int.Parse(q)).ToArray();
            int[] y = Console.ReadLine().Split(' ').Select(q => int.Parse(q)).ToArray();

            bool flag = false;
            for (int Z = X + 1; Z <= Y; Z++)
            {
                bool temp = true;
                for (int i = 0; i < N; i++)
                {
                    if (x[i] < Z) continue;
                    temp = false;
                }
                for (int i = 0; i < M; i++)
                {
                    if (y[i] >= Z) continue;
                    temp = false;
                }
                if (temp)
                {
                    flag = true;
                    break;
                }
            }
            Console.WriteLine((flag)? "No War": "War");
        }
    }
}