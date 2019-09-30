using System;
using System.Linq;
using System.Collections.Generic;
using System.Numerics;
using static System.Console;

class Solver {
    Scanner sc = new Scanner();
    int ans = 0;
    int[,] g;
    int N;

    public void Solve() {
        N = sc.nextInt();
        var M = sc.nextInt();
        g = new int[N, N];
        for (int i = 0; i < M; i++) {
            var a = sc.nextInt();
            var b = sc.nextInt();
            g[a - 1, b - 1] = 1;
            g[b - 1, a - 1] = 1;
        }

        var lst = new List<int>();
        Dfs(lst, 1);

        WriteLine(ans);
    }

    void Dfs(List<int> lst, int n) {
        if (lst.Contains(n)) {
            return;
        }

        lst.Add(n);

        if (lst.Count == N) {
            ans++;
            return;
        }

        for (int i = 0; i < N; i++) {
            if (g[n - 1, i] == 1) {
                Dfs(new List<int>(lst), i + 1);
            }
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