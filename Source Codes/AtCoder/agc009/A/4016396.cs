using System;
using System.Collections.Generic;
using System.Linq;

public class Hello
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int N = Input.Cin<int>();
        long[] A = new long[N];
        long[] B = new long[N];
        for (int i = N - 1; i != -1; i--) { A[i] = Input.Cin<long>(); B[i] = Input.Cin<long>(); }
        long ans = 0;
        for (int i = 0; i < N; i++)
        {
            long nowA = A[i] + ans;
            if (nowA % B[i] == 0) continue;
            long c = (long)Math.Floor(nowA / (B[i] + .0)) + 1;
            ans += c * B[i] - nowA;
        }
        Console.WriteLine(ans);
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
        else return (T)(object)("");
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