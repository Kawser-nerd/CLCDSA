using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ASmall
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            int tst = Console.ReadLine().ToInt();
            for (int cas = 1; cas < tst + 1; cas++)
            {
                int[] ar = Console.ReadLine().ToIntArray();
                int N = ar[0];
                int M = ar[1];
                int[,] input = new int[N,M];
                for (int i = 0; i < N; i++)
                {
                    int[] a = Console.ReadLine().ToIntArray();
                    for (int j = 0; j < M; j++)
                    {
                        input[i, j] = a[j];
                    }
                }
                bool[,] edge = new bool[N,N];
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if (i==j)
                        {
                            continue;
                        }
                        bool flag = true;
                        for (int k = 0; k < M; k++)
                        {
                            if (input[i,k]>=input[j,k])
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                        {
                            edge[i, j] = true;
                        }
                    }
                }
                Console.WriteLine("Case #" + cas + ": "+(N-BipartiteMatching.Calc(edge)));

            }
        }


        public class BipartiteMatching
        {
            private static int[] matchl;
            private static int[] matchr;
            private static int L;
            private static int R;
            private static bool[] visited;
            private static bool[,] Edge;

            private static bool dfs(int cur)
            {
                if (visited[cur]) return false;
                visited[cur] = true;
                for (int i = 0; i < R; ++i)
                {
                    if (!Edge[cur, i]) continue;
                    if (matchr[i] == -1 || dfs(matchr[i]))
                    {
                        matchl[cur] = i;
                        matchr[i] = cur;
                        return true;
                    }
                }
                return false;
            }

            public static int Calc(bool[,] edge)
            {
                Edge = edge;
                L = edge.GetUpperBound(0) + 1;
                R = edge.GetUpperBound(1) + 1;
                matchl = new int[L];
                matchr = new int[R];
                for (int i = 0; i < L; ++i)
                {
                    matchl[i] = -1;
                }
                for (int i = 0; i < R; ++i)
                {
                    matchr[i] = -1;
                }
                int ret = 0;
                visited = new bool[L];
                for (int i = 0; i < L; ++i)
                {
                    if (matchl[i] != -1)
                    {
                        continue;
                    }
                    for (int j = 0; j < L; ++j)
                    {
                        visited[j] = false;
                    }
                    if (dfs(i))
                    {
                        ++ret;
                    }
                }
                return ret;
            }
        }

    }


    

    internal static class Extensions
    {
        public static int ToInt(this string s)
        {
            return int.Parse(s);
        }

        public static int[] ToIntArray(this string s)
        {
            var tokens = s.Split(" \t".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            return tokens.Select(ob => ob.ToInt()).ToArray();
        }
    }


    
}
