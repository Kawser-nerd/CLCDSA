//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

public class Test
{
    public static int[,] CreatePartialSumTable(byte[][] s, int H, int W)
    {
        var sum = new int[H + 1, W + 1];

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                sum[i + 1, j + 1] = sum[i, j + 1] + sum[i + 1, j] - sum[i, j] + (int)s[i][j];
            }
        }

        return sum;
    }

    public static void Main()
    {
        var line1 = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var N = line1[0];
        var M = line1[1];
        var Q = line1[2];

        var s = new byte[N][];

        for (var i = 0; i < N; i++)
        {
            s[i] = new byte[M];
            var s0 = Console.ReadLine();

            for (int j = 0; j < M; j++)
            {
                s[i][j] = (byte)(s0[j] - '0');
            }
        }

        int[,] face = CreatePartialSumTable(s, N, M);

        int[,] edgeVert;  // ???????
        {
            var temp = new byte[N][];

            for (int i = 0; i < N; i++)
            {
                temp[i] = new byte[M - 1];
                for (int j = 0; j < M - 1; j++)
                {
                    temp[i][j] = (byte)(s[i][j] * s[i][j + 1]);  // ???
                }
            }
            
            edgeVert = CreatePartialSumTable(temp, N, M - 1);
            temp = null;
        }
        

        int[,] edgeHori;  // ???????
        {
            var temp = new byte[N - 1][];

            for (int i = 0; i < N - 1; i++)
            {
                temp[i] = new byte[M];
                for (int j = 0; j < M; j++)
                {
                    temp[i][j] = (byte)(s[i][j] * s[i + 1][j]);  // ???
                }
            }

            s = null;

            edgeHori = CreatePartialSumTable(temp, N - 1, M);
            temp = null;
            GC.Collect();
        }
                

        for (int k = 0; k < Q; k++)
        {
            var line2 = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();  
            var x1 = line2[0];  // ???????xi????????yi?????NG
            var y1 = line2[1];
            var x2 = line2[2];
            var y2 = line2[3];

            var f = face[x2, y2] - face[x2, y1 - 1] - face[x1 - 1, y2] + face[x1 - 1, y1 - 1];
            var v = edgeVert[x2, y2 - 1] - edgeVert[x2, y1 - 1] - edgeVert[x1 - 1, y2 - 1] + edgeVert[x1 - 1, y1 - 1];
            var h = edgeHori[x2 - 1, y2] - edgeHori[x2 - 1, y1 - 1] - edgeHori[x1 - 1, y2] + edgeHori[x1 - 1, y1 - 1];

            Console.WriteLine(f - v - h);

            if (k % 30000 == 0)
            {
                GC.Collect();
            }
        }
    }
}