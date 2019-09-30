using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

static public class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int H, W;

    private int[][] C;
    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        H = int.Parse(line[0]);
        W = int.Parse(line[1]);
        C = new int[H][];
        for (int i = 0; i < H; i++)
        {
            C[i] = Console.ReadLine().Split(' ').Select((ii, index) => { return ((index+i) % 2 == 1 ? 1 : -1) * int.Parse(ii); }).ToArray();
        }
    }

    public void Solve()
    {
        Scan();
        var w = new int[H + 1, W + 1];
        for (int i = 1; i <= H; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                w[i, j] = w[i - 1, j] + w[i, j - 1] - w[i - 1, j - 1] + C[i - 1][j - 1];
            }
        }
        int max = 0;

        for (int iy = 0; iy < H; iy++)
        {
            for (int ix = 0; ix < W; ix++)
            {
                for(int jy = iy + 1; jy <= H; jy++)
                {
                    for(int jx = ix + 1; jx <= W; jx++)
                    {
                        int ans = w[jy, jx] - w[iy, jx] - w[jy, ix] + w[iy, ix];
                        if(ans == 0)
                        {
                            int f = (jy - iy) * (jx - ix);
                            max = Math.Max(max, f);
                        }
                    }
                }
            }
        }
        Console.WriteLine(max);
    }
}