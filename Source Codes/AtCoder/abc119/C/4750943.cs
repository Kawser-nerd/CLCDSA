using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp
{
    class Program
    {
        static int N, A, B, C;
        static List<int> mp = new List<int>();
        static List<int> ls;

        static void Main(string[] args)
        {
            var str = Console.ReadLine();
            var strs = str.Split(' ');
            N = int.Parse(strs[0]);
            A = int.Parse(strs[1]);
            B = int.Parse(strs[2]);
            C = int.Parse(strs[3]);

            ls = new List<int>(N);
            for (int i = 0; i < N; i++)
            {
                ls.Add(int.Parse(Console.ReadLine()));
            }

            var list = new List<int>();
            for (int i = 0; i < N; i++)
            {
                list.Add(0);
            }

            Dfs(0, list);

            Console.WriteLine(mp.Min());
        }

        static void Dfs(int depth, List<int> list)
        {
            if (depth == N)
            {
                Calc(list);
                return;
            }

            for (int i = 0; i < 4; i++)
            {
                list[depth] = i;
                Dfs(depth + 1, list);
            }
        }

        static void Calc(List<int> list)
        {
            if (!list.Contains(0) || !list.Contains(1) || !list.Contains(2))
            {
                return;
            }

            var lA = 0;
            var lB = 0;
            var lC = 0;

            var synthesis = 0;
            for (int i = 0; i < N; i++)
            {
                switch (list[i])
                {
                    case 0:
                        if (lA != 0)
                        {
                            synthesis += 10;
                        }
                        lA += ls[i];
                        break;
                    case 1:
                        if (lB != 0)
                        {
                            synthesis += 10;
                        }
                        lB += ls[i];
                        break;
                    case 2:
                        if (lC != 0)
                        {
                            synthesis += 10;
                        }
                        lC += ls[i];
                        break;
                    default:
                        break;
                }
            }

            mp.Add(Math.Abs(lA - A) + Math.Abs(lB - B) + Math.Abs(lC - C) + synthesis);
        }
    }
}