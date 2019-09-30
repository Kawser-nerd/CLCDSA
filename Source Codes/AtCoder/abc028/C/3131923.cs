using System;
using System.Linq;
using System.Collections.Generic;
using System.Numerics;
using static System.Console;

class Solver {
    Scanner sc = new Scanner();


    public void Solve() {
        var A = sc.ArrayInt(5);
        var bit = new int[][] {
            new int[] {1,1,1,0,0},
            new int[] {1,1,0,1,0},
            new int[] {1,1,0,0,1},
            new int[] {1,0,1,1,0},
            new int[] {1,0,1,0,1},
            new int[] {1,0,0,1,1},
            new int[] {0,1,1,1,0},
            new int[] {0,1,1,0,1},
            new int[] {0,1,0,1,1},
            new int[] {0,0,1,1,1}
        };

        var ans = new List<int>();
        for (int i = 0; i < bit.Length; i++) {
            var sum = 0;
            for (int j = 0; j < bit[i].Length; j++) {
                if (bit[i][j] == 1) {
                    sum += A[j];
                }
            }
            ans.Add(sum);
        }
        WriteLine(ans.OrderByDescending(i => i).ToArray()[2]);
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