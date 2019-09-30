using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;
using System.Linq;

class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{

    private int A, B, C;

    public void Solve()
    {
        var Map = new Dictionary<int, int>();
        int N, M;
        var line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        M = int.Parse(line[1]);
        for (int i = 0; i < M; i++)
        {
            line = Console.ReadLine().Split(' ');
            int a = int.Parse(line[0]);
            int b = int.Parse(line[1]);
            int d;
            if (!Map.TryGetValue(a, out d)) Map[a] = 0;
            if (!Map.TryGetValue(b, out d)) Map[b] = 0;
            Map[a]++;
            Map[b]++;
        }
        foreach(var i in Map)
        {
            if (i.Value % 2 == 1)
            {
                Console.WriteLine("NO");
                return;
            }
        }
        Console.WriteLine("YES");
    }


}