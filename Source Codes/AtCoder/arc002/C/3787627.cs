using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
using System.Globalization;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var comm = ReadLine();
        var min = int.MaxValue;
        for (var i = 0; i < 4; i++)
            dfs("", comm, ref min);
        WriteLine(min);
    }
    private static void dfs(string cm,string comm,ref int min)
    {
        var c = "ABXY";
        if (cm.Length == 4)
            min = Min(min, comm.Replace(cm.Substring(0, 2), "L").Replace(cm.Substring(2), "R").Length);
        else
            for (var i = 0; i < 4; i++)
                dfs(cm + c[i], comm, ref min);
        
            
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}