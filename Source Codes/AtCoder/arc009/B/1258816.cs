using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

public class Program
{
    public static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private Dictionary<string, int> map;
    private int N;
    private string[] a;
    public void Solve()
    {
        var line = Console.ReadLine().Split(' ');
        map = new Dictionary<string, int>();
        for(int i = 0; i <= 9; i++)
        {
            map[line[i]] = i;
        }
        N = int.Parse(Console.ReadLine());
        a = new string[N];
        for (int i = 0; i < N; i++)
        {
            a[i] = Console.ReadLine();
        }
        Array.Sort(a, compare);
        Console.WriteLine(string.Join("\n", a));
    }

    private int compare(string a,string b)
    {
        if (a.Length == b.Length)
        {
            for (int i = 0; i < a.Length; i++)
            {
                if (a[i] != b[i])
                {
                    return map[a[i].ToString()].CompareTo(map[b[i].ToString()]);
                }
            }
            return 0;
        }
        else
        {
            return a.Length.CompareTo(b.Length);
        }
    }
}