using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private static int[] dx = new int[4] { 0, -1, 0, 1 };
    private static int[] dy = new int[4] { -1, 0, 1, 0 };
    public static void Main()
    {
        int R = NextInt();
        int C = NextInt();
        int K = NextInt();
        List<char>[] map = new List<char>[R];
        for (int i = 0; i < R; i++)
        {
            string s = NextString();
            map[i] = new List<char>();
            for (int j = 0; j < C; j++) map[i].Add(s[j]);
        }

        List<int>[] ue = new List<int>[R];
        for (int i = 0; i < R; i++) ue[i] = Enumerable.Repeat(0, C).ToList();
        for (int i = 0; i < C; i++)
        {
            int x = 0;
            for (int j = 0; j < R; j++)
            {
                if (map[j][i] == 'o') x++;
                else x = 0;
                ue[j][i] = x;
            }
        }

        List<int>[] sita = new List<int>[R];
        for (int i = 0; i < R; i++) sita[i] = Enumerable.Repeat(0, C).ToList();
        for (int i = 0; i < C; i++)
        {
            int x = 0;
            for (int j = R - 1; j != -1; j--)
            {
                if (map[j][i] == 'o') x++;
                else x = 0;
                sita[j][i] = x;
            }
        }

        long ans = 0;
        int k2 = 2 * K - 1;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j <= C - k2; j++)
            {
                bool flag = true;
                int ind = j;
                for (int k = 1; k <= K; k++)
                {
                    if (ue[i][ind] < k || sita[i][ind] < k) flag = false;
                    ind++;
                }
                for (int k = K - 1; k != 0; k--)
                {
                    if (ue[i][ind] < k || sita[i][ind] < k) flag = false;
                    ind++;
                }
                if (flag) ans++;
            }
        }
        Console.WriteLine(ans);
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