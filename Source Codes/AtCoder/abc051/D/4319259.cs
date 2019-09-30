//#define TEST

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Linq;

class Program
{
    private static int N;
    private static int M;
    private static int[] a;
    private static int[] b;
    private static int[] c;
    private static int[,] Edge; //????
    private static int[,] MinDis; //?????????????

    public static void Main()
    {
        /*???????????????*/
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        N = input[0];
        M = input[1];
        a = new int[M];
        b = new int[M];
        c = new int[M];
        Edge = new int[N, N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                Edge[i, j] = (int)1e9; //??????????
        MinDis = new int[N, N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                MinDis[i, j] = (int)1e9; //??????????????
        for (int i = 0; i < N; i++)
            MinDis[i, i] = 0; //????????0?
        for (int i = 0; i < M; i++)
        {
            input = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int ai = input[0] - 1;
            int bi = input[1] - 1;
            int ci = input[2];
            Edge[ai, bi] = ci;
            Edge[bi, ai] = ci;
            MinDis[ai, bi] = ci;
            MinDis[bi, ai] = ci;
            a[i] = ai;
            b[i] = bi;
            c[i] = ci;
        }

        /*???????????*/
        WarshallFloyd();
        ShowMinDis();

        /*??(a,b;c)???????????????
            i = 0,1,2,...,N - 1 , j = i + 1,i + 2,i + 3,...,N ????
            MinDis[i,j] != MinDis[i,a] + c + MinDis[b,j]
            MinDis[j,i] != MinDis[j,a] + c + MinDis[b,i]
        */
        int ans = 0;
        for (int e = 0; e < M; e++)
        {
            bool f = true;
            for (int i = 0; i < N - 1; i++)
            {
                for (int j = i + 1; j < N; j++)
                {
                    f = f && MinDis[i, j] != MinDis[i, a[e]] + c[e] + MinDis[b[e], j];
                    f = f && MinDis[j, i] != MinDis[j, a[e]] + c[e] + MinDis[b[e], i];
                    if (!f) goto Fin;
                }
            }
            Fin:;
            if (f) ans++;
        }

        /*?????*/
#if TEST
        Console.WriteLine("ANS");
#endif
        Console.WriteLine(ans);
    }

    /*????????????????????????????*/
    private static void WarshallFloyd()
    {
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if (MinDis[i, j] > MinDis[i, k] + MinDis[k, j])
                        MinDis[i, j] = MinDis[i, k] + MinDis[k, j];
    }

    /*MinDis?????*/
    [Conditional("TEST")]
    private static void ShowMinDis()
    {
        Console.WriteLine("MinDis");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                Console.Write("{0} ", MinDis[i, j]);
            Console.WriteLine();
        }
    }
}