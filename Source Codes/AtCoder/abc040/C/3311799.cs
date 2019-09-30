using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Solver {
    Scanner sc = new Scanner();

    public void Solve() {
        int N = sc.nextInt();
        var a = sc.ArrayInt(N);

        var dp = new int[N];
        dp[1] = Math.Abs(a[1] - a[0]);
        for (int i = 2; i < N; i++) {
            dp[i] = Math.Min(dp[i - 1] + Math.Abs(a[i] - a[i - 1]),
                             dp[i - 2] + Math.Abs(a[i] - a[i - 2]));
        }
        WriteLine(dp[N - 1]);
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