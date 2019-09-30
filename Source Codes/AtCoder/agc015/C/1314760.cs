//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

public static class Enumerable2D
{
    public static TResult[,] DiffX<T, TResult>(this T[,] s, Func<T, T, TResult> f)
    {
        // do not use int[][] (instead of int[,]) in case of s.GetLength == 0

        int N = s.GetLength(0);
        int M = s.GetLength(1);

        var temp = new TResult[N, M - 1];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M - 1; j++)
            {
                temp[i, j] = f(s[i, j], s[i, j + 1]);
            }
        }

        return temp;
    }

    public static TResult[,] DiffY<T, TResult>(this T[,] s, Func<T, T, TResult> f)
    {
        // do not use int[][] (instead of int[,]) in case of s.GetLength == 0

        int N = s.GetLength(0);
        int M = s.GetLength(1);

        var temp = new TResult[N - 1, M];

        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < M; j++)
            {
                temp[i, j] = f(s[i, j], s[i + 1, j]);  // ???
            }
        }

        return temp;
    }
}

public class PartialSum2D
{
    int[,] sum;

    public PartialSum2D(int[,] s)
    {
        // do not use int[][] (instead of int[,]) in case of s.GetLength == 0

        int H = s.GetLength(0);
        int W = s.GetLength(1);

        sum = new int[H + 1, W + 1];

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                sum[i + 1, j + 1] = sum[i, j + 1] + sum[i + 1, j] - sum[i, j] + (int)s[i, j];
            }
        }
    }

    public int Query(int y1, int x1, int y2Exclusive, int x2Exclusive)
    {
        return 0
            + sum[y2Exclusive, x2Exclusive]
            - sum[y1, x2Exclusive]
            - sum[y2Exclusive, x1]
            + sum[y1, x1];
    }
}

public class Test
{
    public static void Main()
    {
        var line1 = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var N = line1[0];
        var M = line1[1];
        var Q = line1[2];

        // vvchar ?????????
        // ??Concole.WriteLine??????????????
        var s = new int[N, M];

        for (var i = 0; i < N; i++)
        {
            var s0 = Console.ReadLine();

            for (int j = 0; j < M; j++)
            {
                s[i, j] = (byte)(s0[j] - '0');
            }
        }

        PartialSum2D face = new PartialSum2D(s);

        // ????????? (????diff)
        PartialSum2D edgeVert = new PartialSum2D(s.DiffX((x, y) => x * y));

        // ????????? (????diff)
        PartialSum2D edgeHori = new PartialSum2D(s.DiffY((x, y) => x * y));
        
        for (int k = 0; k < Q; k++)
        {
            var line2 = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();  
            var x1 = line2[0] - 1;  // ???????xi????????yi?????NG
            var y1 = line2[1] - 1;
            var x2 = line2[2] - 1;
            var y2 = line2[3] - 1;

            var f = face.Query(x1, y1, x2 + 1, y2 + 1);
            var v = edgeVert.Query(x1, y1, x2 + 1, y2);
            var h = edgeHori.Query(x1, y1, x2, y2 + 1);

            Console.WriteLine(f - v - h);
        }
    }
}