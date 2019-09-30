using System;
using System.Linq;
using System.Collections.Generic;
using System.Numerics;
using static System.Console;

class Solver {
    Scanner sc = new Scanner();

    public void Solve() {
        var N = sc.nextInt();
        var M = sc.nextInt();
        var arr = new long[N, 3];
        for (int i = 0; i < N; i++) {
            arr[i, 0] = sc.nextLong();
            arr[i, 1] = sc.nextLong();
            arr[i, 2] = sc.nextLong();
        }

        var D = 3;
        var ans = new long[8];
        for (int i = 0; i < (1 << D); i++) {
            var hoge = new long[N];
            for (int k = 0; k < N; k++) {
                long sum = 0;
                for (int j = 0; j < D; j++) {
                    if ((1 & i >> j) == 1) {
                        sum += arr[k, j];
                    } else {
                        sum -= arr[k, j];
                    }
                }
                hoge[k] = sum;
            }
            ans[i] = hoge.OrderByDescending(l => l).Take(M).Sum();
        }
        WriteLine(ans.Max());
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