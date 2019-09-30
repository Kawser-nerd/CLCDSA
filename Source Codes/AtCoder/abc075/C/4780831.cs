using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC075_C();
        }
        

        static void ABC075_C()
        {
            var NM = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var N = NM[0];
            var M = NM[1];
            var graph = new int[51, 51];
            var tmp = new int[51];
            var abInputs = new List<List<int>>();
            var hashi = 0;

            for (var m = 0; m < M; m++)
            {
                var ab = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                abInputs.Add(ab);
                graph[ab[0], ab[1]] = 1;
                graph[ab[1], ab[0]] = 1;
            }

            Action<int> dfs = null;
            dfs = x =>
            {
                if (tmp[x] == 1) return;
                tmp[x] = 1;
                for (var i = 1; i <= M; i++)
                {
                    if (graph[x, i] == 1)
                        dfs(i);
                }
            };

            foreach(var ab in abInputs)
            {
                for (var i = 0; i < tmp.Length; i++) tmp[i] = 0;

                graph[ab[0], ab[1]] = 0;
                graph[ab[1], ab[0]] = 0;

                dfs(1);

                if (tmp.Count(x => x == 1) < N)
                    hashi++;

                graph[ab[0], ab[1]] = 1;
                graph[ab[1], ab[0]] = 1;
            }
            Console.WriteLine(hashi);
        }
    }
}