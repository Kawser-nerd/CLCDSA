using System;
using System.Linq;
using System.Collections.Generic;
using System.Numerics;
using static System.Console;

class Solver {
    Scanner sc = new Scanner();

    class Ball {
        public int X { get; set; }
        public int Y { get; set; }
    }

    int N;

    public void Solve() {
        N = sc.nextInt();
        var red = new Ball[N];
        var blue = new Ball[N];
        for (int i = 0; i < N; i++) {
            var ball = new Ball { X = sc.nextInt(), Y = sc.nextInt() };
            red[i] = ball;
        }
        for (int i = 0; i < N; i++) {
            var ball = new Ball { X = sc.nextInt(), Y = sc.nextInt() };
            blue[i] = ball;
        }

        var ans = 0;
        var Red = red.ToList();
        var dist = new bool[N];
        blue = blue.OrderBy(b => b.X).ToArray();
        for (int i = 0; i < N; i++) {
            var ball = Red.Where(b => blue[i].X > b.X && blue[i].Y > b.Y)
                          .OrderByDescending(b => b.Y).FirstOrDefault();
            if (ball != null) {
                Red.Remove(ball);
                ans++;
            }

        }
        WriteLine(ans);
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