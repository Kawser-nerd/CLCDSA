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
        var fri = new HashSet<int>[nm[0]];
        for (var i = 0; i < nm[0]; i++)
            fri[i] = new HashSet<int>();
        for(var i = 0; i < nm[1]; i++)
        {
            var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            fri[ar[0]-1].Add(ar[1]-1);
            fri[ar[1]-1].Add(ar[0]-1);
        }
        for(var i = 0; i < nm[0]; i++)
        {
            var r = 0;
            var con = new HashSet<int>();
            foreach(var f in fri[i])
            {
                foreach(var w in fri[f])
                {
                    if (w != i && !fri[i].Contains(w)&&!con.Contains(w))
                    {
                        r++;
                        con.Add(w);
                    }
                }
            }
            WriteLine(r);
        }
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}