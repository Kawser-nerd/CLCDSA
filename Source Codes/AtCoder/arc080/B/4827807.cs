using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private const long INFINITY = 9223372036854775807;
    private struct Pair { public int x, y; }
    public static void Main()
    {
        //input
        int H = NextInt();
        int W = NextInt();
        int N = NextInt();
        int[] a = LineInt();
        PriorityQueue<int, int> PQ = new PriorityQueue<int, int>();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < a[i]; j++) PQ.Add(i + 1, i + 1);
        int[,] ans = new int[H, W];
        for (int i = 0; i < H; i++)
        {
            bool f = i % 2 == 0;
            for (int j = (f ? 0 : W - 1); j != (f ? W : -1); j += (f ? 1 : -1))
            {
                ans[i, j] = PQ.Take();
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) Console.Write(ans[i,j]+" ");
            Console.WriteLine();
        }
    }
}


public class PriorityQueue<Tkey, Tvalue> where Tkey : IComparable
{
    private static List<Tkey> keys = new List<Tkey>();
    private static List<Tvalue> values = new List<Tvalue>();
    private int size = 0;
    private static bool Descending;
    private static int Compare(Tkey a, Tkey b) { return (Descending ? a.CompareTo(b) : b.CompareTo(a)); }

    public PriorityQueue(bool b = true) { Clear(); Descending = b; }
    public int Count() { return size; }
    public void Clear() { keys = new List<Tkey>(); values = new List<Tvalue>(); size = 0; }
    public void Add(Tkey e, Tvalue v)
    {
        keys.Add(e);
        values.Add(v);
        int x = size;
        size += 1;
        while (x != 0)
        {
            int par = (x % 2 == 0 ? x - 2 : x - 1) / 2;
            if (Compare(keys[par], e) <= 0) break;
            Tkey a = keys[x]; keys[x] = keys[par]; keys[par] = a;
            Tvalue b = values[x]; values[x] = values[par]; values[par] = b;
            x = par;
        }
    }
    public void Poll()
    {
        Tkey k = keys[size - 1];
        Tvalue v = values[size - 1];
        int x = 0;
        size--;
        if (size == 0) { Clear(); return; }
        keys.RemoveAt(size);
        values.RemoveAt(size);
        while (true)
        {
            int l = x * 2 + 1;
            int r = x * 2 + 2;
            if (size - 1 < l) break;
            int y = 0;
            if (size - 1 == l) { y = l; }
            else if (Compare(keys[l], keys[r]) == 1) { y = r; }
            else { y = l; }
            if (Compare(keys[y], k) > 0) break;
            keys[x] = keys[y];
            values[x] = values[y];
            x = y;
        }
        keys[x] = k;
        values[x] = v;
    }
    public Tvalue Take() { Tvalue ret = values[0]; Poll(); return ret; }
    public Tvalue Peek() { return values[0]; }
}

public class Input
{
    private static Queue<string> q = new Queue<string>();
    private static void Confirm() { if (q.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) q.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(q.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(q.Dequeue()); }
    public static char NextChar() { Confirm(); return char.Parse(q.Dequeue()); }
    public static string NextString() { Confirm(); return q.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(q.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}