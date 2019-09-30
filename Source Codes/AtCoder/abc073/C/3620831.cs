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
        var num = ToInt32(ReadLine());
        var dic = new Dictionary<int, int>();
        for(var i = 0; i < num; i++)
        {
            var a = ToInt32(ReadLine());
            if (dic.ContainsKey(a)) dic[a]++;
            else dic[a] = 1;
        }
        var result = 0;
        foreach (var key in dic.Keys)
            result += dic[key] % 2 == 0 ? 0 : 1;
        WriteLine(result);
    }
}