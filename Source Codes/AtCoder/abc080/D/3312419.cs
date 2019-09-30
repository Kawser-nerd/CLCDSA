using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Solver {
    Scanner sc = new Scanner();

    public void Solve() {
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] s, t, c;
        s = new int[N];
        t = new int[N];
        c = new int[N];
        var dic = new Dictionary<int, int[]>();
        for (int i = 0; i < N; i++) {
            s[i] = sc.nextInt();
            t[i] = sc.nextInt();
            c[i] = sc.nextInt();
            if (!dic.ContainsKey(c[i])) {
                dic.Add(c[i], new int[100001]);
            }
            for (int j = s[i]-1; j < t[i]; j++) {
                dic[c[i]][j] = 1;
            }
        }

        var sum = new int[100001];
        foreach (var kvp in dic) {
            for (int i = 0; i < 100001; i++) {
                sum[i] += kvp.Value[i];
            }
        }

        WriteLine(sum.Max());
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