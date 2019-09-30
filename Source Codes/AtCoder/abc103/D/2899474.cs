using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;
using System.Text;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        int[] nm = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        int n = nm[0];
        int m = nm[1];
        int[][] ab = Enumerable.Repeat(0, m).Select(_ => Console.ReadLine().Split(' ').Select(int.Parse).ToArray()).ToArray();
        List<Tuple<int, int>> d = new List<Tuple<int, int>>();

        for (int i = 0; i < m; i++)
        {
            d.Add(new Tuple<int, int>(ab[i][0], ab[i][1]));
        }

        d.Sort((a, b) => (a.Item2 != b.Item2) ? (a.Item2 - b.Item2) : (a.Item1 - b.Item1));

        int ans = 0;
        int destroy = 0;

        for(int i = 0; i < m; i++)
        {
            if(destroy <= d[i].Item1)
            {
                destroy = d[i].Item2;
                ans++;
            }
        }

        Console.WriteLine(ans);
    }
}