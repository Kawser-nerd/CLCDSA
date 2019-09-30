using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class Solve {
    const int I = 2;
    const int J = 3;
    const int K = 4;

    static int[,] matrix = new int[,]{
        { 0, 0, 0, 0, 0 },
        { 0, 1, I, J, K },
        { 0, I, -1, K, -J },
        { 0, J, -K, -1, I },
        { 0, K, J, -I, -1 },
    };

    static int multipy(int a, int b) {
        if (a < 0) return -multipy(-a, b);
        if (b < 0) return -multipy(a, -b);
        return matrix[a, b];
    }

    static int Pow(int x, long n) {
        if (n == 0)
            return 1;
        else if (n % 2 != 0)
            return multipy(x, Pow(x, n - 1));
        else
            return Pow(multipy(x, x), n / 2);
    }

    static int multipy(char c, int x) {
        if (c == 'i') {
            return multipy(I, x);
        } else if (c == 'j') {
            return multipy(J, x);
        } else if (c == 'k') {
            return multipy(K, x);
        }
        throw new Exception();
    }
    static int multipy(int x, char c) {
        if (c == 'i') {
            return multipy(x, I);
        } else if (c == 'j') {
            return multipy(x, J);
        } else if (c == 'k') {
            return multipy(x, K);
        }
        throw new Exception();
    }

    static void Main(string[] args) {
        var scanner = new Scanner();
        var t = scanner.NextInt();
        int caseNo = 1;
        while (t-- > 0) {

            var L = scanner.NextLong();
            var X = scanner.NextLong();
            var S = scanner.Next();

            bool ans = false;

            int x = 1;

            foreach (var c in S) {
                x = multipy(x, c);
            }

            // ijk = -1
            if (Pow(x, X) == -1) {
                var extra = X - 100;
                if (extra > 0) {
                    X -= extra / 16 * 16;
                }
                if (Pow(x, X) != -1) throw new Exception();
                S = String.Concat(Enumerable.Repeat(S, (int)X));

                int firstI = -1;
                int firstK = -1;

                x = 1;
                for (int i = 0; i < S.Length; i++) {
                    x = multipy(x, S[i]);
                    if (x == I) {
                        firstI = i;
                        break;
                    }
                }

                x = 1;
                for (int i = S.Length - 1; i >= 0; i--) {
                    x = multipy(S[i], x);
                    if (x == K) {
                        firstK = i;
                        break;
                    }
                }
                if (firstI != -1 && firstK != -1 && firstI < firstK) {
                    ans = true;
                }
            } else {

                ans = false;
            }

            Console.WriteLine("Case #{0}: {1}", caseNo++, ans ? "YES" : "NO");
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

