using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class ABC
    {
        static void Main(string[] args)
        {
            long N = int.Parse(Console.ReadLine());

            long m = 0, a = 0, r = 0, c = 0, h = 0;
            for(long i = 0; i < N; i++)
            {
                string S = Console.ReadLine();
                if (S[0] == 'M') m++;
                else if (S[0] == 'A') a++;
                else if (S[0] == 'R') r++;
                else if (S[0] == 'C') c++;
                else if (S[0] == 'H') h++;
            }

            long[] list = { m, a, r, c, h };
            long[] A = { 0, 0, 0, 1, 1, 2, 1, 0, 0, 0 };
            long[] B = { 1, 1, 1, 2, 2, 3, 3, 2, 2, 3 };
            long[] C = { 2, 3, 4, 3, 4, 4, 4, 3, 4, 4 };

            long ans = 0;
            for(long i = 0; i < 10; i++)
            {
                ans += list[A[i]] * list[B[i]] * list[C[i]];
            }

            Console.WriteLine(ans);
            Console.ReadLine();
        }
    }
}