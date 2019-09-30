using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    static readonly long Big = (long)1e9;

    public void Solve()
    {
        int H = Reader.Int(), W = Reader.Int(), N = Reader.Int();
        var sw = Stopwatch.StartNew();
        var table = Reader.IntTable(N);
        var set = new AVLTreeSortedSet(N * 9);
        var black = new AVLTreeSortedSet(N);
        var ans = new long[10];
        ans[0] = (long)(H - 2) * (W - 2);
        Func<int, int, bool> IsInside = (r, c) => r >= 0 && r < H && c >= 0 && c < W;

        foreach (var t in table)
        {
            black.Add(--t[0] * Big + --t[1]);
            for (int dr = -2; dr <= 0; dr++)
                for (int dc = -2; dc <= 0; dc++)
                    if (IsInside(t[0] + dr, t[1] + dc))
                        set.Add((t[0] + dr) * Big + t[1] + dc);
        }
        long add = sw.ElapsedMilliseconds;
        foreach (long mask in set.ToArray())
        {
            long r = mask / Big, c = mask % Big;
            if (r + 3 <= H && c + 3 <= W)
            {
                int count = 0;
                for (int dr = 0; dr < 3; dr++)
                    for (int dc = 0; dc < 3; dc++)
                        if (black.Contains((r + dr) * Big + c + dc))
                            count++;
                ans[0]--;
                ans[count]++;
            }
        }
        Console.WriteLine(string.Join("\n", ans));
        //Console.WriteLine("Rotate:" + set.RotateCount);
        //Console.WriteLine("Add:   " + add + "ms");
    }


    public class AVLTreeSortedSet
    {
        public struct Node
        {
            public int L, R, Count;
            public byte MaxDepth;
            public long Val;

            public Node(long val)
            {
                L = R = None;
                MaxDepth = 1;
                Count = 1;
                Val = val;
            }
        }

        public int Count { get { return nodes[Root].Count; } }
        static readonly int None = 0;
        int Root = 0, nodesIndex = 1;
        Node[] nodes;
        public long RotateCount;

        public AVLTreeSortedSet(int maxSize)
        {
            nodes = new Node[maxSize + 1];
        }

        int GenNode(long val)
        {
            nodes[nodesIndex] = new Node(val);
            return nodesIndex++;
        }

        void SetChild(int i, ref int p, int childIndex)
        {
            p = childIndex;
            nodes[i].Count = 1 + nodes[nodes[i].L].Count + nodes[nodes[i].R].Count;
            nodes[i].MaxDepth = (byte)(1 + Math.Max(nodes[nodes[i].L].MaxDepth, nodes[nodes[i].R].MaxDepth));
        }

        public bool Add(long val)
        {
            int node = Add(Root, GenNode(val), val);
            if (node == None) return false;
            Root = node;
            return true;
        }
        int Add(int i, int newNodeIndex, long val)
        {
            if (i == None) return newNodeIndex;
            if (val == nodes[i].Val) return None;
            int A, B;

            if (val < nodes[i].Val)
            {
                int child = Add(nodes[i].L, newNodeIndex, val);
                if (child == None) return None;
                SetChild(i, ref nodes[i].L, child);
                if (nodes[nodes[i].L].MaxDepth - nodes[nodes[i].R].MaxDepth <= 1) return i;

                A = nodes[i].L;
                if (nodes[nodes[A].L].MaxDepth < nodes[nodes[A].R].MaxDepth)
                {
                    RotateCount++;
                    B = nodes[A].R;
                    SetChild(A, ref nodes[A].R, nodes[B].L);
                    SetChild(B, ref nodes[B].L, A);
                    SetChild(i, ref nodes[i].L, B);
                }

                RotateCount++;
                B = nodes[i].L; A = nodes[B].L;
                SetChild(i, ref nodes[i].L, nodes[B].R);
                SetChild(B, ref nodes[B].R, i);
                Debug.Assert(Math.Abs(nodes[nodes[i].L].MaxDepth - nodes[nodes[i].R].MaxDepth) <= 1);

                return B;
            }
            else
            {
                int child = Add(nodes[i].R, newNodeIndex, val);
                if (child == None) return None;
                SetChild(i, ref nodes[i].R, child);
                if (nodes[nodes[i].L].MaxDepth - nodes[nodes[i].R].MaxDepth >= -1) return i;

                A = nodes[i].R;
                if (nodes[nodes[A].R].MaxDepth < nodes[nodes[A].L].MaxDepth)
                {
                    RotateCount++;
                    B = nodes[A].L;
                    SetChild(A, ref nodes[A].L, nodes[B].R);
                    SetChild(B, ref nodes[B].R, A);
                    SetChild(i, ref nodes[i].R, B);
                }

                RotateCount++;
                B = nodes[i].R; A = nodes[B].R;
                SetChild(i, ref nodes[i].R, nodes[B].L);
                SetChild(B, ref nodes[B].L, i);
                Debug.Assert(Math.Abs(nodes[nodes[i].L].MaxDepth - nodes[nodes[i].R].MaxDepth) <= 1);

                return B;
            }
        }

        public bool Contains(long val)
        {
            for (int i = Root; i != None; )
            {
                if (nodes[i].Val == val) return true;
                if (val < nodes[i].Val) i = nodes[i].L;
                else i = nodes[i].R;
            }
            return false;
        }

        public long[] ToArray()
        {
            long[] res = new long[Count];
            if (Count == 0) return res;
            ToArrayRec(Root, 0, res);
            return res;
        }
        void ToArrayRec(int i, int resL, long[] res)
        {
            int Lsize = (nodes[i].L == None ? 0 : nodes[nodes[i].L].Count);
            if (Lsize > 0) ToArrayRec(nodes[i].L, resL, res);
            res[resL + Lsize] = nodes[i].Val;
            if (nodes[i].R != None) ToArrayRec(nodes[i].R, resL + Lsize + 1, res);
        }
    }
}


class Entry { static void Main() { new Program().Solve(); } }
class Reader
{
    static TextReader reader = Console.In;
    static readonly char[] separator = { ' ' };
    static readonly StringSplitOptions op = StringSplitOptions.RemoveEmptyEntries;
    static string[] A = new string[0];
    static int i;
    static void Init() { A = new string[0]; }
    public static void Set(TextReader r) { reader = r; Init(); }
    public static void Set(string file) { reader = new StreamReader(file); Init(); }
    public static bool HasNext() { return CheckNext(); }
    public static string String() { return Next(); }
    public static int Int() { return int.Parse(Next()); }
    public static long Long() { return long.Parse(Next()); }
    public static double Double() { return double.Parse(Next()); }
    public static int[] IntLine() { return Array.ConvertAll(Split(Line()), int.Parse); }
    public static int[] IntArray(int N) { return Range(N, Int); }
    public static int[][] IntTable(int H) { return Range(H, IntLine); }
    public static string[] StringArray(int N) { return Range(N, Next); }
    public static string[][] StringTable(int N) { return Range(N, () => Split(Line())); }
    public static string Line() { return reader.ReadLine().Trim(); }
    static string[] Split(string s) { return s.Split(separator, op); }
    static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
    static string Next() { CheckNext(); return A[i++]; }
    static bool CheckNext()
    {
        if (i < A.Length) return true;
        string line = reader.ReadLine();
        if (line == null) return false;
        if (line == "") return CheckNext();
        A = Split(line);
        i = 0;
        return true;
    }
}