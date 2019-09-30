using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Solver {
    Scanner sc = new Scanner();

    public void Solve() {
        int Q = sc.nextInt();
        var prime = GeneratePrimeList(100000);
        var cnt = 0;
        var arr = new int[100001];
        for (int i = 0; i <= 100000; i++) {
            if (prime[i] && prime[(i+1) / 2]) {
                cnt++;
            }
            arr[i] = cnt;
        }

        for (int i = 0; i < Q; i++) {
            var l = sc.nextInt();
            var r = sc.nextInt();
            WriteLine(arr[r] - arr[l-1]);
        }
    }

    bool[] GeneratePrimeList(int n) {
        n++;
        var isPrime = new bool[n];
        for (int i = 2; i < n; i++) isPrime[i] = true;
        var sqrt = (int)Math.Sqrt(n);
        for (int i = 2; i <= sqrt; i++) {
            if (isPrime[i]) {
                var j = i + i;
                while (j < n) {
                    isPrime[j] = false;
                    j += i;
                }
            }
        }
        return isPrime;
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