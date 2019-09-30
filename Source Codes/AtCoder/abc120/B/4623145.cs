using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        public static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int A = int.Parse(s[0]);
            int B = int.Parse(s[1]);
            int K = int.Parse(s[2]);
            int res = 0;
            for (int i = 100; i > 0; i--)
            {
                if ((A % i) == 0 && (B % i) == 0)
                {
                    if (K == 1) { res = i; break; }
                    K--;
                }
            }
            Console.WriteLine(res);
        }
    }
}