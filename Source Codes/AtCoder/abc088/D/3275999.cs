using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Solver {
    Scanner sc = new Scanner();
    int H;
    int W;

    public void Solve() {
        H = sc.nextInt();
        W = sc.nextInt();
        var S = new string[H];
        for (int i = 0; i < H; i++) {
            S[i] = ReadLine();
        }

        var M = new List<Pair>[H*W];
        var num = 0;
        var black = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                var lst = new List<Pair>();
                if (i > 0 && S[i - 1][j] == '.') lst.Add(new Pair(1, num - W));
                if (j > 0 && S[i][j - 1] == '.') lst.Add(new Pair(1, num - 1));
                if (i < H - 1 && S[i + 1][j] == '.') lst.Add(new Pair(1, num + W));
                if (j < W - 1 && S[i][j + 1] == '.') lst.Add(new Pair(1, num + 1));
                M[num] = lst;
                num++;
                if (S[i][j] == '#') black++;
            }
        }

        var s = 0;
        var dist = new bool[num];
        var d = new int[num];
        for (int i = 0; i < num; i++) {
            d[i] = int.MaxValue;
        }
        d[s] = 0;

        var PQ = new PriorityQueue(num);

        PQ.Push(new Pair(0, s));

        while (!PQ.IsEmpty()) {
            var f = PQ.Pop();
            var u = f.Value;
            dist[u] = true;

            if (d[u] < f.Key) { continue; }

            for (int i = 0; i < M[u].Count; i++) {
                int v = M[u][i].Value;
                if (dist[v]) { continue; }
                if (d[u] + M[u][i].Key < d[v]) {
                    d[v] = d[u] + M[u][i].Key;
                    PQ.Push(new Pair(d[v], v));
                }
            }
        }

        if (d[num - 1] == int.MaxValue) {
            WriteLine(-1);
        } else {
            WriteLine((H * W) - black - d[num - 1] - 1);
        }

    }

    class Pair {
        public int Key { get; set; }
        public int Value { get; set; }

        public Pair(int key, int value) {
            Key = key;
            Value = value;
        }
    }

    class PriorityQueue {
        Pair[] A;
        int _cnt = 0;
        bool _asc;

        public PriorityQueue(int n, bool asc = true) {
            A = new Pair[500001];
            _asc = asc;
        }

        public void Push(Pair pair) {
            _cnt++;
            A[_cnt] = new Pair(int.MinValue, 0);
            HeapIncreaseKey(_cnt, pair);
        }

        public Pair Pop() {
            if (_cnt < 1) { return null; }
            var pop = A[1];
            A[1] = A[_cnt];
            A[_cnt] = null;
            _cnt--;
            Heapify(1);
            return pop;
        }

        public bool IsEmpty() {
            return _cnt == 0;
        }

        void HeapIncreaseKey(int i, Pair pair) {
            if (pair.Key <= A[i].Key) { return; }
            A[i] = pair;

            while (i > 1 && Compare(A[Parent(i)].Key, A[i].Key)) {
                Swap(Parent(i), i);
                i = Parent(i);
            }
        }

        bool Compare(int l, int r) {
            if (_asc) {
                return l > r;
            } else {
                return l < r;
            }
        }

        void Heapify(int i) {
            var l = i * 2;
            var r = i * 2 + 1;
            int largest;

            if (l <= _cnt && Compare(A[i].Key, A[l].Key)) {
                largest = l;
            } else {
                largest = i;
            }

            if (r <= _cnt && Compare(A[largest].Key, A[r].Key)) {
                largest = r;
            }

            if (largest != i) {
                Swap(i, largest);
                Heapify(largest);
            }
        }

        void Swap(int a, int b) {
            var tmp = A[a];
            A[a] = A[b];
            A[b] = tmp;
        }

        static int Parent(int i) { return i / 2; }
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