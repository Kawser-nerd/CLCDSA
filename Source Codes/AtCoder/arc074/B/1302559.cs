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
        var A = Reader.IntArray(N * 3);
        var L = new AVLTreeMultiSet();
        var R = new AVLTreeMultiSet();
        foreach (int a in A) R.Add(a);
        long ans = long.MinValue;

        for (int i = 0; ; i++)
        {
            L.Add(A[i]);
            R.Remove(A[i]);
            if (R.Count < N) break;
            if (L.Count >= N) ans = Math.Max(ans, L.Sum(L.Count - N) - R.Sum(0, N));
        }

        Console.WriteLine(ans);
    }
}


public class AVLTreeMultiSet
{
    public struct Node
    {
        public int L, R, Count;
        public byte MaxDepth;
        public long Val;
        public long Sum;
    }

    const int PoolSize = (int)3e5;
    const int None = 0, NotFound = -1;
    Node[] nodes = new Node[PoolSize + 1];
    int nodeIndex = 1;

    public int Count { get { return nodes[Root].Count; } }
    public int MaxDepth { get { return nodes[Root].MaxDepth; } }
    int Root = None;

    int GenNode(long val)
    {
        nodes[nodeIndex].Val = val;
        nodes[nodeIndex].Sum = val;
        nodes[nodeIndex].MaxDepth = 1;
        nodes[nodeIndex].Count = 1;
        nodes[nodeIndex].L = nodes[nodeIndex].R = None;
        return nodeIndex++;
    }

    void Update(int i)
    {
        Debug.Assert(i != None);
        nodes[i].Count = 1 + nodes[nodes[i].L].Count + nodes[nodes[i].R].Count;
        nodes[i].MaxDepth = (byte)(1 + Math.Max(nodes[nodes[i].L].MaxDepth, nodes[nodes[i].R].MaxDepth));
        nodes[i].Sum = nodes[i].Val + nodes[nodes[i].L].Sum + nodes[nodes[i].R].Sum;
    }

    public void Clear() { Root = None; nodeIndex = 1; }

    public void Add(long val) { Root = Add(Root, GenNode(val), val); }
    int Add(int i, int newNodeIndex, long val)
    {
        if (i == None) return newNodeIndex;
        if (val < nodes[i].Val)
        {
            int child = Add(nodes[i].L, newNodeIndex, val);
            nodes[i].L = child; Update(i);
        }
        else
        {
            int child = Add(nodes[i].R, newNodeIndex, val);
            nodes[i].R = child; Update(i);
        }
        return Rebalance(i);
    }

    public long this[int index]
    {
        get
        {
            if (index < 0 || index >= Count) throw new ArgumentException();
            int i = Root, Lsize;
            while (index != (Lsize = nodes[nodes[i].L].Count))
                if (index < Lsize) i = nodes[i].L;
                else { index -= Lsize + 1; i = nodes[i].R; }
            return nodes[i].Val;
        }
    }

    public bool Contains(long val)
    {
        for (int i = Root; i != None; )
            if (val == nodes[i].Val) return true;
            else if (val < nodes[i].Val) i = nodes[i].L;
            else i = nodes[i].R;
        return false;
    }


    // Count node.Val < val
    public int LowerBound(long val) { long d; return LowerBound(val, out d); }
    public int LowerBound(long val, out long resVal)
    {
        int index = 0;
        resVal = long.MaxValue;
        for (int i = Root; i != None; )
            if (nodes[i].Val >= val) { resVal = nodes[i].Val; i = nodes[i].L; }
            else { index += 1 + nodes[nodes[i].L].Count; i = nodes[i].R; }
        return index;
    }

    // Count node.Val <= val
    public int UpperBound(long val) { long d; return UpperBound(val, out d); }
    public int UpperBound(long val, out long resVal)
    {
        int index = 0;
        resVal = long.MaxValue;
        for (int i = Root; i != None; )
            if (nodes[i].Val > val) { resVal = nodes[i].Val; i = nodes[i].L; }
            else { index += 1 + nodes[nodes[i].L].Count; i = nodes[i].R; }
        return index;
    }


