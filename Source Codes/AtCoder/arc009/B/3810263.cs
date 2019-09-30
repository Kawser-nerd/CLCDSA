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
        var re = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var dic1 = new Dictionary<string, string>();
        var dic2 = new Dictionary<string, string>();
        for(var i = 0; i < 10; i++)
        {
            dic1[i.ToString()] = re[i].ToString();
            dic2[re[i].ToString()] = i.ToString();
        }
        var num = ToInt32(ReadLine());
        var ar = new long[num];
        for (var i = 0; i < num; i++)
            ar[i] = ToInt64(ReadLine());
        for(var i = 0; i < num; i++)
        {
            ar[i] = Get(dic2, ar[i].ToString());
        }
        Array.Sort(ar);
        for (var i = 0; i < num; i++)
            WriteLine(Get(dic1, ar[i].ToString()));
    }
    private static long Get(Dictionary<string,string> dic,string num)
    {
        var ne = "";
        for (var i = 0; i < num.Length; i++)
            ne += dic[num.Substring(i, 1)];
        return ToInt64(ne);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}