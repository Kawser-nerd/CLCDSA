using System;
using System.Collections.Generic;

namespace ABC
{
    class Program
    {

        static void Main(string[] args)
        {
            string[] inp = Console.ReadLine().Split(' ');

            int N = int.Parse(inp[0]);
            int M = int.Parse(inp[1]);

            int[,] xy = new int[N + 1, N + 1];
            
            for (int i=0; i<M; ++i)
            {
                inp = Console.ReadLine().Split(' ');
                xy[int.Parse(inp[0]), int.Parse(inp[1])] = 1;
            }
            
            List<int> t = new List<int>();
            for (int i=1; i<=N; ++i)
            {
                t.Add(i);
            }

            int maxcount = Search(xy, t, 1);
            
            Console.WriteLine(maxcount);

            //Console.ReadKey();
            return;
        }


        static int Search(int[,] xy , List<int> a, int depth)
        {
            int maxcount = depth;
            for(int i=0; i<a.Count; ++i)
            {
                List<int> t = new List<int>();
                for (int j = i + 1; j < a.Count; ++j)
                {
                    if (xy[a[i], a[j]] == 1)
                    {
                        t.Add(a[j]);
                    }
                }
                if (t.Count == 0)
                {
                    continue;
                }
                int d = Search(xy, t, depth + 1);
                if ( d > maxcount )
                {
                    maxcount = d;
                }
            }

            return maxcount;
        }
    }
}