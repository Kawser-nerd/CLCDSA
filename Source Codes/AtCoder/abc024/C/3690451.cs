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
        var ndk = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var lr = new int[ndk[1]][];
        for (var i = 0; i < ndk[1]; i++)
            lr[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var st = new int[ndk[2]][];
        for (var i = 0; i < ndk[2]; i++)
            st[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var cle = new int[ndk[2]][];
        for(var i = 0; i < ndk[2]; i++)
        {
            cle[i] = new int[2];
            cle[i][0] = st[i][0];
            cle[i][1] = st[i][0];
        }
        var result = new int[ndk[2]];
        var isdet = new bool[ndk[2]];
        for(var i = 0; i < ndk[1]; i++)
        {
            for(var j = 0; j < ndk[2]; j++)
            {
                if (cle[j][0] > lr[i][0] && cle[j][0] <= lr[i][1])
                    cle[j][0] = lr[i][0];
                if (cle[j][1] < lr[i][1] && cle[j][1] >= lr[i][0])
                    cle[j][1] = lr[i][1];
                if (!isdet[j]&&cle[j][0] <= st[j][1] && cle[j][1] >= st[j][1])
                {
                    result[j] = i+1;
                    isdet[j] = true;
                }
            }
        }
        foreach (var r in result)
            WriteLine(r);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}