    public bool Remove(long val)
    {
        int node = Remove(Root, val);
        if (node == NotFound) return false;
        Root = node;
        return true;
    }
    int Remove(int i, long val)
    {
        if (i == None) return NotFound;
        if (val == nodes[i].Val) return RemoveNode(i);
        if (val < nodes[i].Val)
        {
            int child = Remove(nodes[i].L, val);
            if (child == NotFound) return NotFound;
            nodes[i].L = child; Update(i);
        }
        else
        {
            int child = Remove(nodes[i].R, val);
            if (child == NotFound) return NotFound;
            nodes[i].R = child; Update(i);
        }
        return Rebalance(i);
    }

    public void RemoveAt(int index)
    {
        if (index < 0 || index >= Count) throw new ArgumentException();
        Root = RemoveAt(index, Root);
    }
    int RemoveAt(int index, int i)
    {
        int Lsize = nodes[nodes[i].L].Count;
        if (index == Lsize) return RemoveNode(i);
        if (index < Lsize)
            nodes[i].L = RemoveAt(index, nodes[i].L);
        else
            nodes[i].R = RemoveAt(index - Lsize - 1, nodes[i].R);
        Update(i);
        return Rebalance(i);
    }
    int RemoveNode(int i)
    {
        int L = nodes[i].L, R = nodes[i].R;
        if (L == None && R == None) return None;
        if (L == None) return R;
        if (R == None) return L;
        int minNode = 0;
        R = MoveMin(R, ref minNode);
        nodes[minNode].L = L;
        nodes[minNode].R = R;
        Update(minNode);
        return Rebalance(minNode);
    }
    int MoveMin(int i, ref int minNode)
    {
        if (nodes[i].L == None) { minNode = i; return nodes[i].R; }
        nodes[i].L = MoveMin(nodes[i].L, ref minNode);
        Update(i);
        return Rebalance(i);
    }

    public long Sum(int L = 0, int R = int.MaxValue) { return Sum(Root, L, R); }
    long Sum(int i, int L, int R)
    {
        if (R <= 0 || L >= nodes[i].Count) return 0;
        if (L <= 0 && R >= nodes[i].Count) return nodes[i].Sum;
        int Lsize = nodes[nodes[i].L].Count;
        long sum = L <= Lsize && R > Lsize ? nodes[i].Val : 0;
        sum += Sum(nodes[i].L, L, R);
        sum += Sum(nodes[i].R, L - Lsize - 1, R - Lsize - 1);
        return sum;
    }


    public long[] ToArray()
    {
        var res = new long[Count];
        if (Count == 0) return res;
        ToArrayRec(Root, 0, res);
        return res;
    }
    void ToArrayRec(int i, int resL, long[] res)
    {
        int Lsize = nodes[nodes[i].L].Count;
        if (Lsize > 0) ToArrayRec(nodes[i].L, resL, res);
        res[resL + Lsize] = nodes[i].Val;
        if (nodes[i].R != None) ToArrayRec(nodes[i].R, resL + Lsize + 1, res);
    }


    int Rebalance(int i)
    {
        int L = nodes[i].L, R = nodes[i].R;
        switch (nodes[L].MaxDepth - nodes[R].MaxDepth)
        {
            case 2:
                if (nodes[nodes[L].L].MaxDepth < nodes[nodes[L].R].MaxDepth)
                    RotateLR(i);
                return RotateLL(i);
            case -2:
                if (nodes[nodes[R].R].MaxDepth < nodes[nodes[R].L].MaxDepth)
                    RotateRL(i);
                return RotateRR(i);
            default:
                return i;
        }
    }
    void RotateLR(int i)
    {
        int A = nodes[i].L, B = nodes[A].R;
        nodes[A].R = nodes[B].L; Update(A);
        nodes[B].L = A; Update(B);
        nodes[i].L = B; Update(i);
    }
    int RotateLL(int i)
    {
        int B = nodes[i].L;
        nodes[i].L = nodes[B].R; Update(i);
        nodes[B].R = i; Update(B);
        return B;
    }
    void RotateRL(int i)
    {
        int A = nodes[i].R, B = nodes[A].L;
        nodes[A].L = nodes[B].R; Update(A);
        nodes[B].R = A; Update(B);
        nodes[i].R = B; Update(i);
    }
    int RotateRR(int i)
    {
        int B = nodes[i].R;
        nodes[i].R = nodes[B].L; Update(i);
        nodes[B].L = i; Update(B);
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
    public static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
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