using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static int N, M;
    static bool[][] ConnectionTable;
    static bool[] VisitedTable;

    public static void Main(string[] args)
    {
        checked
        {
            N = Input.NextInt();
            M = Input.NextInt();

            ConnectionTable = new bool[N][];
            for (int i = 0; i < N; i++)
            {
                ConnectionTable[i] = new bool[N];
            }

            for (int i = 0; i < M; i++)
            {
                var s = Input.LineInt();
                var a = s[0] - 1;
                var b = s[1] - 1;
                ConnectionTable[a][b] = true;
                ConnectionTable[b][a] = true;
            }

            VisitedTable = new bool[N];

            NumberOfFound = 0;
            F(0, 0);

            Console.WriteLine(NumberOfFound);
        }
    }

    static int NumberOfFound;

    static void F(int nodeNo, int depth)
    {
        Debug.Assert(VisitedTable[nodeNo] == false);

        if (depth == N - 1)
            NumberOfFound++;

        VisitedTable[nodeNo] = true;
        var p = ConnectionTable[nodeNo];
        for (int i = 0; i < N; i++)
        {
            if (p[i] && !VisitedTable[i])
            {
                F(i, depth + 1);
            }
        }
        VisitedTable[nodeNo] = false;
    }
}

public static class Input
{
    private static Queue<string> q = new Queue<string>();
    private static void Confirm() { if (q.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) q.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(q.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(q.Dequeue()); }
    public static string NextString() { Confirm(); return q.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(q.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}