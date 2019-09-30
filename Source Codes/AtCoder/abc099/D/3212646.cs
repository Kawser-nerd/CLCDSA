using System;
using System.Linq;
using System.Collections.Generic;
using System.Numerics;
using static System.Console;

class Solver {
    Scanner sc = new Scanner();

    public void Solve() {
        int N = sc.nextInt();
        int C = sc.nextInt();
        var D = new int[C, C];
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < C; j++) {
                D[i, j] = sc.nextInt();
            }
        }
        var c = new int[N, N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                c[i, j] = sc.nextInt();
            }
        }

        var zero = new long[C];
        var one = new long[C];
        var two = new long[C];
        for (int k = 0; k < C; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if ((i + j + 2) % 3 == 0) {
                        zero[k] += D[c[i, j] - 1, k];
                    } else if ((i + j + 2) % 3 == 1) {
                        one [k] += D[c[i, j] - 1, k];
                    } else {
                        two[k] += D[c[i, j] - 1, k];
                    }
                }
            }
        }

        var min = long.MaxValue;
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < C; j++) {
                if (i == j) continue;
                for (int k = 0; k < C; k++) {
                    if (i == k) continue;
                    if (j == k) continue;

                    min = Math.Min(min, zero[i] + one[j] + two[k]);
                }
            }
        }
        WriteLine(min);
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