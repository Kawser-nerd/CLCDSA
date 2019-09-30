using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int N = NextInt();
        int M = NextInt();
        int m = M / 3;
        for (int i = 0; i <= m; i++)
        {
            if (i > N) break;
            int m0 = M - i * 3;
            if (m0 % 2 == 1) continue;
            int n0 = N - i;
            int n2 = m0 / 2;
            int n3 = i;
            int n4 = (n2 - n0);
            int n20 = (n2 - (n2 - n0) * 2);
            if (n20 < 0 || n4 < 0) continue;
            Console.WriteLine(n20 + " " + n3 + " " + n4);
            return;
        }
        Console.WriteLine("-1 -1 -1");
    }
}

public class Input
{
    private static Queue<string> queue = new Queue<string>();
    private static void Confirm() { if (queue.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) queue.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(queue.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(queue.Dequeue()); }
    public static string NextString() { Confirm(); return queue.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(queue.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}