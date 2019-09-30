using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var nk = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var xy = new int[nk[0]][];
        for (var i = 0; i < nk[0]; i++)
            xy[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var xar = xy.Select(p => p[0]).OrderBy(v => v).ToArray();
        var yar = xy.Select(p => p[1]).OrderBy(v => v).ToArray();
        var res = long.MaxValue;
        for (var xf = 0; xf < nk[0] - 1; xf++)
            for(var xl=xf+1;xl<nk[0];xl++)
                for(var yf=0;yf<nk[0]-1;yf++)
                    for(var yl = yf + 1; yl < nk[0]; yl++)
                    {
                        var cou = 0;
                        var xfir = xar[xf];
                        var xlas = xar[xl];
                        var yfir = yar[yf];
                        var ylas = yar[yl];
                        for (var i = 0; i < nk[0]; i++)
                            if (xfir <= xy[i][0] && xy[i][0] <= xlas && yfir <= xy[i][1] && xy[i][1] <= ylas)
                                cou++;
                        if (cou >= nk[1])
                            res = Min(res, (long)(xlas - xfir) * (ylas - yfir));
                    }
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}