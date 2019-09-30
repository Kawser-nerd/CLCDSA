using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    private static long result;
    private const string march = "MARCH";
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var dic = new Dictionary<string, int>();
        for (var i = 0; i < 5; i++)
            dic[march.Substring(i, 1)] = 0;
        for (var i = 0; i < num; i++)
        {
            var str = ReadLine();
            var s = str.Substring(0, 1);
            if (dic.ContainsKey(s))
                dic[s]++;

        }
        for (var i = 0; i < 5; i++)
            dfs(dic, dic[march.Substring(i,1)],  0, i);
        WriteLine(result);
    }
    private static void dfs(Dictionary<string,int> dic,long res,int depth,int index)
    {
        if (depth == 2) { result += res; return; }
        for (var i = index+1; i < 5; i++)
        {
            var s = march.Substring(i, 1);
            dfs(dic, res * dic[s], depth+1, i);
        }

    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}