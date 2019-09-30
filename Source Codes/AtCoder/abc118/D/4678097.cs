using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private const long INFINITY = 9223372036854775807;
    private static int[] make_cost = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    public static void Main()
    {
        int N = NextInt();
        int M = NextInt();
        int[] A = LineInt();
        string[] dp = new string[N + 1];
        dp[0] = "";
        for (int i = 1; i <= N; i++)
        {
            dp[i] = "0";
            foreach (int a in A)
            {
                if (make_cost[a] > i || dp[i - make_cost[a]] == "0") continue;
                int index = Search(dp[i - make_cost[a]], char.Parse(a.ToString()));
                string s = dp[i - make_cost[a]].Substring(0, index) + a + dp[i - make_cost[a]].Substring(index);
                if (Compare(s, dp[i])) { dp[i] = s; }
            }
        }
        Console.WriteLine(dp[N]);
    }
    private static int Search(string s, char c)
    {
        int i = 0;
        for (; i < s.Length; i++) { if (c >= s[i]) return i; }
        return i;
    }
    private static bool Compare(string a, string b)
    {
        if (a.Length > b.Length) { return true; }
        else if (a.Length < b.Length) { return false; }
        for (int i = 0; i < a.Length; i++)
        {
            if (a[i] > b[i]) return true;
            else if (a[i] < b[i]) return false;
        }
        return false;
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