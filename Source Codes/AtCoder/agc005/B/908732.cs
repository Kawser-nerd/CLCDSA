using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            List<int> A = Console.ReadLine().Split().Select(f => int.Parse(f)).ToList();
            long count = 0;
            List<int> sort = Enumerable.Range(0, N).ToList();
            int[] larr = Enumerable.Range(-1, N).ToArray();
            int[] rarr = Enumerable.Range(1, N).ToArray();
            sort.Sort((a, b) => A[b] - A[a]);
            for (int i = 0; i < N; i++)
            {
                var l = larr[sort[i]];
                var r = rarr[sort[i]];
                if (r != N)
                {
                    larr[r] = l;
                    
                }
                if (l != -1)
                {
                    rarr[l] = r;
                }
                count += (long)A[sort[i]] * (long)(sort[i] - l) * (long)(r- sort[i]);
            }
            Console.WriteLine(count);
        }
    }
}