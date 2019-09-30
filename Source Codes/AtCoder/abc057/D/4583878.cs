using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_D
{
    class D057
    {
        static void Main(string[] args)
        {
            int[] h = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int N = h[0], A = h[1], B = h[2];
            List<long> v = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToList();
            v = v.OrderByDescending(x => x).ToList();
            double ave = v.Take(A).Average();
            long mval = v[A - 1];
            int cnt = v.Count(x => x == mval);

            if (v[0] == mval) //A+1????????????A????????????
            {
                long count = 0;
                for(int i = A; i <= B; i++)
                {
                    if (cnt < i) break;
                    count += CombinationPascal(cnt, i);
                }
                Console.WriteLine(mval);
                Console.WriteLine(count);
            }
            else
            {
                int numC = v.Take(A).Count(x => x == mval);
                long r = CombinationPascal(cnt, numC);
                Console.WriteLine(ave.ToString("F8"));
                Console.WriteLine(r);
            }

        }

        //????????(O(n^2)
        public static List<long[]> PascalTriangle(int n)
        {
            List<long[]> list = new List<long[]>();
            for (int i = 0; i <= n; i++)
            {
                long[] arr = new long[i + 1];

                arr[0] = 1; arr[i] = 1;
                if (i >= 2)
                {
                    long[] arrBfr = list[i - 1];
                    for (int j = 1; j < arr.Length - 1; j++)
                    {
                        arr[j] = arrBfr[j - 1] + arrBfr[j];
                    }
                }
                list.Add(arr);
            }
            return list;
        }

        public static long CombinationPascal(int n, int r)
        {
            return PascalTriangle(n)[n][r];
        }


    }
}