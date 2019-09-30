using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    public void Solve()
    {
        int N = Reader.Int();
        var E = EdgeRead(N);
        var deg = E.Select(e => (long)e.Length).ToArray();
        var set = new AVLTreeSortedSet();
        for (int i = 0; i < N; i++)
            set.Add((deg[i] << 32) + i);

        Action<int> RemoveV = a =>
        {
            set.Remove((deg[a] << 32) + a);
            deg[a] = 0;
            foreach (int b in E[a])
                if (deg[b] > 0)
                {
                    set.Remove((deg[b] << 32) + b);
                    deg[b]--;
                    set.Add((deg[b] << 32) + b);
                }
        };
        for (; set.Count > 1; )
        {
            int a = (int)set[0];
            if (deg[a] == 0) break;
            Debug.Assert(deg[a] == 1);
            int b = Array.Find(E[a], x => deg[x] > 0);
            RemoveV(a);
            RemoveV(b);
        }

        Console.WriteLine(set.Count > 0 && (set[0] >> 32) == 0 ? "First" : "Second");
    }

    int[][] EdgeRead(int V, int E = -1, int origin = 1)
    {
        if (E == -1) E = V - 1;
        var es = new List<int>[V];
        for (int i = 0; i < V; i++) es[i] = new List<int>();
        for (int i = 0; i < E; i++)
        {
            int a = Reader.Int() - origin, b = Reader.Int() - origin;
            es[a].Add(b);
            es[b].Add(a);
        }
        return es.Select(a => a.ToArray()).ToArray();
    }
}

public class AVLTreeSortedSet
{
    public class Node
    {
        public int Count;
        public Node L, R;
        public byte MaxDepth;
        public long Val;
        //public long Sum;
    }

    static readonly Node NoneNode;
    Node Root = NoneNode;

    static AVLTreeSortedSet()
    {
        NoneNode = new Node();
        NoneNode.L = NoneNode.R = NoneNode;
    }

    public int Count { get { return Root.Count; } }
    public int MaxDepth { get { return Root.MaxDepth; } }

    static Node GenNode(long val)
    {
        var node = new Node();
        node.Val = val;
        //node.Sum = val;
        node.MaxDepth = 1;
        node.Count = 1;
        node.L = node.R = NoneNode;
        return node;
    }

    void Update(Node n)
    {
        n.Count = 1 + n.L.Count + n.R.Count;
        n.MaxDepth = (byte)(1 + Math.Max(n.L.MaxDepth, n.R.MaxDepth));
        //n.Sum = n.Val + n.L.Sum + n.R.Sum;
    }

    public void Clear() { Root = NoneNode; }

    public bool Add(long val) { return Add(ref Root, GenNode(val), val); }
    bool Add(ref Node n, Node newNode, long val)
    {
        if (n.Count == 0) { n = newNode; return true; }
        if (n.Val == val) return false;
        if (val < n.Val) Add(ref n.L, newNode, val);
        else Add(ref n.R, newNode, val);
        Update(n);
        n = Rebalance(n);
        return true;
    }

    public long this[int index]
    {
        get
        {
            if (index < 0 || index >= Count) throw new ArgumentException();
            Node n = Root;
            for (int Lsize; (Lsize = n.L.Count) != index; )
                if (index < Lsize) n = n.L;
                else { index -= Lsize + 1; n = n.R; }
            return n.Val;
        }
    }

    public bool Contains(long val)
    {
        for (Node n = Root; n.Count != 0; )
            if (val == n.Val) return true;
            else if (val < n.Val) n = n.L;
            else n = n.R;
        return false;
    }

    public int IndexOf(long val)
    {
        Node n = Root;
        for (int index = 0; n.Count != 0; )
            if (val == n.Val) return index + n.L.Count;
            else if (val < n.Val) n = n.L;
            else { index += n.L.Count + 1; n = n.R; }
        return -1;
    }

    // Count node.Val < val
    public int LowerBound(long val) { long d; return LowerBound(val, out d); }
    public int LowerBound(long val, out long resVal)
    {
        int index = 0;
        resVal = long.MaxValue;
        for (Node n = Root; n.Count != 0; )
            if (n.Val >= val) { resVal = n.Val; n = n.L; }
            else { index += 1 + n.L.Count; n = n.R; }
        return index;
    }

