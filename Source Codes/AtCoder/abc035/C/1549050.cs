using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int N = x[0];
            int Q = x[1];
            //list
            //int[] L = new int[Q];
            //int[] R = new int[Q];

            int[] y = new int[2];
            int[] ans = new int[N];

            for (int i = 0; i < Q; i++)
            {
                y = Console.ReadLine().Split().Select(int.Parse).ToArray();
                int L = y[0];
                int R = y[1];
                ans[L - 1]++;
                if (R < N) ans[R]--;

                //for (int j = 0; j < N; j++)
                //{
                //    if (j >= y[0]-1) ans[j] += 1;
                //    if (j > y[1]-1) ans[j] -= 1;
                //}
            }
            Console.Write(ans[0] % 2);
            for (int i = 1; i < N; i++)
            {
                ans[i] += ans[i - 1];
                Console.Write(ans[i] % 2);
            }
            Console.WriteLine();
        }
    }
}