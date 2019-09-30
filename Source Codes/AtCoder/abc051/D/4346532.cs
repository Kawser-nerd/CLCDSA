using System;
using System.Collections.Generic;
using System.Linq;
//using System.Numerics;
class Program
{     
    const int INF = short.MaxValue;
    public void Slove()
    {
        var inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int m = int.Parse(inputs[1]);
        int[][] distance =
            Enumerable.Range(0, n)
            .Select(x => new int[n].Select(y => INF).ToArray())
            .ToArray();
        foreach(int i in Enumerable.Range(0, n))
            distance[i][i] = 0;
        var node =
            Enumerable.Range(0, m)
            .Select(x => Console.ReadLine().Split()
                .Select(int.Parse).ToArray())
            .Select(x => new {a = x[0] - 1, b = x[1] - 1, dis = x[2]})
            .ToArray();
        foreach(var item in node)
        {
            distance[item.a][item.b] = item.dis;
            distance[item.b][item.a] = item.dis;
        }
        foreach(int i in Enumerable.Range(0, n))
            foreach(int j in Enumerable.Range(0, n))
                foreach(int k in Enumerable.Range(0, n))
                {
                    distance[j][k] = Math.Min(distance[j][k], distance[j][i] + distance[i][k]);
                }
        //System.Console.WriteLine(string.Join("\n", distance.Select(x => string.Join(",", x))));
        int result = node.Count(x => x.dis != distance[x.a][x.b]);
        System.Console.WriteLine(result);
    }
    
    static void Main(string[] args)
    {
        new Program().Slove();
    }
}