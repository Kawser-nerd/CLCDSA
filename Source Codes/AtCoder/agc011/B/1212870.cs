using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC011ColorfulCreatures
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            long[] A = new long[N];
            string[] vals = Console.ReadLine().Split(' ');
            for(int i=0; i < N; i++)
            {
                A[i] = long.Parse(vals[i]);
            }

            Array.Sort(A);
            long[] cum = new long[N];
            cum[0] = A[0];
            for (int i=1; i < N; i++)
            {
                cum[i] = cum[i - 1] + A[i];
            }

            int smallest;
            for(smallest=N-2; smallest >= 0; smallest--)
            {
                if(cum[smallest] * 2  < A[smallest+1])
                {
                    break;
                }
            }

            if(smallest < 0)
            {
                Console.WriteLine(N);
            }
            else
            {
                Console.WriteLine(N - smallest - 1);
            }

        }
    }
}