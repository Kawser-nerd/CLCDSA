using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class Solver {
    public struct Point {
        public int Row, Col;
        public Point(int row, int col) {
            this.Row = row;
            this.Col = col;
        }
        public override string ToString() {
            return String.Format("({0},{1})", Row, Col);
        }
    }

    public class Omino {
        public List<Point> Points = new List<Point>();
        public void Normalize() {
            int minRow = Points.Min(p => p.Row);
            int minCol = Points.Min(p => p.Col);
            this.Points = Points
                .Select(p => new Point(p.Row - minRow, p.Col - minCol))
                .OrderBy(p => p.Row)
                .ThenBy(p => p.Col)
                .ToList();
        }

        public int Width {
            get {
                return Points.Max(p => p.Col) + 1;
            }
        }

        public int Height {
            get {
                return Points.Max(p => p.Row) + 1;
            }
        }

        public string GetId() {
            Normalize();
            return String.Join(",", Points);
        }

        public Omino Clone() {
            var clone = new Omino();
            clone.Points = this.Points.ToList();
            clone.Normalize();
            return clone;
        }

        public Omino Rotate() {
            var result = Clone();
            result.Points = result.Points.Select(p => new Point(p.Col, -p.Row)).ToList();
            result.Normalize();
            return result;
        }
        public Omino Reflect() {
            var result = Clone();
            result.Points = result.Points.Select(p => new Point(p.Row, -p.Col)).ToList();
            result.Normalize();
            return result;
        }
    }

    static int[] dx = new int[] { 0, 1, 0, -1 };
    static int[] dy = new int[] { 1, 0, -1, 0 };

    static IEnumerable<Omino> GetOmino(int N) {
        Omino init = new Omino();
        init.Points.Add(new Point(0, 0));
        init.Normalize();

        Queue<Omino> queue = new Queue<Omino>();

        queue.Enqueue(init);

        Dictionary<string, Omino> memo = new Dictionary<string, Omino>();

        while (queue.Count > 0) {
            var now = queue.Dequeue();

            var id = now.GetId();
            if (memo.ContainsKey(id)) continue;
            memo[id] = now;

            if (now.Points.Count >= N) continue;

            foreach (var p in now.Points) {
                for (int i = 0; i < 4; i++) {
                    int nr = p.Row + dy[i];
                    int nc = p.Col + dx[i];
                    if (!now.Points.Any(q => q.Row == nr && q.Col == nc)) {
                        var next = now.Clone();
                        next.Points.Add(new Point(nr, nc));
                        queue.Enqueue(next);
                    }
                }
            }
        }

        return memo.Values.Where(v => v.Points.Count == N).ToArray();
    }

    static int FloodFill(bool[,] table, int row, int col) {
        if (table[row, col]) return 0;
        table[row, col] = true;
        int cnt = 1;
        for (int i = 0; i < 4; i++) {
            int nr = row + dy[i];
            int nc = col + dx[i];
            if (0 <= nr && nr < table.GetLength(0) && 0 <= nc && nc < table.GetLength(1) && table[nr, nc] == false) {
                cnt += FloodFill(table, nr, nc);
            }
        }
        return cnt;
    }

    static bool Check(Omino omino, int R, int C, int X) {
        var width = omino.Width;
        var height = omino.Height;
        if (width > C) return false;
        if (height > R) return false;
        //if (width + 2 <= C && height + 2 <= R) return true;
        for (int i = 0; i + height - 1 < R; i++) {
            for (int j = 0; j + width - 1 < C; j++) {
                var table = new bool[R, C];
                foreach (var p in omino.Points) {
                    table[p.Row + i, p.Col + j] = true;
                }
                bool ok = true;
                for (int p = 0; p < R && ok; p++) {
                    for (int q = 0; q < C && ok; q++) {
                        if (!table[p, q]) {
                            var cnt = FloodFill(table, p, q);
                            if (cnt % X != 0) {
                                ok = false;
                                break;
                            }
                        }
                    }
                }
                if (ok) {
                    return true;
                }
            }
        }
        return false;
    }

    static bool Solve(int X, int R, int C) {
        if (R < 0 || C < 0) return false;
        if (R == 0 && C == 0) return true;
        if ((R * C) % X != 0) {
            return false;
        }

        if (X >= 7) return false;

        //if (X == 1) return true;
        //if (X == 2) return true;

        var ominos = GetOmino(X);

        foreach (var omino in ominos) {
            bool ok = false;
            var o = omino.Clone();
            for (int j = 0; j < 2; j++) {
                for (int i = 0; i < 4; i++) {
                    if (Check(o, R, C, X)) {
                        ok = true;
                        break;
                    }

                    o = o.Rotate();
                }
                if (ok) break;
                o = o.Reflect();
            }

            if (!ok) {
                return false;
            }
        }

        return true;
    }

    static void Main(string[] args) {
        Debug.Assert(Solve(5, 4, 5) == true);
        Debug.Assert(Solve(5, 2, 20) == false);
        Debug.Assert(Solve(5, 3, 5) == false);

        /*for (int k = 1; k <= 7; k++) {
            for (int i = 1; i <= 10; i++) {
                for (int j = 1; j <= 10; j++) {
                    if (Solve(k, i, j)) Console.WriteLine(" " + k + " " + i + " " + j);
                }
            }
        }*/

        var scanner = new Scanner();
        var t = scanner.NextInt();
        int caseNo = 1;
        while (t-- > 0) {
            var X = scanner.NextInt();
            var R = scanner.NextInt();
            var C = scanner.NextInt();

            bool win = Solve(X, R, C);

            Console.WriteLine("Case #{0}: {1}", caseNo++, win ? "GABRIEL" : "RICHARD");
        }
    }
}

public class Scanner {
    private TextReader Reader;
    private Queue<String> TokenQueue = new Queue<string>();
    private CultureInfo ci = new CultureInfo("en-US");

    public Scanner()
        : this(Console.In) {
    }

    public Scanner(TextReader reader) {
        this.Reader = reader;
    }

    public int NextInt() { return Int32.Parse(Next(), ci); }
    public long NextLong() { return Int64.Parse(Next(), ci); }
    public double NextDouble() { return double.Parse(Next(), ci); }
    public string[] NextArray(int size) {
        var array = new string[size];
        for (int i = 0; i < size; i++) array[i] = Next();
        return array;
    }
    public int[] NextIntArray(int size) {
        var array = new int[size];
        for (int i = 0; i < size; i++) array[i] = NextInt();
        return array;
    }

    public long[] NextLongArray(int size) {
        var array = new long[size];
        for (int i = 0; i < size; i++) array[i] = NextLong();
        return array;
    }

    public String Next() {
        if (TokenQueue.Count == 0) {
            if (!StockTokens()) throw new InvalidOperationException();
        }
        return TokenQueue.Dequeue();
    }

    public bool HasNext() {
        if (TokenQueue.Count > 0)
            return true;
        return StockTokens();
    }

    private bool StockTokens() {
        while (true) {
            var line = Reader.ReadLine();
            if (line == null) return false;
            var tokens = line.Trim().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            if (tokens.Length == 0) continue;
            foreach (var token in tokens)
                TokenQueue.Enqueue(token);
            return true;
        }
    }
}

