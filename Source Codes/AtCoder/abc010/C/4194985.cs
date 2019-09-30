using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int txa = NextInt();
        int tya = NextInt();
        int txb = NextInt();
        int tyb = NextInt();
        int max = NextInt() * NextInt();
        int n = NextInt();
        for (int i = 0; i < n; i++)
        {
            int x = NextInt();
            int y = NextInt();
            double root = Math.Sqrt(Math.Pow(x - txa, 2) + Math.Pow(y - tya, 2))
                + Math.Sqrt(Math.Pow(x - txb, 2) + Math.Pow(y - tyb, 2));
            if (root <= max + 0.0) { Console.WriteLine("YES"); return; }
        }
        Console.WriteLine("NO");
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