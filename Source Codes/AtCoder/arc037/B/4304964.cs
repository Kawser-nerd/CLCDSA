using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    private static bool res = true;
    private static HashSet<int> co = new HashSet<int>();
    static void Main(string[] args)
    {
        var nm = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ad = new List<int>[nm[0]];
        for (var i = 0; i < nm[0]; i++)
            ad[i] = new List<int>();
        for(var i = 0; i < nm[1]; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            ad[input[0] - 1].Add(input[1] - 1);
            ad[input[1] - 1].Add(input[0] - 1);
        }
        var sum = 0;
        for(var i = 0; i < nm[0]; i++)
        {
            if (!co.Contains(i))
            {
                res = true;
                dfs(ad, new HashSet<int>(), i, i);
                if (res) sum++;
            }   
        }
        WriteLine(sum);
    }
    private static void dfs(List<int>[] ad,HashSet<int> set,int index,int then)
    {
        set.Add(index);
        co.Add(index);
        foreach (var item in ad[index])
        {
            if ((item != then && set.Contains(item))||!res)
            {
                res = false;
                return;
            }
            else if(!set.Contains(item))
                dfs(ad, set, item, index);
        }
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}