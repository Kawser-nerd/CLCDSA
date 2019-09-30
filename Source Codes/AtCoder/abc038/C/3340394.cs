using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Solver {
    Scanner sc = new Scanner();

    public void Solve() {
        int N = sc.nextInt();
        var a = sc.ArrayInt(N);

        long ans = 0;
        var l = 0;
        var cnt = 1;
        for (int i = 1; i < N; i++) {
            var r = i + 1;
            if (a[i-1] < a[i] && l <= i && i < r) {
                cnt++;
            } else {
                if (cnt != 1) {
                    ans += Combination.Calc(cnt, 2);    
                }
                l = i + 1;
                cnt = 1;
            }
        }
        if (cnt != 1) {
            ans += Combination.Calc(cnt, 2);
        }

        WriteLine(ans + N);
    }

    class Combination {
        //static int mod = 1000000007;

        public static long Calc(int a, int b) {
            if (b > a - b) return Calc(a, a - b);

            long ansMul = 1;
            long ansDiv = 1;
            for (int i = 0; i < b; i++) {
                ansMul *= (a - i);
                ansDiv *= (i + 1);
                //ansMul %= mod;
                //ansDiv %= mod;
            }

            return ansMul / ansDiv;
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