using System;
using System.Collections.Generic;
using System.Linq;

public static class Iter {
    private static IEnumerable<T[]> Product_1<T>(int p, T[] buf, List<List<T>> pools) {
        if (p == buf.Length) {
            yield return buf;
        }
        else {
            foreach (var e in pools[p]) {
                buf[p] = e;
                foreach (var ret in Product_1(p+1, buf, pools)) {
                    yield return ret;
                }
            }
        }
    }

    public static IEnumerable<T[]> Product<T>(IEnumerable<T> xs, int repeat = 1) {
        var pools = new List<List<T>>(Enumerable.Repeat(xs.ToList(), repeat));
        return Product_1(0, new T[pools.Count], pools);
    }
}

class Program {
    static string ReadLine() { return Console.ReadLine(); }
    static int ReadInt() { return int.Parse(ReadLine()); }
    static int[] ReadInts() { return ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return ReadLine().Split(); }

    static void Display<T>(T[,] xs) {
        int rows = xs.GetLength(0);
        int cols = xs.GetLength(1);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Console.Write("{0} ", xs[i, j]);
            }
            Console.WriteLine();
        }
    }

    static void Fill<T>(T[,] xs, T val) {
        for (int i = 0; i < xs.GetLength(0); i++)
            for (int j = 0; j < xs.GetLength(1); j++)
                xs[i, j] = val;
    }

    static void Calc(List<string> xs) {
        int rows = xs.Count;
        int cols = xs[0].Length;

        var cs = new char[rows, cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int cnt = 0;
                foreach (var d in Iter.Product(new[] { -1, 0, 1 }, 2)) {
                    int r = i + d[0];
                    int c = j + d[1];
                    if (r < 0 || r >= rows || c < 0 || c >= cols || xs[r][c] == '#') {
                        cnt++;
                    }
                }
                cs[i, j] = cnt == 9 ? '#' : '.';
            }
        }

        var cs2 = new char[rows, cols];
        Fill(cs2, '.');
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (cs[i, j] == '.') continue;

                foreach (var d in Iter.Product(new[] { -1, 0, 1 }, 2)) {
                    int r = i + d[0];
                    int c = j + d[1];
                    if (r < 0 || r >= rows || c < 0 || c >= cols) continue;
                    cs2[r, c] = '#';
                }
            }
        }

        bool ok = true;
        for (int i = 0; i < rows; i++) {
            var t = string.Join("", Enumerable.Range(0, cols).Select(e => cs2[i, e]));
            if (xs[i] != t) {
                ok = false;
                break;
            }
        }

        if (ok) {
            Console.WriteLine("possible");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    Console.Write(cs[i, j]);
                }
                Console.WriteLine();
            }
        }
        else {
            Console.WriteLine("impossible");
        }
    }

    static void Main() {
        var hw = ReadInts();
        int rows = hw[0];
        var ss = new List<string>();
        for (int i = 0; i < rows; i++) {
            ss.Add(ReadLine());
        }
        Calc(ss);
    }
}