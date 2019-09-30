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
        int N = Reader.Int(), K = Reader.Int();
        var S = new long[1].Concat(Reader.IntArray(N).Select(a => (long)a - K)).ToArray();
        for (int i = 1; i <= N; i++) S[i] += S[i - 1];
        var tree = new WaveletTree(S);
        long ans = Enu.Range(0, N).Sum(i => (long)(N - i) - tree.Rank(i + 1, N + 1, S[i] - 1));
        Console.WriteLine(ans);
    }
}

public class WaveletTree
{
    int N;
    long[][] A;
    int[][] Left;
    long[] Sorted;

    public WaveletTree(long[] A)
    {
        N = A.Length;
        int logN = 1;
        while ((1 << logN) < N) logN++;
        this.A = new long[logN + 1][];
        Left = new int[logN + 1][];
        for (int depth = 0; depth <= logN; depth++)
        {
            this.A[depth] = new long[N];
            Left[depth] = new int[N];
        }
        var index = new int[N];
        for (int i = 0; i < N; i++) index[i] = i;
        Sorted = new long[N];
        Array.Copy(A, Sorted, N);
        Array.Sort(Sorted, index);
        for (int i = 0; i < N; i++) this.A[0][index[i]] = i;
        Init(0, N, 0);
    }

    void Init(int L, int R, int depth)
    {
        if (R - L <= 1) return;
        int mid = (L + R) >> 1, ai = L, bi = mid;
        for (int i = L; i < R; i++)
        {
            if (A[depth][i] < mid) A[depth + 1][ai++] = A[depth][i];
            else A[depth + 1][bi++] = A[depth][i];
            Left[depth][i] = ai - L;
        }
        Init(L, mid, depth + 1);
        Init(mid, R, depth + 1);
    }

    // K is 0-indexed
    public long KthNumber(int L, int R, int K)
    {
        int currL = 0, currR = N;
        K++;
        for (int depth = 0; currR - currL != 1; depth++)
        {
            int mid = (currL + currR) >> 1;
            int toL = Left[depth][R - 1];
            int outL = currL == L ? 0 : Left[depth][L - 1];
            int inL = toL - outL;
            if (inL >= K)
            {
                L = currL + outL;
                R = currL + toL;
                currR = mid;
            }
            else
            {
                L = mid + L - currL - outL;
                R = mid + R - currL - toL;
                K = K - inL;
                currL = mid;
            }
        }
        return Sorted[currL];
    }

    // Count A[i] == val
    public int Count(int L, int R, long val)
    {
        return Rank(L, R, val) - Rank(L, R, val - 1);
    }

    // Count A[i] <= val
    public int Rank(int L, int R, long val)
    {
        int currL = 0, currR = N, res = 0;
        for (int depth = 0; L < R && currR - currL > 1; depth++)
        {
            int outL = currL == L ? 0 : Left[depth][L - 1];
            int inL = Left[depth][R - 1] - outL;
            int mid = (currL + currR) >> 1;
            if (val < Sorted[mid])
            {
                L = currL + outL;
                R = L + inL;
                currR = mid;
            }
            else
            {
                res += inL;
                int inR = R - L - inL;
                L = mid + L - currL - outL;
                R = L + inR;
                currL = mid;
            }
        }
        if (currR - currL == 1 && R - L == 1 && Sorted[L] <= val) res++;
        return res;
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