using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static int compare(string a,string b)
    {
        int s = Math.Min(a.Length, b.Length);
        for (int i = 1; i <= s; i++)
        {
            if (a[a.Length - i] < b[b.Length - i])
                return -1;
             else if (a[a.Length - i] > b[b.Length - i])
                return 1;
        }
        if (a.Length < b.Length)
            return -1;
        else
        if (a.Length > b.Length)
            return 1;
        return 0;
    }
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        List<string> s = new List<string>() { Capacity = N };
        for (int i = 0; i < N; i++)
            s.Add(Console.ReadLine());
        s.Sort((x,y)=> compare(x,y));
        foreach (var i in s)
            Console.WriteLine(i);
    }
}