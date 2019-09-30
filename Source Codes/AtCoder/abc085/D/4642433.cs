using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private const long INFINITY = 9223372036854775807;
    public static void Main()
    {
        int N = NextInt();
        int H = NextInt();

        PriorityQueue<int, int[]> PQ = new PriorityQueue<int, int[]>(false);

        for (int i = 0; i < N; i++)
        {
            int a = NextInt();
            int b = NextInt();
            PQ.Enqueue(a, new int[2] { 0, a });
            PQ.Enqueue(b, new int[2] { 1, b });
        }
        long ans = 0;
        while (H > 0)
        {
            var v = PQ.Top();
            H -= v[1];
            if (v[0] == 1) { v = PQ.Dequeue(); }
            else {
                ans += (H / v[1]);
                H -= (H / v[1]) * v[1];
            }
            ans++;
        }
        Console.WriteLine(ans);
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
    public Tvalue Top()
    {
        return value[0];
    }
    public Tkey TopKey()
    {
        return list[0];
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