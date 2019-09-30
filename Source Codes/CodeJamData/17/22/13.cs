// csc /r:System.Numerics.dll /optimize /checked [This File]

using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

partial class Solver
{
    public class ColorNum
    {
        public char Charactor;
        public int Number;
    }

    public void Run()
    {
        var t = ni();
        int caseNo = 1;
        while (t-- > 0)
        {
            int N, R, O, Y, G, B, V;
            N = ni();
            R = ni();
            O = ni();
            Y = ni();
            G = ni();
            B = ni();
            V = ni();

            var colors = new ColorNum[]
            {
                new ColorNum { Charactor = 'R', Number = R },
                new ColorNum { Charactor = 'Y', Number = Y },
                new ColorNum { Charactor = 'B', Number = B },
            }.OrderByDescending(c => c.Number).ToArray();

            var ans = new char[N];

            bool failed = false;

            if (N == 1)
            {
                ans[0] = colors[0].Charactor;
            }
            else
            {
                for (int i = 0; i < N; i++)
                {
                    ans[i] = ' ';
                }

                for (int i = 0; i < N - 1; i += 2)
                {
                    if (colors[0].Number == 0) break;
                    colors[0].Number--;
                    ans[i] = colors[0].Charactor;
                }

                for (int i = (N % 2 == 0 ? N - 1 : N - 2); i >= 0; i -= 2)
                {
                    if (ans[i] != ' ' || colors[1].Number == 0) break;
                    colors[1].Number--;
                    ans[i] = colors[1].Charactor;
                }

                for (int i = 0; i < N; i++)
                {
                    if (colors[2].Number == 0) break;
                    if (ans[i] == ' ')
                    {
                        colors[2].Number--;
                        ans[i] = colors[2].Charactor;
                    }
                }
            }

            failed = ans.Contains(' ');

            cout.WriteLine("Case #{0}: {1}", caseNo++, failed ? "IMPOSSIBLE" : new string(ans));
        }
    }
}

// PREWRITEN CODE BEGINS FROM HERE
partial class Solver : Scanner
{
    public static void Main(string[] args)
    {
        new Solver(Console.In, Console.Out).Run();
    }

    TextReader cin;
    TextWriter cout;

    public Solver(TextReader reader, TextWriter writer)
        : base(reader)
    {
        this.cin = reader;
        this.cout = writer;
    }
    public Solver(string input, TextWriter writer)
        : this(new StringReader(input), writer)
    {
    }

    public int ni() { return NextInt(); }
    public int[] ni(int n) { return NextIntArray(n); }
    public long nl() { return NextLong(); }
    public long[] nl(int n) { return NextLongArray(n); }
    public double nd() { return NextDouble(); }
    public string ns() { return Next(); }
}

public class Scanner
{
    private TextReader Reader;
    private Queue<String> TokenQueue = new Queue<string>();
    private CultureInfo ci = CultureInfo.InvariantCulture;

    public Scanner()
        : this(Console.In)
    {
    }

    public Scanner(TextReader reader)
    {
        this.Reader = reader;
    }

    public int NextInt() { return Int32.Parse(Next(), ci); }
    public long NextLong() { return Int64.Parse(Next(), ci); }
    public double NextDouble() { return double.Parse(Next(), ci); }
    public string[] NextArray(int size)
    {
        var array = new string[size];
        for (int i = 0; i < size; i++) array[i] = Next();
        return array;
    }
    public int[] NextIntArray(int size)
    {
        var array = new int[size];
        for (int i = 0; i < size; i++) array[i] = NextInt();
        return array;
    }

    public long[] NextLongArray(int size)
    {
        var array = new long[size];
        for (int i = 0; i < size; i++) array[i] = NextLong();
        return array;
    }

    public String Next()
    {
        if (TokenQueue.Count == 0)
        {
            if (!StockTokens()) throw new InvalidOperationException();
        }
        return TokenQueue.Dequeue();
    }

    public bool HasNext()
    {
        if (TokenQueue.Count > 0)
            return true;
        return StockTokens();
    }

    private bool StockTokens()
    {
        while (true)
        {
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
