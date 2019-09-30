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
        string S = NextString();
        bool[] done = Enumerable.Repeat(true, 26).ToArray();
        foreach (char c in S) { done[(int)c - 97] = false; }
        if (S.Length < 26)
        {
            for (int i = 0; i < 26; i++)
            {
                if (done[i])
                {
                    Console.WriteLine(S + ((char)(i + 97)).ToString());
                    return;
                }
            }
        }
        else if (S == "zyxwvutsrqponmlkjihgfedcba") Console.WriteLine(-1);
        else
        {
            string ans = "";
            done = Enumerable.Repeat(true, 26).ToArray();
            for (int i = 0; i < 26; i++)
            {
                done[S[i] - 97] = false;
                //i????????
                for (int j = 0; j < 26; j++)
                {
                    string _ans = S.Substring(0, i);
                    if (done[j])
                    {
                        _ans += ((char)(j + 97)).ToString();
                        if (S.CompareTo(_ans) == -1)
                        {
                            if (ans == "" || _ans.CompareTo(ans) == -1) ans = _ans;
                        }
                    }
                }
            }
            Console.WriteLine(ans);
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