// ABC 061 D Score Attack

using System;
using System.Linq;

class Program
{
    static int N;
    static int M;
    static int[] a; // a[i] : a_(i + 1) - 1
    static int[] b; // b[i] : b_(i + 1) - 1
    static int[] c; // c[i] : -c_(i + 1)

    static void Main()
    {
        /* ??????? */
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        N = input[0];
        M = input[1];
        a = new int[M];
        b = new int[M];
        c = new int[M];
        for (int i = 0; i < M; i++)
        {
            input = Console.ReadLine().Split().Select(int.Parse).ToArray();
            a[i] = input[0] - 1;
            b[i] = input[1] - 1;
            c[i] = -input[2];
        }

        /* (?????-1???????)BellmanFord???????????????????? */
        long[] dis = new long[N];
        for (int i = 1; i < N; i++)
            dis[i] = (long)1e18;
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (dis[a[j]] == (long)1e18) continue;
                if (dis[b[j]] > dis[a[j]] + c[j])
                    dis[b[j]] = dis[a[j]] + c[j];
            }
        }
        long ans = -dis[N - 1];
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (dis[a[j]] == (long)1e18) continue;
                if (dis[b[j]] > dis[a[j]] + c[j])
                    dis[b[j]] = dis[a[j]] + c[j];
            }
        }
        if (ans == -dis[N - 1]) Console.WriteLine(ans);
        else Console.WriteLine("inf");
    }
}