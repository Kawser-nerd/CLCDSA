using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    struct P
    {
        public int x;
        public int y;
        public P(int y,int x)
        {
            this.x = x;
            this.y = y;
        }
    }
    static void Main(string[] args)
    {
        var gre = new string[10];
        for (var i = 0; i < 10; i++)
            gre[i] = ReadLine();
        var an = new HashSet<P>();
        for(var i = 0; i < 10; i++)
        {
            for (var j = 0; j < 10; j++)
                if (gre[i][j] == 'o') an.Add(new P(i, j));
        }
        for(var i = 0; i < 10; i++)
        {
            for(var j = 0; j < 10; j++)
            {
                if (gre[i][j] != 'o')
                {
                    var s = new P(i, j);
                    an.Add(s);
                    var qu = new HashSet<P>();
                    dfs(gre, an, qu, j, i);
                    if (qu.Count==an.Count)
                    {
                        WriteLine("YES");
                        return;
                    }
                    an.Remove(s);
                }
            }
        }
        WriteLine("NO");
    }
    private static void dfs(string[] gre, HashSet<P> an, HashSet<P> qu, int x, int y)
    {
        qu.Add(new P(y, x));

        if (x != 0 && !qu.Contains(new P(y, x - 1)) && gre[y][x - 1] == 'o')
            dfs(gre, an, qu, x - 1, y);
        if (x != 9 && !qu.Contains(new P(y, x + 1)) && gre[y][x + 1] == 'o')
            dfs(gre, an, qu, x + 1, y);
        if (y != 0 && !qu.Contains(new P(y - 1, x)) && gre[y - 1][x] == 'o')
            dfs(gre, an, qu, x, y - 1);
        if (y != 9 && !qu.Contains(new P(y + 1, x)) && gre[y + 1][x] == 'o')
            dfs(gre, an, qu, x, y + 1);
            
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}