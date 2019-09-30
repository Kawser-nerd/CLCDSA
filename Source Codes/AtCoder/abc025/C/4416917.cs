using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private static int[,] board = new int[3, 3];
    private static int[,] b = new int[2, 3];
    private static int[,] c = new int[3, 2];
    public static void Main()
    {

        b[0, 0] = NextInt(); b[0, 1] = NextInt(); b[0, 2] = NextInt();
        b[1, 0] = NextInt(); b[1, 1] = NextInt(); b[1, 2] = NextInt();
        c[0, 0] = NextInt(); c[0, 1] = NextInt();
        c[1, 0] = NextInt(); c[1, 1] = NextInt();
        c[2, 0] = NextInt(); c[2, 1] = NextInt();

        //??????...?
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) board[i, j] = 0;
        int bc = 0;
        foreach (var bi in b) bc += bi;
        foreach (var ci in c) bc += ci;

        int chokudai = Recursion(0);
        Console.WriteLine(chokudai);
        Console.WriteLine(bc - chokudai);
    }

    private static int Calc()
    {
        int box = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                if (board[i, j] == board[i + 1, j]) box += b[i, j];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 2; j++)
                if (board[i, j] == board[i, j + 1]) box += c[i, j];

        return box;
    }

    private static int Recursion(int t)
    {
        if (t == 9) return Calc();
        if (t % 2 == 0)
        {
            int max = -INF;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                {
                    if (board[i, j] != 0) continue;
                    board[i, j] = 1;
                    max = Math.Max(max, Recursion(t + 1));
                    board[i, j] = 0;
                }
            return max;
        }
        else
        {
            int min = INF;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                {
                    if (board[i, j] != 0) continue;
                    board[i, j] = 2;
                    min = Math.Min(min, Recursion(t + 1));
                    board[i, j] = 0;
                }
            return min;
        }
    }
}

public class Input
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