using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    struct P
    {
        public int h;
        public int w;
        public P(int h,int w)
        {
            this.h = h;
            this.w = w;
        }
    }
    static void Main(string[] args)
    {
        var hwt = Input.ar;
        var gred = new string[hwt[0]];
        for (var i = 0; i < hwt[0]; i++)
            gred[i] = ReadLine();
        var st = new P(-1, -1);
        var go = new P(-1, -1);
        for (var i = 0; i < hwt[0]; i++)
            for (var j = 0; j < hwt[1]; j++)
                if (gred[i][j] == 'S')
                {
                    st.h = i;
                    st.w = j;
                }
                else if (gred[i][j] == 'G')
                {
                    go.h = i;
                    go.w = j;
                }
        var left = 1;
        var right = hwt[2];
        while (right-left>1)
        {
            var mid = (right + left) / 2;
            var weights = new long[hwt[0], hwt[1]];
            for (var i = 0; i < hwt[0]; i++)
                for (var j = 0; j < hwt[1]; j++)
                    weights[i, j] = long.MaxValue;
            weights[st.h, st.w] = 0;
            var bo = new bool[hwt[0], hwt[1]];
            while (true)
            {
                var min = long.MaxValue;
                var p = new P(-1, -1);
                for(var i=0;i<hwt[0];i++)
                    for(var j=0;j<hwt[1];j++)
                        if (!bo[i,j]&&min > weights[i, j])
                        {
                            min = weights[i, j];
                            p = new P(i, j);
                        }
                if (min == long.MaxValue) break;
                bo[p.h, p.w] = true;
                for (var i = 0; i < 4; i++)
                {
                    var h = p.h + GH[i];
                    var w = p.w + GW[i];
                    if (0 <= h && h < hwt[0] && 0 <= w && w < hwt[1])
                    {
                        var wei = weights[p.h, p.w] + (gred[h][w] == '#' ? mid : 1);
                        if (!bo[h, w] && weights[h, w] > wei)
                            weights[h, w] = wei;
                    }
                }
            }
            if (weights[go.h, go.w] > hwt[2])
                right = mid;
            else left = mid;
        }
        WriteLine(left);
    }
    private static int[] GH = new[] { 0, 0, -1, 1 };
    private static int[] GW = new[] { 1, -1, 0, 0 };
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}