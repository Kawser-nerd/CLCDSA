using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var hw = Console.ReadLine().Split(' ');
        var h = int.Parse(hw[0]);
        var w = int.Parse(hw[1]);

        var hlist = new List<List<char>>();
        for (int i = 0; i < h; i++)
        {
            var s = Console.ReadLine();
            var wlist = new List<char>();
            for (int j = 0; j < w; j++)
            {
                wlist.Add(s[j]);
            }
            hlist.Add(wlist);
        }

        hlist = m1(m1(hlist));

        for (int i = 0; i < hlist.Count; i++)
        {
            for (int j = 0; j < hlist[i].Count; j++)
            {
                Console.Write(hlist[i][j]);
            }
            Console.WriteLine();
        }
    }

    static List<List<char>> m1(List<List<char>> source)
    {
        var hlist = new List<List<char>>();
        for (int i = 0; i < source[0].Count; i++)
        {
            var f = false;
            var wlist = new List<char>();
            for (int j = 0; j < source.Count; j++)
            {
                f |= source[j][i] == '#';
                wlist.Add(source[j][i]);
            }
            if (f)
            {
                hlist.Add(wlist);
            }
        }
        return hlist;
    }
}