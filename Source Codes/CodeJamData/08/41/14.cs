using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

class Program
{
    delegate int[] Doop(int a,int b,int c,int d);
    static int[] GetAnd(int left0, int left1, int right0, int right1)
    {
        int[] ret = new int[2];
        ret[0] = Math.Min(left0 + right1, left1 + right0);
        ret[0] = Math.Min(ret[0], left0 + right0);
        ret[1] = left1 + right1;
        return ret;
    }


    static int[] GetOr(int left0, int left1, int right0, int right1)
    {
        int[] ret = new int[2];
        ret[1] = Math.Min(left0 + right1, left1 + right0);
        ret[1] = Math.Min(ret[1], left1 + right1);
        ret[0] = left0 + right0;
        return ret;
    }


    static void Main(string[] args)
    {
        using (SpaceDelimReader sr = new SpaceDelimReader(args[0]))
        {
            int tst = sr.NextInt();
            for (int cas = 1; cas <= tst; ++cas)
            {
                int m = sr.NextInt();
                int v = sr.NextInt();
                int inter = (m - 1) / 2;
                int leaf = (m + 1) / 2;
                var ininter = sr.NextUEdge(inter);
                var g = ininter.Select(u => u.from).ToArray();
                var c = ininter.Select(u => u.to).ToArray();
                int[] lvalue = sr.NextInt(leaf);
                int[] cost0 = Enumerable.Repeat(100000, m).ToArray();
                int[] cost1 = Enumerable.Repeat(100000, m).ToArray();
                Doop[] func = new Doop[2];
                func[0] = GetOr;
                func[1] = GetAnd;
                for (int i = inter; i < m; ++i)
                {
                    int j = i - inter;
                    if (lvalue[j] == 0)
                    {
                        cost0[i] = 0;
                    }
                    else
                    {
                        cost1[i] = 0;
                    }
                }
                for (int i = inter - 1; i >= 0; --i)
                {
                    int left0 = cost0[2 * i + 1];
                    int left1 = cost1[2 * i + 1];
                    int right0 = cost0[2 * i + 2];
                    int right1 = cost1[2 * i + 2];
                    var res1 = func[g[i]](left0, left1, right0, right1);
                    cost0[i] = Math.Min(cost0[i], res1[0]);
                    cost1[i] = Math.Min(cost1[i], res1[1]);
                    if (c[i] == 1)
                    {
                        var res2 = func[1-g[i]](left0, left1, right0, right1);
                        cost0[i] = Math.Min(cost0[i], res2[0]+1);
                        cost1[i] = Math.Min(cost1[i], res2[1]+1);
                    }
                }
                int res = v == 0 ? cost0[0] : cost1[0];
                Console.Write("Case #{0}: ", cas);
                if (res >= 20000)
                {
                    Console.WriteLine("IMPOSSIBLE");
                }
                else
                {
                    Console.WriteLine(res);
                }
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
