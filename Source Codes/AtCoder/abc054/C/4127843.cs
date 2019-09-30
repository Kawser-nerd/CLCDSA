using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int N = Cin<int>();
        int M = Cin<int>();
        List<bool> visit = Enumerable.Repeat(false, N).ToList();
        Glaph glaph = new Glaph(visit);
        glaph.visit[0] = true;
        glaph.now_Node = 0;
        List<int>[] edge = new List<int>[N];
        for (int i = 0; i < N; i++) edge[i] = new List<int>();
        for (int i = 0; i < M; i++)
        {
            int[] inp = Line<int[]>().Select(v => v - 1).ToArray();
            edge[inp[0]].Add(inp[1]);
            edge[inp[1]].Add(inp[0]);
        }
        long ans = 0;
        Stack<Glaph> stack = new Stack<Glaph>();
        stack.Push(glaph);
        while (stack.Count() != 0)
        {
            Glaph now_state = stack.Pop();
            if (now_state.visit.All(v => v == true)) ans++;
            foreach (var i in edge[now_state.now_Node])
            {
                if (!now_state.visit[i])
                {
                    Glaph next_state = new Glaph(now_state.visit);
                    next_state.visit[i] = true;
                    next_state.now_Node = i;
                    stack.Push(next_state);
                }
            }
        }
        Console.WriteLine(ans);
    }
}

public class Glaph
{
    public List<bool> visit;
    public int now_Node { get; set; }
    public Glaph(List<bool> b) { visit = new List<bool>(b); }
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