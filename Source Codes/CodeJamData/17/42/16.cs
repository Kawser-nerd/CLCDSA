// csc /r:System.Numerics.dll /optimize /checked [This File]

using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

using Weight = System.Int64;

public class MinCostFlowResult
{
    public Weight TotalCost;
    public Weight TotalFlow;
}

/// <summary>
/// Solve min-cost flow problem
/// Verified: SRM 635 Medium
/// </summary>
public class PrimalDual
{
    int N;
    List<List<Edge>> adjacents;

    class Edge
    {
        public int From, To;
        public Weight Flow, Capacity, Cost;
        public Edge Reverse;
        public Edge(int from, int to, Weight capacity, Weight cost, Weight flow = 0)
        {
            this.From = from;
            this.To = to;
            this.Cost = cost;
            this.Flow = flow;
            this.Capacity = capacity;
        }
        public Weight Residue()
        {
            return Capacity - Flow;
        }
    }

    public PrimalDual(int n)
    {
        this.N = n;
        this.adjacents = new List<List<Edge>>();
        for (int i = 0; i < n; i++)
        {
            this.adjacents.Add(new List<Edge>());
        }
    }

    public void AddEdge(int from, int to, Weight capacity, Weight cost)
    {
        Edge e = new Edge(from, to, capacity, cost);
        adjacents[from].Add(e);
    }

    Edge[] FindShortestPathTree(int source)
    {
        Weight[] distance = new Weight[N];
        Edge[] prevEdges = new Edge[N];
        Queue<int> queue = new Queue<int>();
        bool[] inQueue = new bool[N];
        for (int i = 0; i < N; i++) distance[i] = Weight.MaxValue;
        distance[source] = 0;
        inQueue[source] = true;
        queue.Enqueue(source);
        while (queue.Count > 0)
        { // SPFA
            var now = queue.Dequeue();
            inQueue[now] = false;
            foreach (var e in adjacents[now])
            {
                if (e.Residue() <= 0) continue;
                if (distance[now] != Weight.MaxValue && distance[e.To] > distance[now] + e.Cost)
                {
                    distance[e.To] = distance[now] + e.Cost;
                    prevEdges[e.To] = e;
                    if (!inQueue[e.To])
                    {
                        inQueue[e.To] = true;
                        queue.Enqueue(e.To);
                    }
                }
            }
        }
        return prevEdges;
    }

    public MinCostFlowResult Run(int source, int sink, Weight flow)
    {
        Weight totalCost = 0;
        Weight totalFlow = 0;

        while (totalFlow < flow)
        {
            var prevEdges = FindShortestPathTree(source);
            if (prevEdges[sink] == null) break;
            Weight incrementalFlow = flow - totalFlow;
            for (Edge e = prevEdges[sink]; e != null; e = prevEdges[e.From])
            {
                incrementalFlow = Math.Min(incrementalFlow, e.Residue());
            }
            for (Edge e = prevEdges[sink]; e != null; e = prevEdges[e.From])
            {
                if (e.Reverse == null)
                {
                    Edge reverseEdge = new Edge(e.To, e.From, 0, -e.Cost);
                    reverseEdge.Reverse = e;
                    e.Reverse = reverseEdge;
                    adjacents[e.To].Add(reverseEdge);
                }
                totalCost += e.Cost * incrementalFlow;
                e.Flow += incrementalFlow;
                e.Reverse.Flow -= incrementalFlow;
            }
            totalFlow += incrementalFlow;
        }
        return new MinCostFlowResult { TotalCost = totalCost, TotalFlow = totalFlow };
    }
}
partial class Solver
{
    public class Seat
    {
        public int Id { get; set; }
        public int SeatNo { get; set; }
        public int PersonNo { get; set; }
    }

    public void Run()
    {
        var t = ni();
        int caseNo = 1;
        while (t-- > 0)
        {
            var N = ni();
            var C = ni();
            var M = ni();
            var P = new int[M];
            var B = new int[M];
            for (int i = 0; i < M; i++)
            {
                P[i] = ni();
                B[i] = ni();
            }

            var seats = new List<Seat>();

            for (int i = 0; i < M; i++)
            {
                seats.Add(new Seat { Id = i, SeatNo = P[i], PersonNo = B[i] });
            }

            long minimumRide = 0;
            long minimumPromotion = 0;

            var seats1 = seats.Where(s => s.PersonNo == 1).Select(s => s.SeatNo).OrderBy(s => s).ToList();
            var seats2 = seats.Where(s => s.PersonNo == 2).Select(s => s.SeatNo).OrderBy(s => s).ToList();

            int NN = Math.Max(seats1.Count, seats2.Count);
            while (seats1.Count < NN) seats1.Add(-1);
            while (seats2.Count < NN) seats2.Add(-1);

            var source = NN + NN;
            var sink = source + 1;
            PrimalDual PD = new PrimalDual(sink + 1);
            var IN = new Func<int, int>(n => n);
            var OUT = new Func<int, int>(n => n + NN);
            long OFFSET = 10000;
            for (int i = 0; i < NN; i++)
            {
                PD.AddEdge(source, IN(i), 1, 0);
            }
            for (int i = 0; i < NN; i++)
            {
                PD.AddEdge(OUT(i), sink, 1, 0);
            }

            for (int i = 0; i < NN; i++)
            {
                for (int j = 0; j < NN; j++)
                {
                    var s1 = seats1[i];
                    var s2 = seats2[j];
                    if (s1 == -1 || s2 == -1)
                    {
                        PD.AddEdge(IN(i), OUT(j), 1, OFFSET);
                    }
                    else if (s1 == 1 && s2 == 1)
                    {
                        PD.AddEdge(IN(i), OUT(j), 1, 2 * OFFSET);
                    }
                    else if (s1 == s2)
                    {
                        PD.AddEdge(IN(i), OUT(j), 1, 1 * OFFSET + 1);
                    }
                    else
                    {
                        PD.AddEdge(IN(i), OUT(j), 1, 1 * OFFSET);
                    }
                }
            }

            var result = PD.Run(source, sink, 1 << 28);
            minimumRide = result.TotalCost / OFFSET;
            minimumPromotion = result.TotalCost % OFFSET;

            cout.WriteLine("Case #{0}: {1} {2}", caseNo++, minimumRide, minimumPromotion);
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
