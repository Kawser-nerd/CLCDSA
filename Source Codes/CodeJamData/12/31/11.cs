using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace _1c_A_diamond
{
    class Program
    {
        const int NMAX = 1010;
        static bool Solve()
        {
            // in
            int N = int.Parse(Console.ReadLine());
            List<short>[] G = new List<short>[NMAX];
            for (short i = 0; i <= N; ++i)
                G[i] = new List<short>();

            List<short> Z = new List<short>();
            for (short i = 1; i <= N; ++i)
            {
                string[] sa = Console.ReadLine().Split(' ');
                int M = int.Parse(sa[0]);
                for (int j = 1; j <= M; ++j)
                {
                    short k = short.Parse(sa[j]);
                    G[k].Add(i); // odwrócona krawędź k-->i
                }
                if (M == 0)
                    Z.Add(i);
            }

            // solve
            foreach (short z in Z)
            {
                Queue<short> Q = new Queue<short>();
                bool[] visited = new bool[NMAX];
                Q.Enqueue(z); visited[z] = true;
                while (Q.Count() > 0)
                {
                    short v = Q.Dequeue();
                    //if (visited[v]) return true;
                    foreach (short k in G[v])
                    {
                        if (visited[k]) return true;
                        Q.Enqueue(k);
                        visited[k] = true;
                    }
                }
            }
            return false;
        }
        static void Main(string[] args)
        {
            int nCases = int.Parse(Console.ReadLine());
            for (int c = 1; c <= nCases; ++c)
            {
                Console.WriteLine("Case #{0}: {1}", c, Solve()?"Yes":"No");
            }
            //Console.ReadKey();
        }
    }
}

/*
3
3
1 2
1 3
0
5
2 2 3
1 4
1 5
1 5
0
3
2 2 3
1 3
0
*/
