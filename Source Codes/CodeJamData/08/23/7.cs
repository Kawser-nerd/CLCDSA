using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

class Program
{

    static int[] remove(int[] p, int index)
    {
        int[] ret = new int[p.Length - 1];
        int c = 0;
        for (int i = index + 1; i < p.Length; ++i)
        {
            ret[c] = p[i];
            ++c;
        }
        for (int i = 0; i < index; ++i)
        {
            ret[c] = p[i];
            ++c;
        }
        return ret;
    }
    static void Main(string[] args)
    {
        using (SpaceDelimReader sr = new SpaceDelimReader(args[0]))
        {
            int tst = sr.NextInt();
            for (int cas = 1; cas <= tst; ++cas)
            {
                int k = sr.NextInt();
                int n = sr.NextInt();
                var index = sr.NextInt(n);
                int[] a = new int[k];
                for (int i = 0; i < k; ++i) a[i] = i;
                int[] res = new int[k];
                for (int i = 0; i < k; ++i)
                {
                    int ii = i % (k - i);
                    res[a[ii]] = i + 1;
                    a = remove(a, ii);
                }
                Console.Write("Case #{0}: ", cas);
                Console.WriteLine(string.Join(" ", index.Select(i => res[i - 1].ToString()).ToArray()));
            }
        }
    }
}


public class SpaceDelimReader : StreamReader
{
    string[] Buffer;
    int cur;
    public SpaceDelimReader(string FileName)
        : base(FileName)
    {
        Buffer = ReadToEnd().Split(" \r\n".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
        cur = 0;
    }

    public int NextInt()
    {
        int ret = Int32.Parse(Buffer[cur]);
        ++cur;
        return ret;
    }

    public int[] NextInt(int n)
    {
        int[] ret = new int[n];
        for (int i = 0; i < n; ++i)
        {
            ret[i] = Int32.Parse(Buffer[cur]);
            ++cur;
        }
        return ret;
    }

    public string NextString()
    {
        string ret = Buffer[cur];
        ++cur;
        return ret;
    }

    public string[] NextString(int n)
    {
        string[] ret = new string[n];
        Array.Copy(Buffer, cur, ret, 0, n);
        cur += n;
        return ret;
    }

    public class UEdge
    {
        public int from;
        public int to;
    }

    public UEdge NextUEdge()
    {
        UEdge ret = new UEdge();
        ret.from = NextInt();
        ret.to = NextInt();
        return ret;
    }




    public UEdge NextUEdge1()
    {
        UEdge ret = new UEdge();
        ret.from = NextInt() - 1;
        ret.to = NextInt() - 1;
        return ret;
    }

    public UEdge[] NextUEdge(int n)
    {
        UEdge[] ret = new UEdge[n];
        for (int i = 0; i < n; ++i)
        {
            ret[i] = NextUEdge();
        }
        return ret;
    }

    public UEdge[] NextUEdge1(int n)
    {
        UEdge[] ret = new UEdge[n];
        for (int i = 0; i < n; ++i)
        {
            ret[i] = NextUEdge1();
        }
        return ret;
    }


}


public static class Permutation
{
    public static bool NextPermutation(this int[] p)
    {
        for (int i = p.Length - 2; i >= 0; --i)
        {
            if (p[i] < p[i + 1])
            {
                Array.Reverse(p, i + 1, p.Length - i - 1);
                for (int j = i + 1; ; ++j)
                {
                    if (p[i] < p[j])
                    {
                        int temp = p[i]; p[i] = p[j]; p[j] = temp;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    public static IEnumerable<int[]> AllPermutations(this int[] p)
    {
        Array.Sort(p);
        do
        {
            yield return p;
        } while (p.NextPermutation());

    }

    public static IEnumerable<int[]> AllPermutations(this int p)
    {
        int[] a = new int[p];
        for (int i = 0; i < p; ++i)
        {
            a[i] = i;
        }
        return a.AllPermutations();
    }
}


public class Utility
{

    public static int bits(int p)
    {
        if (p == 0)
        {
            return 0;
        }
        else
        {
            return bits(p & (p - 1)) + 1;
        }
    }

    public class MaskIndexPair
    {
        public int mask;
        public int i;
    };

    public static IEnumerable<int> GetFreeBits(int n, int mask)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((mask & (1 << i)) == 0)
            {
                yield return i;
            }
        }
    }

    public static IEnumerable<MaskIndexPair> GetFreeMaskIndexPairs(int n, int mask)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((mask & (1 << i)) == 0)
            {
                yield return new MaskIndexPair { mask = mask ^ (1 << i), i = i };
            }
        }

    }

    public static IEnumerable<int> GetUsedBits(int n, int mask)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((mask & (1 << i)) != 0)
            {
                yield return i;
            }
        }
    }

