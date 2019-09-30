using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int N = NextInt();
        Data[] d = new Data[N + 1];
        for (int i = 0; i <= N; i++)
        {
            d[i].Boss = 1;
            d[i].buka = new List<int>();
            d[i].cost = -INF;
        }
        for (int i = 2; i <= N; i++)
        {
            int b = NextInt();
            d[i].Boss = b;
            d[b].buka.Add(i);
        }

        //????DFS
        Stack<int> stack = new Stack<int>();
        stack.Push(1);
        while (stack.Count() != 0)
        {
            int x = stack.Pop();
            if (d[x].cost != -INF) continue;
            if (d[x].buka.Count() == 0)
            {
                d[x].cost = 1;
                stack.Push(d[x].Boss);
                continue;
            }
            int min = INF;
            int max = 0;
            bool fin = true;
            foreach (int i in d[x].buka)
            {
                if (d[i].cost == -INF)
                {
                    stack.Push(i);
                    fin = false;
                    break;
                }
                min = Math.Min(min, d[i].cost);
                max = Math.Max(max, d[i].cost);
            }
            if (fin) {
                d[x].cost = max + min + 1;
                stack.Push(d[x].Boss);
            }
        }
        Console.WriteLine(d[1].cost);
    }

    public struct Data
    {
        public int Boss;
        public List<int> buka;
        public int cost;
    }
}

public class Input
{
    private static Queue<string> q = new Queue<string>();
    private static void Confirm() { if (q.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) q.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(q.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(q.Dequeue()); }
    public static string NextString() { Confirm(); return q.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(q.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}