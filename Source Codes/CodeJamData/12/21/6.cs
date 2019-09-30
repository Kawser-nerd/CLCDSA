using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A_Small
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = System.Int32.Parse(Console.ReadLine());
            for (int tc = 1; tc <= T; tc++)
            {
                String[] inputs = Console.ReadLine().Split(' ');
                int N = Int32.Parse(inputs[0]);
                int[] s = new int[N];
                int sum = 0;
                for (int i = 0; i < N; i++)
                {
                    s[i] = Int32.Parse(inputs[i + 1]);
                    sum += s[i];
                }
                double low = 0, high = 999999999,mid=0;
                for (int k = 0; k < 129; k++)
                {
                    mid = (low + high) * .5;
                    //全てをmid以上にするのに必要なポイント数
                    double pts = 0;
                    for (int i = 0; i < N; i++)
                    {
                        double need = Math.Max(0, mid - s[i]);
                        pts += need / sum;
                    }
                    if (pts > 1)
                    {
                        high = mid;
                    }
                    else
                    {
                        low = mid;
                    }
                }

                Console.Write("Case #{0}:", tc);
                for(int i=0;i<N;i++)
                {
                    Console.Write(" {0:F10}", Math.Max(0.0,(mid-s[i])*100.0/sum));
                }
                Console.WriteLine();
            }
        }
    }
}