    public static IEnumerable<MaskIndexPair> GetUsedMaskIndexPairs(int n, int mask)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((mask & (1 << i)) != 0)
            {
                yield return new MaskIndexPair { mask = mask ^ (1 << i), i = i };
            }
        }

    }



    public static IEnumerable<int> GenerateMask(int n)
    {
        for (int i = 0; i < (1 << n); ++i)
        {
            yield return i;
        }
    }


    public static IEnumerable<int> GenerateMask1(int n)
    {
        for (int i = 1; i < (1 << n); ++i)
        {
            yield return i;
        }
    }


    public static IEnumerable<int> GenerateMask(int n, int b)
    {
        for (int i = 0; i < (1 << n); ++i)
        {
            if (bits(i) == b)
            {
                yield return i;
            }
        }
    }

    public static T[,] Get2DArrayWithDefault<T>(int n1, int n2, T val)
    {
        T[,] ret = new T[n1, n2];
        for (int i = 0; i < n1; ++i)
        {
            for (int j = 0; j < n2; ++j)
            {
                ret[i, j] = val;
            }
        }
        return ret;
    }




    public static void swap<T>(ref T a, ref T b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    public class IntPair
    {
        public int i;
        public int j;
    };

    public static IEnumerable<IntPair> GenerateCombPairs(int n)
    {
        for (int a = 0; a < n; ++a)
        {
            for (int b = a + 1; b < n; ++b)
            {
                yield return new IntPair { i = a, j = b };
            }
        }
    }

    public class IntTetra
    {
        public int i;
        public int j;
        public int k;
        public int l;
    };

    public static IEnumerable<IntTetra> Generate(int n1, int n2, int n3, int n4)
    {
        for (int a = 0; a < n1; ++a)
        {
            for (int b = 0; b < n2; ++b)
            {
                for (int c = 0; c < n3; ++c)
                {
                    for (int d = 0; d < n4; ++d)
                    {
                        yield return new IntTetra { i = a, j = b, k = c, l = d };
                    }
                }
            }
        }
    }


    public class IntTriple
    {
        public int i;
        public int j;
        public int k;
    };

    public static IEnumerable<IntTriple> Generate(int n1, int n2, int n3)
    {
        for (int a = 0; a < n1; ++a)
        {
            for (int b = 0; b < n2; ++b)
            {
                for (int c = 0; c < n3; ++c)
                {
                    yield return new IntTriple { i = a, j = b, k = c };
                }
            }
        }
    }

}



public class Maze
{
    public class Cell
    {
        public int r;
        public int c;

        public IEnumerable<Cell> Get4()
        {
            int[] dr = { -1, 0, 1, 0 };
            int[] dc = { 0, -1, 0, 1 };
            for (int i = 0; i < 4; ++i)
            {
                int tr = r + dr[i];
                int tc = c + dc[i];
                yield return new Cell { r = tr, c = tc };
            }
        }

        public IEnumerable<Cell> Get4(Func<int, int, bool> predicate)
        {
            int[] dr = { -1, 0, 1, 0 };
            int[] dc = { 0, -1, 0, 1 };
            for (int i = 0; i < 4; ++i)
            {
                int tr = r + dr[i];
                int tc = c + dc[i];
                if (predicate(tr, tc))
                {
                    yield return new Cell { r = tr, c = tc };
                }
            }

        }



