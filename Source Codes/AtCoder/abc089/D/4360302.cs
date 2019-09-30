using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    struct P
    {
        public int num;
        public int h;
        public int w;
        public P(int num,int h,int w)
        {
            this.num = num;
            this.h = h;
            this.w = w;
        }
    }
    static void Main(string[] args)
    {
        var hwd = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ps = new P[hwd[0] * hwd[1]+1];
        for (var i = 0; i < hwd[0]; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            for (var j = 0; j < hwd[1]; j++)
                ps[input[j]] = new P(input[j], i, j);
        }
        var im = new long[hwd[0] * hwd[1] + 1];
        for (var i = hwd[2] + 1; i <= hwd[0] * hwd[1]; i++)
            im[i] = im[i - hwd[2]] + GetDif(ps[i], ps[i - hwd[2]]);
        var que = ToInt32(ReadLine());
        var res = new long[que];
        for(var i = 0; i < que; i++)
        {
            var lr = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            res[i] = im[lr[1]] - im[lr[0]];
        }
        WriteLine(string.Join("\n", res));
    }
    private static int GetDif(P fr,P to)
    {
        return Abs(fr.h - to.h) + Abs(fr.w - to.w);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}