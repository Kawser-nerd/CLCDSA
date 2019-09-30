// ABC 073 D joisino's travel

using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static int N;
    static int M;
    static int R;
    static int[] r;
    static int[,] Edge; // Edge[i,j] : ??i+1,j+1??????(????1e9)
    static int[,] Dis; // Dis[i,j] : ??i+1,j+1??????

    static void Main()
    {
        /* ?????????????? */
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        N = input[0];
        M = input[1];
        R = input[2];
        r = Console.ReadLine().Split().Select(s => int.Parse(s) - 1).ToArray();
        Edge = new int[N, N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                Edge[i, j] = (int)1e9;
        for (int i = 0; i < M; i++)
        {
            input = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int a = input[0] - 1;
            int b = input[1] - 1;
            int c = input[2];
            Edge[a, b] = c;
            Edge[b, a] = c;
        }
        Dis = new int[N, N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                Dis[i, j] = Edge[i, j];
        for (int i = 0; i < N; i++)
            Dis[i, i] = 0;

        /* Warshall-Floyd????????????????? */
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if (Dis[i, j] > Dis[i, k] + Dis[k, j])
                        Dis[i, j] = Dis[i, k] + Dis[k, j];

        /* ????r?????????????? */
        int ans = int.MaxValue;
        Permutation perm = new Permutation();
        foreach (var n in perm.Enumerate(r))
        {
            int dis = 0;
            for (int i = 0; i < n.Length - 1; i++)
                dis += Dis[n[i], n[i + 1]];
            ans = Math.Min(ans, dis);
        }
        Console.WriteLine(ans);
    }
}

class Permutation // ??
{
    public IEnumerable<T[]> Enumerate<T>(IEnumerable<T> nums)
    {
        return _GetPermutations<T>(new List<T>(), nums.ToList());
    }

    private IEnumerable<T[]> _GetPermutations<T>(IEnumerable<T> perm, IEnumerable<T> nums)
    {
        if (nums.Count() == 0)
        {
            yield return perm.ToArray();
        }
        else
        {
            foreach (var n in nums)
            {
                var result = _GetPermutations<T>(perm.Concat(new T[] { n }),
                                                 nums.Where(x => x.Equals(n) == false)
                              );
                foreach (var xs in result)
                    yield return xs.ToArray();
            }
        }
    }
}