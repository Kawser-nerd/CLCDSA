using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Hello
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int A = Cin<int>();
        int B = Cin<int>();
        int[] dp = Enumerable.Repeat(INF, 50).ToArray();
        dp[0] = 0;
        for (int i = 0; i < 50; i++)
        {
            if (i + 10 < 50) dp[i + 10] = Math.Min(dp[i + 10], dp[i] + 1);
            if (i + 5 < 50) dp[i + 5] = Math.Min(dp[i + 5], dp[i] + 1);
            if (i + 1 < 50) dp[i + 1] = Math.Min(dp[i + 1], dp[i] + 1);
        }
        for (int i = 49; i != -1; i--)
        {
            if (i - 10 > -1) dp[i - 10] = Math.Min(dp[i - 10], dp[i] + 1);
            if (i - 5 > -1) dp[i - 5] = Math.Min(dp[i - 5], dp[i] + 1);
            if (i - 1 > -1) dp[i - 1] = Math.Min(dp[i - 1], dp[i] + 1);
        }
        Console.WriteLine(dp[Math.Abs(B - A)]);
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
        else return (T)(object)(-1);
    }
    public static T Line<T>()
    {
        if (typeof(T) == typeof(int[]))
        {
            return (T)(object)Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        }
        else if (typeof(T) == typeof(long[]))
        {
            return (T)(object)Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        }
        else if (typeof(T) == typeof(string[]))
        {
            return (T)(object)Console.ReadLine().Split(' ').ToArray();
        }
        else if (typeof(T) == typeof(double[]))
        {
            return (T)(object)Console.ReadLine().Split(' ').Select(double.Parse).ToArray();
        }
        else return (T)(object)(-1);
    }
}