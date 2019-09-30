using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static int GCD(int x,int y)
    {
        if (x < y)
            return GCD(y, x);
        if (x % y == 0)
            return y;
        else
            return GCD(y, x % y);
    }
    public static void Main()
    {
        string[] s = Console.ReadLine().Split(' ');
        int N = int.Parse(s[0]);
        int X = int.Parse(s[1]);
        int[] x = new int[N];
        Queue<int> q = new Queue<int>();
        s = Console.ReadLine().Split(' ');
        for (int i = 0; i < N; i++)
            q .Enqueue(Math.Abs(int.Parse(s[i]) - X));
        while (q.Count > 1)
            q.Enqueue(GCD(q.Dequeue(), q.Dequeue()));
        Console.WriteLine(q.Dequeue());
    }
}