using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] ar = ReadLine().Split(' ').Select(_ => int.Parse(_)).ToArray();
            int N = ar[0];
            int K = ar[1];
            int past = 0;
            int cnt = 0;
            int res = 0;
            for (int i = 0; i < N; i++)
            {
                int A = int.Parse(ReadLine());
                if(past<A)
                {
                    cnt++;
                }
                else
                {
                    if (K <= cnt)
                    {
                        res += 1 + (cnt - K);
                    }
                    cnt = 1;
                }
                past = A;
            }
            if (K <= cnt)
            {
                res += 1 + (cnt - K);
            }
            WriteLine(res);
            ReadLine();
        }
    }
    class Item
    {
        public float Max { get; set; }
        public float Min { get; set; }
    }
}