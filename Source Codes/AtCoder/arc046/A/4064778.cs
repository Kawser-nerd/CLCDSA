using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Hello
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int N = Cin<int>();
        List<int> o = new List<int>() { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        for (int i = 1; i < 10; i++)
        {
            int t = o[i - 1];
            for (int j = 0; j < 7; j++)
            {
                o.Add(t * 10 + i);
                t = t * 10 + i;
            }
        }
        o.Sort();
        Console.WriteLine(o[N - 1]);
    }
}

public class Input
{
    private static Queue<string> queue = new Queue<string>();
    public static T Cin<T>()
    {
        if (queue.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) queue.Enqueue(s);
        if (typeof(T) == typeof(int)) return (T)(object)int.Parse(queue.Dequeue());
        else if (typeof(T) == typeof(long)) return (T)(object)long.Parse(queue.Dequeue());
        else if (typeof(T) == typeof(string)) return (T)(object)(queue.Dequeue());
        else if (typeof(T) == typeof(double)) return (T)(object)double.Parse(queue.Dequeue());
        else return (T)(object)(0);
    }
    public static T Line<T>()
    {
        foreach (var s in Console.ReadLine().Split(' ')) queue.Enqueue(s);
        int c = queue.Count();
        if (typeof(T) == typeof(int[]))
        {
            int[] ret = new int[c];
            for (int i = 0; i < c; i++) ret[i] = Cin<int>();
            return (T)(object)ret;
        }
        else if (typeof(T) == typeof(long[]))
        {
            long[] ret = new long[c];
            for (int i = 0; i < c; i++) ret[i] = Cin<long>();
            return (T)(object)ret;
        }
        else if (typeof(T) == typeof(string[]))
        {
            string[] ret = new string[c];
            for (int i = 0; i < c; i++) ret[i] = Cin<string>();
            return (T)(object)ret;
        }
        else if (typeof(T) == typeof(double[]))
        {
            double[] ret = new double[c];
            for (int i = 0; i < c; i++) ret[i] = Cin<double>();
            return (T)(object)ret;
        }
        else return (T)(object)(0);
    }
}