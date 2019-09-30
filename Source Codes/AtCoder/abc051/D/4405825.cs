using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    struct P
    {
        public int index;
        public List<int> ad;
        public Dictionary<int, int> weights;
        public P(int index)
        {
            this.index = index;
            ad = new List<int>();
            weights = new Dictionary<int, int>();
        }
    }
    class E
    {
        public int index1;
        public int index2;
        public int weight;
        public E(int index1,int index2,int weight)
        {
            this.index1 = index1;
            this.index2 = index2;
            this.weight = weight;
        }
    }
    static void Main(string[] args)
    {
        var nm = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ps = new P[nm[0]];
        var eg = new E[nm[1]];
        for (var i = 0; i < nm[0]; i++)
            ps[i] = new P(i);
        for (var i = 0; i < nm[1]; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            ps[input[0] - 1].ad.Add(input[1] - 1);
            ps[input[1] - 1].ad.Add(input[0] - 1);
            ps[input[0] - 1].weights[input[1] - 1] = input[2];
            ps[input[1] - 1].weights[input[0] - 1] = input[2];
            eg[i] = new E(input[0] - 1, input[1] - 1,input[2]);
        }
        var wei = new int[nm[0], nm[0]];
        for(var i = 0; i < nm[0]; i++)
        {
            for (var j = 0; j < nm[0]; j++)
                wei[i, j] = int.MaxValue;
            wei[i, i] = 0;
            var set = new HashSet<int>();
            while (true)
            {
                var min = int.MaxValue;
                var minj = -1;
                for (var j = 0; j < nm[0]; j++)
                    if (!set.Contains(j) && min > wei[i, j])
                    {
                        min = wei[i, j];
                        minj = j;
                    }
                if (minj == -1) break;
                set.Add(minj);
                foreach (var a in ps[minj].ad)
                {
                    if (!set.Contains(a) && wei[i, a] > wei[i, minj] + ps[minj].weights[a])
                        wei[i, a] = wei[i, minj] + ps[minj].weights[a];
                }
            }
        }
        var res = 0;
        foreach (var ege in eg)
        {
            var isTh = false;
            for(var i=0;i<nm[0];i++)
                for(var j = 0; j < nm[0]; j++)
                    if (wei[i, ege.index1] + ege.weight + wei[ege.index2, j] == wei[i, j])
                    {
                        isTh = true;
                        break;
                    }
            if (!isTh) res++;
        }
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}