using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private string S;

    public void Solve()
    {
        S = Console.ReadLine();
        var map = new Dictionary<char, int>();
        for(char c = 'a'; c <= 'z'; c++)
        {
            map[c] = 0;
        }
        foreach(char c in S)
        {
            map[c]++;
        }
        int cnt = map.Count(p => p.Value % 2 == 1);
        if(cnt == 0)
        {
            Console.WriteLine(S.Length);
            return;
        }
        int length = ((S.Length - cnt) / 2 / cnt)*2+1;
        Console.WriteLine(length);
    }
}