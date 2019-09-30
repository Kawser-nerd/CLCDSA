using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        string S = NextString();
        S = new string(S.Reverse().ToArray());
        string ans = "";
        string T = NextString();
        T = new string(T.Reverse().ToArray());
        int M = S.Length - T.Length;
        bool a = false;
        for (int i = 0; i < S.Length; i++)
        {
            char c = S[i];
            if ((c == '?' || c == T[0]) && !a)
            {
                bool flag = true;
                for (int j = 0; j < T.Length; j++)
                {
                    if (i+j == S.Length) { flag = false; break;  }
                    if ((S[i + j] != T[j]) && (S[i+j] != '?')) flag = false;
                }
                if (flag)
                {
                    a = true;
                    ans += T;
                    i += T.Length - 1;
                }
                else ans += c;
            }
            else ans += c;
        }
        ans = new string(ans.Reverse().ToArray());
        if (!a) { Console.WriteLine("UNRESTORABLE"); }
        else { Console.WriteLine(ans.Replace('?', 'a')); }
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