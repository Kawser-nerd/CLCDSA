using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        string s = Cin<string>();
        Console.WriteLine(s.Replace("O","0").Replace("D", "0").Replace("I", "1")
            .Replace("Z", "2").Replace("S", "5").Replace("B", "8"));
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