using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;

namespace ConsoleApp2
{
    class Program {
        static public int dfs(int v) {
            bool all_visited = true;
            for (int i = 0; i < N; i++)
                if (visited[i] == false) {
                    all_visited = false;
                    break;
                }
            if (all_visited) return 1;

            int ret = 0;

            for (int i = 0; i < N; i++) {
                if (isConnect[v, i] == false) continue;
                if (visited[i] == true) continue;

                visited[i] = true;
                ret += dfs(i);
                visited[i] = false;
            }

            return ret;
        }

        static bool[] visited;
        static int N;
        static public bool[,] isConnect;


        static void Main(string[] Args) {
            var tmp = new List<string>(ReadLine().Split(' ')).Select(int.Parse).ToList();
            N = tmp[0]; int M = tmp[1];

            isConnect = new bool[N, N];
            visited = new bool[N];
            for (int i = 0; i < N; i++) visited[i] = false;

            for(int i = 0;i < M; i++) {
                tmp = new List<string>(ReadLine().Split(' ')).Select(int.Parse).ToList();
                isConnect[tmp[0] - 1, tmp[1] - 1] = true;
                isConnect[tmp[1] - 1, tmp[0] - 1] = true;
            }

            visited[0] = true;
            Console.WriteLine(dfs(0));

            ReadLine();
        }
    }
}