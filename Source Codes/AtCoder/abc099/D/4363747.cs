using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    private static int res = int.MaxValue;
    static void Main(string[] args)
    {
        var nc = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ds = new int[nc[1]][];
        for (var i = 0; i < nc[1]; i++)
            ds[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        
        var dic = new Dictionary<int, Dictionary<int, int>>();
        for(var i = 1; i <= nc[0]; i++)
        {
            var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            for (var j = 0; j < nc[0]; j++)
            {
                var mod = (i + j + 1) % 3;
                if (!dic.ContainsKey(mod))
                    dic[mod] = new Dictionary<int, int>();
                if (dic[mod].ContainsKey(ar[j]-1))
                    dic[mod][ar[j]-1]++;
                else
                    dic[mod][ar[j]-1] = 1;
            }
        }
        for (var i = 0; i < nc[1]; i++)
            dfs(Enumerable.Repeat(-1,3).ToArray(), 0,  i, ds, dic, nc[1]);
        WriteLine(res);
    }
    private static void dfs(int[] sel,int index,int num,int[][] ds,Dictionary<int,Dictionary<int,int>> dic,int c)
    {
        sel[index] = num;
        if (index == 2)
        {
            var sum = 0;
            for(var i = 0; i < 3; i++)
            {
                for (var j = 0; j < c; j++)
                    if (dic.ContainsKey(i)&&dic[i].ContainsKey(j))
                        sum += ds[j][sel[i]] * dic[i][j];
            }
            res = Min(res, sum);
            sel[index] = -1;
            return;
        }
        for (var i = 0; i < c; i++)
            if (!sel.Contains(i))
                dfs(sel, index + 1, i, ds, dic, c);
        sel[index] = -1;
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}