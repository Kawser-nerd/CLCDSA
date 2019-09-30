using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Program
    {
        static void Main(string[] args)
        {

            var line1 = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
            var N = line1[0];
            var M = line1[1];
            var a = new long[M];
            var b = new long[M];

            int bridge = 0;

            int[,] dag = new int[N,N];

            for (int i = 0; i < M; i++)
            {
                var line2 = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
                a[i] = line2[0]-1;
                b[i] = line2[1]-1;
                dag[a[i], b[i]] = 1;
                dag[b[i], a[i]] = 1;
            }

            for (int i = 0; i < M; i++)
            {
                bool[] visited = new bool[N];
                dag[a[i], b[i]] = 0;
                dag[b[i], a[i]] = 0;
                DFS(0,visited,dag);

                if (visited.Where(n => n == true).Count() != N)
                {
                    bridge++;
                }

                dag[a[i], b[i]] = 1;
                dag[b[i], a[i]] = 1;
            }
            Console.WriteLine(bridge);
        }

        public static void DFS(int v,bool[] visited,int[,] dag)
        {
            visited[v] = true;

            for (int i = 0; i < visited.Length; i++)
            {
                if (dag[v, i] == 0) continue;
                if (visited[i]) continue;
                DFS(i,visited,dag);
            }

        }

        public static long LowerBound<T>(T[] arr, long start, long end, T value, IComparer<T> comparer)
        {
            long low = start;
            long high = end;
            long mid;
            while (low < high)
            {
                mid = ((high - low) >> 1) + low;
                if (comparer.Compare(arr[mid], value) < 0)
                    low = mid + 1;
                else
                    high = mid;
            }
            return low;
        }

        //????????????
        public static long LowerBound<T>(T[] arr, T value) where T : IComparable
        {
            return LowerBound(arr, 0, arr.Length, value, Comparer<T>.Default);
        }

        public static long UpperBound<T>(T[] arr, long start, long end, T value, IComparer<T> comparer)
        {
            long low = start;
            long high = end;
            long mid;
            while (low < high)
            {
                mid = ((high - low) >> 1) + low;
                if (comparer.Compare(arr[mid], value) <= 0)
                    low = mid + 1;
                else
                    high = mid;
            }
            return low;
        }

        //????????????
        public static long UpperBound<T>(T[] arr, T value)
        {
            return UpperBound(arr, 0, arr.Length, value, Comparer<T>.Default);
        }
    }

}