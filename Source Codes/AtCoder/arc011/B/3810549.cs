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
        var words = ReadLine().Split(' ');
        var dic = new Dictionary<string, int>();
        dic["b"] = 1;
        dic["c"] = 1;
        dic["t"] = 3;
        dic["d"] = 2;
        dic["w"] = 2;
        dic["j"] = 3;
        dic["f"] = 4;
        dic["q"] = 4;
        dic["l"] = 5;
        dic["v"] = 5;
        dic["s"] = 6;
        dic["x"] = 6;
        dic["p"] = 7;
        dic["m"] = 7;
        dic["h"] = 8;
        dic["k"] = 8;
        dic["n"] = 9;
        dic["g"] = 9;
        dic["z"] = 0;
        dic["r"] = 0;
        var result = new List<string>();
        for(var i = 0; i < num; i++)
        {
            var st = words[i].ToString();
            var nu = "";
            for(var j = 0; j < st.Length; j++)
            {
                var s = st.Substring(j, 1).ToLower();
                if (dic.ContainsKey(s))
                    nu += dic[s];
            }
            if (nu != "")
                result.Add(nu);
        }
        WriteLine(string.Join(" ", result));
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}