        public IEnumerable<Cell> Get4(int R, int C)
        {
            int[] dr = { -1, 0, 1, 0 };
            int[] dc = { 0, -1, 0, 1 };
            for (int i = 0; i < 4; ++i)
            {
                int tr = r + dr[i];
                int tc = c + dc[i];
                if (tr < 0 || tr >= R)
                {
                    continue;
                }
                if (tc < 0 || tc >= C)
                {
                    continue;
                }
                yield return new Cell { r = tr, c = tc };
            }
        }


    }

}















public abstract class BasicGraph
{
    protected int v;
    public abstract IEnumerable<int> GetEdges(int p);

    public int Compn()
    {
        bool[] visited = new bool[v];
        int ret = 0;
        foreach (var i in Enumerable.Range(0, v))
        {
            if (visited[i]) continue;
            visited[i] = true;
            ret++;
            Stack<int> s = new Stack<int>();
            s.Push(i);
            while (s.Count > 0)
            {
                int t1 = s.Pop();
                foreach (var j in GetEdges(t1))
                {
                    if (visited[j]) continue;
                    visited[j] = true;
                    s.Push(j);
                }
            }
        }
        return ret;
    }

}


public class MatrixGraph : BasicGraph
{
    bool[,] edge;
    public MatrixGraph(int n)
    {
        v = n;
        edge = new bool[n, n];
    }
    public override IEnumerable<int> GetEdges(int p)
    {
        for (int i = 0; i < v; ++i)
        {
            if (edge[p, i])
            {
                yield return i;
            }
        }
    }
    public void AddEdge(int i, int j)
    {
        edge[i, j] = edge[j, i] = true;
    }
}

public class ListGraph : BasicGraph
{
    List<int>[] edges;
    public ListGraph(int n)
    {
        v = n;
        edges = new List<int>[n];
        for (int i = 0; i < n; ++i)
        {
            edges[i] = new List<int>();
        }
    }

    public void AddEdge(int i, int j)
    {
        edges[i].Add(j);
        edges[j].Add(i);
    }

    public override IEnumerable<int> GetEdges(int p)
    {
        return edges[p];
    }

}


public class ObjectGraph<T> : ListGraph
{
    Dictionary<T, int> dic;
    public ObjectGraph(T[] names)
        : base(names.Length)
    {
        dic = Enumerable.Range(0, names.Length).ToDictionary(i => names[i]);
    }

    public void AddEdge(T a, T b)
    {
        base.AddEdge(dic[a], dic[b]);
    }
}


public class Point
{
    public double x;
    public double y;
    public Point()
    {
    }
    public Point(double xx, double yy)
    {
        x = xx;
        y = yy;
    }

    public static Point operator +(Point A, Point B)
    {
        return new Point(A.x + B.x, A.y + B.y);
    }

    public static Point operator -(Point A, Point B)
    {
        return new Point(A.x - B.x, A.y - B.y);
    }

    public static Point operator *(double c, Point A)
    {
        return new Point(A.x * c, A.y * c);
    }

    public static Point operator *(Point A, double c)
    {
        return new Point(A.x * c, A.y * c);
    }

    public static double operator ^(Point A, Point B)
    {
        return A.x * B.y - A.y * B.x;
    }
}

public static class ArrayExtension
{
    public static bool IsSorted(this int[] p)
    {
        int n = p.Length;
        for (int i = 1; i < n; ++i)
        {
            if (p[i] < p[i - 1])
            {
                return false;
            }
        }
        return true;
    }

    public static int FirstIndex<T>(this T[] p, Func<T, bool> predicate)
    {
        for (int i = 0; i < p.Length; ++i)
        {
            if (predicate(p[i]))
            {
                return i;
            }
        }
        return -1;
    }

    public static Utility.IntPair FirstIndex<T>(this T[][] p, Func<T, bool> predicate)
    {
        for (int a = 0; a < p.Length; ++a)
        {
            for (int b = 0; b < p[a].Length; ++b)
            {
                if (predicate(p[a][b]))
                {
                    return new Utility.IntPair { i = a, j = b };
                }
            }
        }
        return null;
    }

