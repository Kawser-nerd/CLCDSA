using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] T = new int[N];
            int[] A = new int[N];
            for (int i = 0; i < N; i++)
            {
                string[] vals = Console.ReadLine().Split(' ');
                T[i] = int.Parse(vals[0]);
                A[i] = int.Parse(vals[1]);
            }

            long TT = T[0];
            long AA = A[0];
            for (int i = 1; i < N; i++)
            {
                long t = TT / T[i] + (TT % T[i] == 0 ? 0 : 1);
                long a = AA / A[i] + (AA % A[i] == 0 ? 0 : 1);
                TT = Math.Max(t, a) * T[i];
                AA = Math.Max(t, a) * A[i];
            }
            Console.WriteLine(TT + AA);

        }
    }
}