using System;
using System.Linq;
using System.Collections.Generic;
using System.Numerics;
using static System.Console;

class Solver {
    Scanner sc = new Scanner();

    struct Zahyo {
        public int i;
        public int j;
    }

    public void Solve() {
        var H = sc.nextInt();
        var W = sc.nextInt();
        var D = sc.nextInt();
        var A = new int[H, W];
        var dic = new Dictionary<int, Zahyo>();
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                A[i, j] = sc.nextInt();
                dic.Add(A[i, j], new Zahyo { i = i, j = j });
            }
        }
        var Q = sc.nextInt();

        var cost = new int[H * W + 1];
        for (int i = 1 + D; i <= H * W; i++) {
            cost[i] = cost[i - D] + Math.Abs(dic[i - D].i - dic[i].i) + Math.Abs(dic[i - D].j - dic[i].j);
        }

        for (int i = 0; i < Q; i++) {
            var l = sc.nextInt();
            var r = sc.nextInt();
            WriteLine(cost[r] - cost[l]);
        }
    }
}



class Scanner {
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner() {
        s = new string[0];
        i = 0;
    }

    public string next() {
        if (i < s.Length) return s[i++];
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int nextInt() {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0) {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++) {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong() {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0) {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++) {
            Array[i] = nextLong() + add;
        }
        return Array;
    }

    public double nextDouble() {
        return double.Parse(next());
    }

    public double[] ArrayDouble(int N, double add = 0) {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++) {
            Array[i] = nextDouble() + add;
        }
        return Array;
    }
}

class Program {
    static void Main(string[] args) {
        Solver s = new Solver();
        s.Solve();
    }
}