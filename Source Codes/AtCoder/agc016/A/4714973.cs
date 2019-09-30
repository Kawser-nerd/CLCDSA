using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private const long INFINITY = 9223372036854775807;
    public static void Main()
    {
        string s = NextString();
        int ans = INF;
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (!s.Contains(c)) continue;
            string t = s;
            int count = 0;
            while (t.Count(v => v == c) != t.Length)
            {
                string nxt = "";
                for (int i = 0; i < t.Length - 1; i++)
                {
                    if (t[i] == c) nxt += c.ToString();
                    else if (t[i + 1] == c) nxt += c.ToString();
                    else nxt += t[i].ToString();
                }
                t = nxt;
                count++;
                //Console.WriteLine(t);
            }
            ans = Math.Min(count, ans);
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