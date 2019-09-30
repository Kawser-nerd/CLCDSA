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
        var hwn = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var point = new long[10];
        point[0] = (long)(hwn[0] - 2) * (hwn[1] - 2);
        var dic = new Dictionary<int, Dictionary<int,int>>();
        for(var i = 0; i < hwn[2]; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            for(var j = 0; j < 3; j++)
                for(var h = 0; h < 3; h++)
                {
                    var hh = input[0] - j;
                    var ww = input[1] - h;
                    if (1 > hh || hh > hwn[0]-2 || 1 > ww || ww > hwn[1]-2)
                        continue;
                    if (!dic.ContainsKey(hh))
                        dic[hh] = new Dictionary<int, int>();
                    if (dic[hh].ContainsKey(ww))
                        dic[hh][ww]++;
                    else dic[hh][ww] = 1;
                    point[dic[hh][ww]]++;
                }
        }
        for (var i = 0; i < 9; i++)
            WriteLine(point[i] - point[i + 1]);
        WriteLine(point[9]);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}