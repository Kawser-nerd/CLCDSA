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
        var nk = Array.ConvertAll(ReadLine().Split(' '), long.Parse);
        var dic = new SortedDictionary<long,long>();
        for (var i = 0; i < nk[0]; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            if (dic.ContainsKey(input[0]))
                dic[input[0]] += input[1];
            else dic[input[0]] = input[1];
        }
        var sum = 0L;
        foreach(var pair in dic)
        {
            sum += pair.Value;
            if (sum >= nk[1]) { WriteLine(pair.Key); return; }
        }
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}