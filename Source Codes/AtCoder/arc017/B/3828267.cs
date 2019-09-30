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
        var nk = Array.ConvertAll(ReadLine().Split(' '),int.Parse); 
        var ar = new int[nk[0]];
        for (var i = 0; i < nk[0]; i++)
            ar[i] = ToInt32(ReadLine());
        if (nk[1] == 1) { WriteLine(nk[0]); return; }
        var row = 1;
        var result = 0;
        for(var i = 1; i < nk[0]; i++)
        {
            if (ar[i-1] < ar[i]) row++;
            else  row = 1;
            if (row == nk[1]) { result++; row = nk[1]-1; }
        }
        WriteLine(result);

    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}