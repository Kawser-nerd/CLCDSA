// csc /r:System.Numerics.dll /optimize /checked [This File]

using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

public class DisjointSet {
    private int[] group;
    public DisjointSet(int n) {
        group = new int[n];
        Clear();
    }
    public bool Unite(int x, int y) {
        x = Root(x); y = Root(y);
        if (x == y) return false;
        if (group[y] < group[x]) return Unite(y, x);
        group[x] += group[y];
        group[y] = x;
        return true;
    }
    public bool IsSameSet(int x, int y) { return Root(x) == Root(y); }
    public int Root(int x) { return group[x] < 0 ? x : group[x] = Root(group[x]); }
    public int Size(int x) { return -group[Root(x)]; }
    public void Clear() {
        for (int i = 0; i < group.Length; i++) {
            group[i] = -1;
        }
    }
};

partial class Solver {

    char[][] Zoom(char[][] map) {
        var r = map.Length;
        var c = map[0].Length;
        var zoomed = Enumerable.Range(0, 3 * r).Select(_ => new char[3 * c]).ToArray();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int br = 3 * i;
                int bc = 3 * j;
                if (map[i][j] == '/') {
                    zoomed[br + 2][bc] = '*';
                    zoomed[br + 1][bc + 1] = '*';
                    zoomed[br][bc + 2] = '*';
                } else { // '\'
                    zoomed[br][bc] = '*';
                    zoomed[br + 1][bc + 1] = '*';
                    zoomed[br + 2][bc + 2] = '*';
                }
            }
        }
        return zoomed;
    }

    class Point {
        public int Row { get; set; }
        public int Col { get; set; }
    }

    bool Check(char[][] map, int[] courtiers) {
        var r = map.Length;
        var c = map[0].Length;
        var zoomed = Zoom(map);


        var points = new List<Point>();

        int rightest = 3 * c - 1;
        int bottom = 3 * r - 1;

        for (int i = 0; i < c; i++) {
            points.Add(new Point { Row = 0, Col = i * 3 + 1 });
        }
        for (int i = 0; i < r; i++) {
            points.Add(new Point { Row = i * 3 + 1, Col = rightest });
        }
        for (int i = 0; i < c; i++) {
            points.Add(new Point { Row = bottom, Col = rightest - (i * 3 + 1) });
        }
        for (int i = 0; i < r; i++) {
            points.Add(new Point { Row = bottom - (i * 3 + 1), Col = 0 });
        }
        int cc = 0;
        foreach (var p in points) {
            zoomed[p.Row][p.Col] = (char)('1' + cc++);
        }
        //cout.WriteLine(string.Join("\n", map.Select(z => new string(z))));
        //cout.WriteLine(string.Join("\n", zoomed.Select(z => new string(z))));

        var disjointSet = new DisjointSet((3 * r) * (3 * c));

        var zoomR = r * 3;
        var zoomC = c * 3;
        var toIndex = new Func<int, int, int>((row, col) => (row * zoomC) + col);

        for (int i = 0; i < zoomR; i++) {
            for (int j = 0; j < zoomC; j++) {
                if (i + 1 < zoomR) {
                    if (zoomed[i][j] != '*' && zoomed[i + 1][j] != '*') {
                        disjointSet.Unite(toIndex(i, j), toIndex(i + 1, j));
                    }
                }
                if (j + 1 < zoomC) {
                    if (zoomed[i][j] != '*' && zoomed[i][j + 1] != '*') {
                        disjointSet.Unite(toIndex(i, j), toIndex(i, j + 1));
                    }
                }
            }
        }

        for (int i = 0; i < courtiers.Length; i += 2) {
            int c1 = courtiers[i];
            int c2 = courtiers[i + 1];
            var p1 = points[c1];
            var p2 = points[c2];

            if (!disjointSet.IsSameSet(toIndex(p1.Row, p1.Col), toIndex(p2.Row, p2.Col))) {
                return false;
            }
        }

        //cout.WriteLine(string.Join("\n", zoomed.Select(z => new string(z))));
        return true;
    }

    public void Run() {
        var t = ni();
        int caseNo = 1;
        while (t-- > 0) {
            var R = ni();
            var C = ni();
            var courtiers = ni(2 * (R + C)).Select(n => n - 1).ToArray();

            var M = R * C;
            char[][] ans = null;

            for (int b = 0; b < (1 << M); b++) {
                var map = new char[R][];
                int cur = 0;
                for (int i = 0; i < R; i++) {
                    map[i] = new char[C];
                    for (int j = 0; j < C; j++) {
                        if (((1 << cur) & b) != 0) map[i][j] = '/';
                        else map[i][j] = '\\';
                        cur++;
                    }
                }
                if (Check(map, courtiers)) {
                    ans = map;
                    break;
                }
            }

            cout.WriteLine("Case #{0}:", caseNo++);
            if (ans != null) {
                foreach (var array in ans) {
                    cout.WriteLine(new string(array));
                }
            } else {
                cout.WriteLine("IMPOSSIBLE");
            }
        }
    }
}

// PREWRITEN CODE BEGINS FROM HERE
partial class Solver : Scanner {
    public static void Main(string[] args) {
        new Solver(Console.In, Console.Out).Run();
    }

    TextReader cin;
    TextWriter cout;

    public Solver(TextReader reader, TextWriter writer)
        : base(reader) {
        this.cin = reader;
        this.cout = writer;
    }
    public Solver(string input, TextWriter writer)
        : this(new StringReader(input), writer) {
    }

    public int ni() { return NextInt(); }
    public int[] ni(int n) { return NextIntArray(n); }
    public long nl() { return NextLong(); }
    public long[] nl(int n) { return NextLongArray(n); }
    public double nd() { return NextDouble(); }
    public string ns() { return Next(); }
}

public class Scanner {
    private TextReader Reader;
    private Queue<String> TokenQueue = new Queue<string>();
    private CultureInfo ci = CultureInfo.InvariantCulture;

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
