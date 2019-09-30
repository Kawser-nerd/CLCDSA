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
        int x;
        int y;
        public P(int x,int y)
        {
            this.x = x;
            this.y = y;
        }
    }
    static void Main(string[] args)
    {
        var hw = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var gre = new string[hw[0]];
        var count = 0;
        for (var i = 0; i < hw[0]; i++)
        {
            gre[i] = ReadLine();
            count += gre[i].Count(c => c == '#');
        }
        int x = 0, y = 0, nextx = 0, nexty = 0;
        var set = new HashSet<P>();
        while (x != hw[1] - 1 || y != hw[0] - 1)
        {
            var isP = false;
            set.Add(new P(x, y));
            if (x != hw[1] - 1 && gre[y][x + 1] == '#')
            {
                isP = true;
                nextx++;
            }
            if (y != hw[0] - 1 && gre[y + 1][x] == '#')
            {
                if (isP) { WriteLine("Impossible");return; }
                isP = true;
                nexty++;
            }
            if (isP) { x = nextx;y = nexty; }
            else { WriteLine("Impossible");return; }
        }
        WriteLine(set.Count==count-1?"Possible":"Impossible");
    }
}