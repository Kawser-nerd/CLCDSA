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
        var rck = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var num = ToInt32(ReadLine());
        var amer = new int[rck[0]];
        var amec = new int[rck[1]];
        var a = new int[num, 2];
        for(var i = 0; i < num; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            amer[input[0] - 1]++;
            amec[input[1] - 1]++;
            a[i, 0] = input[0] - 1;
            a[i, 1] = input[1] - 1;
        }
        var dicr = new Dictionary<int, int>();
        var dicc = new Dictionary<int, int>();
        for (var i = 0; i < rck[0]; i++)
        {
            if (dicr.ContainsKey(amer[i])) dicr[amer[i]]++;
            else dicr[amer[i]] = 1;
            if (!dicr.ContainsKey(i)) dicr[i] = 0;

        }
        for(var i = 0; i < rck[1]; i++)
        {
            if (dicc.ContainsKey(amec[i])) dicc[amec[i]]++;
            else dicc[amec[i]] = 1;
            if (!dicc.ContainsKey(i)) dicc[i] = 0;
        }
        var sum = 0L;
        for(var i = 0; i <= rck[2]; i++)
        {
            if(dicc.ContainsKey(i)&&dicr.ContainsKey(rck[2]-i))
            sum += (long)dicc[i] * dicr[rck[2]-i];
        }
        for(var i = 0; i < num; i++)
        {
            if (amer[a[i, 0]] + amec[a[i, 1]] == rck[2]) sum--;
            else if (amer[a[i, 0]] + amec[a[i, 1]] == rck[2] + 1) sum++;
        }
        WriteLine(sum);
    }

    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}