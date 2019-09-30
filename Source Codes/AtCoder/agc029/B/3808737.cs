using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC029B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var A = Console.ReadLine().Split().Select(int.Parse).ToList();

            A = A.OrderBy(x => x).ToList();

            var dic = new Dictionary<int, int>();
            for (int i = 0; i < N; i++)
            {
                if (dic.ContainsKey(A[i])) dic[A[i]]++;
                else dic[A[i]] = 1;
            }

            int[] twoPow = new int[32];
            for (int i = 0; i < 31; i++) twoPow[i] = 1 << i;

            int count = 0;
            for (int j = N - 1; j > 0; j--)
            {
                int last = A[j];

                int pair = -1;
                for (int i = 0; i < 31; i++)
                {
                    if (twoPow[i] > last)
                    {
                        pair = twoPow[i] - last;
                        break;
                    }
                }

                if (!dic.ContainsKey(pair)) continue;

                if (dic[pair] > 0 && dic[last] > 0)
                {
                    if (pair != last)
                    {
                        count++;
                        dic[last]--;
                        dic[pair]--;
                    }
                    else
                    {
                        if (dic[last] >= 2)
                        {
                            count++;
                            dic[last] -= 2;
                        }
                    }
                }
            }

            Console.WriteLine(count);
            Console.ReadKey();
        }
    }
}