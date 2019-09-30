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
        int M = NextInt();
        List<int>[] wf = new List<int>[N];
        for (int i = 0; i < N; i++) wf[i] = Enumerable.Repeat(INF, N).ToList();
        for (int i = 0; i < N; i++) wf[i][i] = 0;
        List<int>[] e = new List<int>[N];
        List<bool>[] e_b = new List<bool>[N];
        for (int i = 0; i < N; i++) e[i] = Enumerable.Repeat(-INF, N).ToList();
        for (int i = 0; i < N; i++) e_b[i] = Enumerable.Repeat(false, N).ToList();
        for (int i = 0; i < M; i++)
        {
            int A = NextInt() - 1;
            int B = NextInt() - 1;
            int Cost = NextInt();
            wf[A][B] = Cost;
            wf[B][A] = Cost;
            e[A][B]  = Cost;
            e[B][A]  = Cost;
            e_b[A][B] = true;
            e_b[B][A] = true;
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    wf[j][k] = Math.Min(wf[j][k], wf[j][i] + wf[i][k]);

        for (int s = 0; s < N; s++)
        {
            //??
            for (int i = 0; i < N; i++)
            {
                //??
                for (int j = 0; j < N; j++)
                {
                    if (!e_b[i][j]) continue;
                    //??
                    if (wf[s][i] + e[i][j] == wf[s][j])
                    {
                        e_b[i][j] = false;
                        e_b[j][i] = false;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) ans += e_b[i].Count(v => v == true);
        Console.WriteLine(ans / 2);
    }
}


public class PriorityQueue<Tkey, Tvalue> where Tkey : IComparable
{
    private static List<Tkey> list = new List<Tkey>();
    private static List<Tvalue> value = new List<Tvalue>();
    public int Count { get; private set; } = 0;
    private static bool Descending;
    public PriorityQueue(bool b = true) { Descending = b; }
    private static int Compare(Tkey a, Tkey b)
    {
        if (Descending) return a.CompareTo(b);
        else return b.CompareTo(a);
    }
    public void Enqueue(Tkey e, Tvalue n)
    {
        Count++;
        int now = Count - 1;
        list.Add(e);
        value.Add(n);
        while (now != 0)
        {
            int par = (now - 1) / 2;
            if (Compare(list[par], e) <= 0) break;
            Tkey a = list[now]; list[now] = list[par]; list[par] = a;
            Tvalue b = value[now]; value[now] = value[par]; value[par] = b;
            now = par;
        }
    }
    public Tvalue Dequeue()
    {
        if (Count == 0) return (Tvalue)(object)(-1);
        Tvalue e = value.First();
        if (Count == 1) { list = new List<Tkey>(); value = new List<Tvalue>(); Count--; return e; }
        Tkey x = list[Count - 1];
        Tvalue y = value[Count - 1];
        int i = 0;
        while (i * 2 + 1 < Count)
        {
            int l = i * 2 + 1;
            int r = i * 2 + 2;
            if (r < Count && Compare(list[r], list[l]) < 0) l = r;
            if (Compare(list[l], x) >= 0) break;
            list[i] = list[l];
            value[i] = value[l];
            i = l;
        }
        list[i] = x;
        value[i] = y;
        Count--;
        return e;
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