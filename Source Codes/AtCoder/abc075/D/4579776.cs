using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var nk = Input.ar;
        var xy = Enumerable.Repeat(0, nk[0]).Select(v => Input.arL).ToArray();
        var res = long.MaxValue;
        var xar = xy.OrderBy(v => v[0]).Select(v => v[0]).ToArray();
        var yar = xy.OrderBy(v => v[1]).Select(v => v[1]).ToArray();
        for (var xf = 0; xf < nk[0]; xf++)
            for(var xl=xf;xl<nk[0];xl++)
                for(var yf=0;yf<nk[0];yf++)
                    for(var yl = yf; yl < nk[0]; yl++)
                    {
                        var ct = 0;
                        for (var i = 0; i < nk[0]; i++)
                            if (xar[xf] <= xy[i][0] && xy[i][0] <= xar[xl] && yar[yf] <= xy[i][1] && xy[i][1] <= yar[yl])
                                ct++;
                        if(ct>=nk[1])
                        res = Min(res, (xar[xl] - xar[xf]) * (yar[yl] - yar[yf]));
                    }
        WriteLine(res);
    }
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