    public static ObjectWithIndex<T> FirstObject<T>(this T[] p, Func<T, bool> predicate)
    {
        for (int j = 0; j < p.Length; ++j)
        {
            if (predicate(p[j]))
            {
                return new ObjectWithIndex<T> { value = p[j], i = j };
            }
        }
        return null;
    }




    public static IEnumerable<ObjectWithIndex<T>> IndicesWhere<T>(this T[] p, Func<T, bool> predicate)
    {
        int index = 0;
        foreach (var v in p)
        {
            if (predicate(v))
            {
                yield return new ObjectWithIndex<T> { value = v, i = index };
            }
            ++index;
        }
    }





    public static IEnumerable<ObjectWith2DIndex<T>> IndicesWhere2<T>(this T[][] p, Func<T, bool> predicate)
    {
        int r1 = 0;
        foreach (var v1 in p)
        {
            int c1 = 0;
            foreach (var v2 in v1)
            {
                if (predicate(v2))
                {
                    yield return new ObjectWith2DIndex<T> { value = v2, r = r1, c = c1 };
                }
                ++c1;
            }
            ++r1;
        }
    }

    public static void Foreach<T>(this T[] p, Action<T, int> f)
    {
        for (int i = 0; i < p.Length; ++i)
        {
            f(p[i], i);
        }
    }


    public class ObjectWithIndex<T>
    {
        public T value;
        public int i;
    }

    public class ObjectWith2DIndex<T>
    {
        public T value;
        public int r;
        public int c;
    }




}

public static class EnumerationExt
{

    public static void Foreach<T>(this IEnumerable<T> enumeration, Action<T> action)
    {
        foreach (var v in enumeration)
        {
            action(v);
        }
    }
    public static HashSet<T> ToHashSet<T>(this IEnumerable<T> enumeration)
    {
        HashSet<T> ret = new HashSet<T>();
        foreach (var v in enumeration)
        {
            ret.Add(v);
        }
        return ret;
    }





    public static Dictionary<T, int> CreateIndexDictionary<T>(this IEnumerable<T> p)
    {
        Dictionary<T, int> ret = new Dictionary<T, int>();
        int index = 0;
        foreach (var t in p)
        {
            ret[t] = index;
            ++index;
        }
        return ret;
    }
}

public static class StringExtensions
{
    public static string Reverse(this string p)
    {
        char[] ch = p.ToCharArray();
        Array.Reverse(ch);
        return new string(ch);
    }

    public static string Sort(this string p)
    {
        char[] ch = p.ToCharArray();
        Array.Sort(ch);
        return new string(ch);
    }

    public static int IntValue(this string p)
    {
        return Int32.Parse(p);
    }

    public static int[] IntArrayValue(this string p)
    {
        return (from s in p.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries) select s.IntValue()).ToArray();
    }

    public static long LongValue(this string p)
    {
        return Int64.Parse(p);
    }

    public static double DoubleValue(this string p)
    {
        return Double.Parse(p);
    }

    public static IEnumerable<string> RegexSplit(this string s, string pattern)
    {
        foreach (Match v in Regex.Matches(s.ToLower(), "[a-z]+"))
        {
            yield return v.Value;
        }
    }


}


public class PriorityQueue<P, V>
{
    private SortedDictionary<P, Queue<V>> list = new SortedDictionary<P, Queue<V>>();
    public void Push(P p, V v)
    {
        Queue<V> q;
        if (!list.TryGetValue(p, out q))
        {
            q = new Queue<V>();
            list.Add(p, q);
        }
        q.Enqueue(v);
    }

    public V Pop()
    {
        var pair = list.First();
        var v = pair.Value.Dequeue();
        if (pair.Value.Count() == 0)
        {
            list.Remove(pair.Key);
        }
        return v;
    }

    public bool Empty
    {
        get { return list.Count != 0; }
    }
}
