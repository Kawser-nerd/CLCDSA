using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var s = Console.ReadLine().Trim();
        if (n % 2 == 0) { Console.WriteLine(-1); goto end; }
        Console.WriteLine(checkS(s, n));
        end:;
    }
    public static int checkS (string s , int n)
    {
        var w = new string[] { "bca", "abc", "cab" };
        var q = new Queue<char>();
        var w0 = (n - 1) / 2;
        var w1 = (w0) % 3;
        for (int i = 0; i < 3; i++) q.Enqueue(w[w1][i]);
        for (int i = 0; i < n; i++)
        {
            var t = q.Dequeue();  q.Enqueue(t);
            if (s[i] != t) return -1;
        }
        return w0;
    }
}