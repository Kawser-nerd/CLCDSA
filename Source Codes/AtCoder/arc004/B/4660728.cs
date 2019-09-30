using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        Queue<int> q = new Queue<int>();
        for (int i = 0; i < N; i++)
            q.Enqueue(int.Parse(Console.ReadLine()));
        int max = 0;
        int min = 0;
        while (q.Count > 0)
        {
            int v = q.Dequeue();
            if (min > v)
                min -= v;
            else if (min <= v && v <= max)
                min = 0;
            else
                min = v - max;
            max += v;
        }
        Console.WriteLine(max);
        Console.WriteLine(min);
    }
}