    // Count node.Val <= val
    public int UpperBound(long val) { long d; return UpperBound(val, out d); }
    public int UpperBound(long val, out long resVal)
    {
        int index = 0;
        resVal = long.MaxValue;
        for (Node n = Root; n.Count != 0; )
            if (n.Val > val) { resVal = n.Val; n = n.L; }
            else { index += 1 + n.L.Count; n = n.R; }
        return index;
    }


    public bool Remove(long val) { return Remove(ref Root, val); }
    bool Remove(ref Node n, long val)
    {
        if (n.Count == 0) return false;
        if (val == n.Val) { n = RemoveNode(n); return true; }
        if (val < n.Val) { if (!Remove(ref n.L, val)) return false; }
        else if (!Remove(ref n.R, val)) return false;
        Update(n);
        n = Rebalance(n);
        return true;
    }

    public long RemoveAt(int index)
    {
        if (index < 0 || index >= Count) throw new ArgumentException();
        long resVal;
        Root = RemoveAt(Root, index, out resVal);
        return resVal;
    }
    Node RemoveAt(Node n, int index, out long resVal)
    {
        if (index == n.L.Count) { resVal = n.Val; return RemoveNode(n); }
        if (index < n.L.Count)
            n.L = RemoveAt(n.L, index, out resVal);
        else
            n.R = RemoveAt(n.R, index - n.L.Count - 1, out resVal);
        Update(n);
        return Rebalance(n);
    }

    Node RemoveNode(Node n)
    {
        Node L = n.L, R = n.R;
        if (L.Count == 0) return R;
        if (R.Count == 0) return L;
        Node minNode = NoneNode;
        R = MoveMin(R, ref minNode);
        Debug.Assert(minNode.Count > 0);
        minNode.L = L;
        minNode.R = R;
        Update(minNode);
        return Rebalance(minNode);
    }
    Node MoveMin(Node n, ref Node minNode)
    {
        if (n.L.Count == 0) { minNode = n; return n.R; }
        n.L = MoveMin(n.L, ref minNode);
        Update(n);
        return Rebalance(n);
    }

    //public long Sum(int L = 0, int R = int.MaxValue) { return Sum(Root, L, R); }
    //long Sum(Node n, int L, int R)
    //{
    //    if (R <= 0 || L >= n.Count) return 0;
    //    if (L <= 0 && R >= n.Count) return n.Sum;
    //    int Lsize = n.L.Count;
    //    long sum = L <= Lsize && R > Lsize ? n.Val : 0;
    //    sum += Sum(n.L, L, R);
    //    sum += Sum(n.R, L - Lsize - 1, R - Lsize - 1);
    //    return sum;
    //}

    public long[] ToArray()
    {
        var res = new long[Count];
        if (Count == 0) return res;
        ToArrayRec(Root, 0, res);
        return res;
    }
    void ToArrayRec(Node n, int resL, long[] res)
    {
        int Lsize = n.L.Count;
        if (Lsize > 0) ToArrayRec(n.L, resL, res);
        res[resL + Lsize] = n.Val;
        if (n.R.Count > 0) ToArrayRec(n.R, resL + Lsize + 1, res);
    }


    Node Rebalance(Node n)
    {
        Node L = n.L, R = n.R;
        switch (n.L.MaxDepth - n.R.MaxDepth)
        {
            case 2:
                if (n.L.L.MaxDepth < n.L.R.MaxDepth) RotateLR(n);
                return RotateLL(n);
            case -2:
                if (n.R.R.MaxDepth < n.R.L.MaxDepth) RotateRL(n);
                return RotateRR(n);
            default:
                return n;
        }
    }
    void RotateLR(Node n)
    {
        Node A = n.L, B = A.R;
        A.R = B.L; Update(A);
        B.L = A; Update(B);
        n.L = B; Update(n);
    }
    Node RotateLL(Node n)
    {
        Node B = n.L;
        n.L = B.R; Update(n);
        B.R = n; Update(B);
        return B;
    }
    void RotateRL(Node n)
    {
        Node A = n.R, B = A.L;
        A.L = B.R; Update(A);
        B.R = A; Update(B);
        n.R = B; Update(n);
    }
    Node RotateRR(Node n)
    {
        Node B = n.R;
        n.R = B.L; Update(n);
        B.L = n; Update(B);
        return B;
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
    static void Init() { Dispose(); A = new string[0]; }
    public static void Set(TextReader r) { Init(); reader = r; }
    public static void Set(string file) { Init(); reader = new StreamReader(file); }
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
    public static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
    public static void Dispose() { reader.Dispose(); }
    static string[] Split(string s) { return s.Split(separator, op); }
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