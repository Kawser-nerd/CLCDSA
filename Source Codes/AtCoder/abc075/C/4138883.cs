using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{

    class Program
    {

        static bool[,] g;
        static bool[] visit;
        static int N;
        static int M;
        
        static void dfs(int u)
        {
            visit[u] = true;

            for(int v = 0; v < N; v++)
            {
                if (g[u, v] && !visit[v]) dfs(v);
            }
            
        }


        
        static void Main(string[] args)
        {
            string[] str1 = Console.ReadLine().Split(' ');
            N = int.Parse(str1[0]);
            M = int.Parse(str1[1]);

            int[] a = new int[M];
            int[] b = new int[M];

            g = new bool[N, N];
            visit = new bool[N];
            
            for(int i = 0; i < M; i++)
            {
                string[] str2 = Console.ReadLine().Split(' ');
                a[i] = int.Parse(str2[0]) - 1;
                b[i] = int.Parse(str2[1]) - 1;

                g[a[i], b[i]] = true;
                g[b[i], a[i]] = true;
            }

            int cnt = 0;

            

            for(int i = 0; i < M; i++)
            {
                g[a[i], b[i]] = false;
                g[b[i], a[i]] = false;

                for(int j = 0; j < N; j++)
                {
                    visit[j] = false;
                }

                dfs(0);

                
                bool bridge = false;
                for(int j = 0; j < N; j++)
                {
                    if (!visit[j])
                    {
                        bridge = true;
                        break;
                    }                  
                }

                if (bridge) cnt++;

                g[a[i], b[i]] = true;
                g[b[i], a[i]] = true;

            }
            
            Console.WriteLine(cnt);

        }
    }
}