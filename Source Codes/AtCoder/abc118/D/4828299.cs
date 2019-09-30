using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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

class Program
{
    static int[] NumberOfNeededMatches = new int[]
    {
            6, 2, 5, 5, 4, 5, 6, 3, 7, 6,
    };

    static int N, M;
    static int[] A;

    public static void Main(string[] args)
    {
        N = Input.NextInt();
        M = Input.NextInt();
        A = Input.LineInt();
        Array.Sort(A);
        Array.Reverse(A);

        int[] dp = new int[N + 1];
        int[][] dp_answers = new int[N + 1][];
        dp[0] = 0;
        for (int numberOfMatches = 1; numberOfMatches <= N; numberOfMatches++)
        {
            int max = int.MinValue;
            int prev_answer_dp_index = int.MinValue;
            int this_answer = int.MinValue;
            for (int j = 0; j < A.Length; j++)
            {
                var res = numberOfMatches - NumberOfNeededMatches[A[j]];
                if (res < 0)
                    continue;
                var dp_n = dp[res] + 1;
                if (dp_n > max)
                {
                    max = dp_n;
                    prev_answer_dp_index = res;
                    this_answer = A[j];
                }
            }
            dp[numberOfMatches] = max;
            if (max >= 0)
            {
                var ans = new List<int>();
                ans.Add(this_answer);

                var n = numberOfMatches - NumberOfNeededMatches[this_answer];
                while (n > 0)
                {
                    ans.Add(dp_answers[n][0]);
                    n = n - NumberOfNeededMatches[dp_answers[n][0]];
                }
                dp_answers[numberOfMatches] = ans.ToArray();
            }
        }

        foreach (var c in dp_answers[N])
            Console.Write(c);
        Console.WriteLine();
    }
}