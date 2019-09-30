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
        int N = NextInt();
        List<int> list = new List<int>();
        for (int i = 0; i < N; i++) list.Add(NextInt());
        for (int i = 0; i < N; i++)
        {
            if (i + 1 < list[i]) { Console.WriteLine(-1); return; }
        }
        List<int> answer = new List<int>();
        bool[] done = Enumerable.Repeat(true, N).ToArray();
        for (int i = 0; i < N; i++)
        {
            int max_index = 0;
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (done[j]) count++;
                if (list[j] == count && done[j]) {
                    max_index = j;
                }
            }
            answer.Add(list[max_index]);
            done[max_index] = false;
        }
        answer.Reverse();
        answer.ForEach(Console.WriteLine);
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