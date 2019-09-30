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
        var nm = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var name = ReadLine();
        var kit = ReadLine();
        var dic = new Dictionary<char, int>();
        var dicn=new Dictionary<char, int>();
        for (var i = 0; i < nm[1]; i++)
            if (dic.ContainsKey(kit[i])) dic[kit[i]]++;
            else dic[kit[i]] = 1;
        for (var i = 0; i < nm[0]; i++)
            if (dicn.ContainsKey(name[i])) dicn[name[i]]++;
            else dicn[name[i]] = 1;
        var max = 0;
        foreach (var d in dicn)
        {
            if (dic.ContainsKey(d.Key))
            {
                max = Max(max, (int)Ceiling((double)d.Value / dic[d.Key]));
            }
            else
            {
                WriteLine(-1);return;
            }
        }
        WriteLine(max);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}