using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using static System.Math;
using Debug = System.Diagnostics.Debug;


static class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        //?????????????????
        bool isOdd = n % 2 != 0;
        n = (n / 2) * 2;

        List<Tuple<int, int>> edges = new List<Tuple<int, int>>();
        int s = 1 + n;
        for (int i = 1; i <= n / 2; i++)
        {
            int anotherVertex = s - i;
            for (int j = 1; j <= n; j++)
            {
                if (j == i || j == anotherVertex) continue;
                int anotherVert = s - j;
                edges.Add(new Tuple<int, int>(i, j));
                edges.Add(new Tuple<int, int>(i, anotherVert));
                edges.Add(new Tuple<int, int>(anotherVertex, j));
                edges.Add(new Tuple<int, int>(anotherVertex, anotherVert));
            }
        }
        if (isOdd)
        {
            for (int i = 1; i <= n; i++)
            {
                edges.Add(new Tuple<int, int>(i, n + 1));
            }
        }
        edges = edges.Select(x => x.Item1 > x.Item2 ? new Tuple<int, int>(x.Item2, x.Item1) : x).Distinct().ToList();
        Console.WriteLine(edges.Count);
        Console.WriteLine(string.Join("\n", edges.Select(x => $"{x.Item1} {x.Item2}")));
    }
}