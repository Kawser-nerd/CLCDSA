using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using Enu = System.Linq.Enumerable;

class Solution {
    void calc() {
        String s = Console.ReadLine();
        BigInteger l = new BigInteger();
        l = s.Aggregate(l, (current, c) => current * 10 + (c - '0'));

        BigInteger r = (l + 1) * (l + 1) - 1;
        l = l * l;
        while ((l + 99) / 100 <= r / 100) {
            l = (l + 99) / 100;
            r /= 100;
        }
        Console.WriteLine(l);
    }

    static void Main(string[] args) {
        new Solution().calc();
    }

    #region
    static int ri() { return int.Parse(Console.ReadLine()); }
    static int[] ria(int n) {
        if (n <= 0) { Console.ReadLine(); return new int[0]; }
        else return Console.ReadLine().Trim().Split(' ').Select(int.Parse).ToArray();
    }
    static void rio(out int p1) { p1 = ri(); }
    static void rio(out int p1, out int p2) { var r = ria(2); p1 = r[0]; p2 = r[1]; }
    static void rio(out int p1, out int p2, out int p3) { var r = ria(3); p1 = r[0]; p2 = r[1]; p3 = r[2]; }
    static void rio(out int p1, out int p2, out int p3, out int p4) { var r = ria(4); p1 = r[0]; p2 = r[1]; p3 = r[2]; p4 = r[3]; }
    static void rio(out int p1, out int p2, out int p3, out int p4, out int p5) { var r = ria(5); p1 = r[0]; p2 = r[1]; p3 = r[2]; p4 = r[3]; p5 = r[4]; }
    static long rl() { return long.Parse(Console.ReadLine()); }
    static long[] rla(int n) {
        if (n <= 0) { Console.ReadLine(); return new long[0]; }
        else return Console.ReadLine().Trim().Split(' ').Select(long.Parse).ToArray();
    }
    static void rlo(out long p1) { p1 = rl(); }
    static void rlo(out long p1, out long p2) { var r = rla(2); p1 = r[0]; p2 = r[1]; }
    static void rlo(out long p1, out long p2, out long p3) { var r = rla(3); p1 = r[0]; p2 = r[1]; p3 = r[2]; }
    static void rlo(out long p1, out long p2, out long p3, out long p4) { var r = rla(4); p1 = r[0]; p2 = r[1]; p3 = r[2]; p4 = r[3]; }
    static void rlo(out long p1, out long p2, out long p3, out long p4, out long p5) { var r = rla(5); p1 = r[0]; p2 = r[1]; p3 = r[2]; p4 = r[3]; p5 = r[4]; }
    static double rd() { return double.Parse(Console.ReadLine()); }
    static double[] rda(int n) {
        if (n <= 0) { Console.ReadLine(); return new double[0]; }
        else return Console.ReadLine().Trim().Split(' ').Select(double.Parse).ToArray();
    }
    static void rdo(out double p1) { p1 = rd(); }
    static void rdo(out double p1, out double p2) { var r = rda(2); p1 = r[0]; p2 = r[1]; }
    static void rdo(out double p1, out double p2, out double p3) { var r = rda(3); p1 = r[0]; p2 = r[1]; p3 = r[2]; }
    static void rdo(out double p1, out double p2, out double p3, out double p4) { var r = rda(4); p1 = r[0]; p2 = r[1]; p3 = r[2]; p4 = r[3]; }
    static void rdo(out double p1, out double p2, out double p3, out double p4, out double p5) { var r = rda(5); p1 = r[0]; p2 = r[1]; p3 = r[2]; p4 = r[3]; p5 = r[4]; }
    static void swap<T>(ref T x, ref T y) { T temp = x; x = y; y = temp; }
    static void wa1<T>(T[] a) { Debug.WriteLine(string.Join(" ", a)); }
    static void wa2<T>(T[][] a) {
        foreach (var row in a) {
            Debug.WriteLine(String.Join(" ", row));
        }
    }
    [DebuggerDisplay("{x} , {y}")]
    class point<T> {
        public T x, y;
        public point(T x, T y) {
            this.x = x; this.y = y;
        }
    }
    #endregion
}

static class Extention {
    public static T[][] ToJagArray<T>(this T[,] a) {
        int n = a.GetLength(0), m = a.GetLength(1);
        var ret = new T[n][];
        for (int i = 0; i < n; i++) {
            ret[i] = new T[m];
            for (int j = 0; j < m; j++) {
                ret[i][j] = a[i, j];
            }
        }
        return ret;
    }

    public static bool InRange<T>(this T[,] a, int i, int j) {
        int n = a.GetLength(0), m = a.GetLength(1);
        return 0 <= i && i < n && 0 <= j && j < m;
    }
}