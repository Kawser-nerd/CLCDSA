using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

class Program
{
    static int N;

    public static void Main(string[] args)
    {
        N = Input.NextInt();
        var x = new int[N];
        var y = new int[N];
        var h = new int[N];

        int samplex = 0, sampley = 0, sampleh = 0;
        foreach (var i in Enumerable.Range(0, N))
        {
            var xyh = Input.LineInt();
            x[i] = xyh[0];
            y[i] = xyh[1];
            h[i] = xyh[2];
            if (h[i] != 0)
            {
                samplex = x[i];
                sampley = y[i];
                sampleh = h[i];
            }
        }

        for (int cx = 0; cx <= 100; cx++)
        {
            for (int cy = 0; cy <= 100; cy++)
            {
                var hh = sampleh + Math.Abs(cx - samplex) + Math.Abs(cy - sampley);
                for (int i = 0; i < N; i++)
                {
                    var HC = Math.Max(hh - Math.Abs(cx - x[i]) - Math.Abs(cy - y[i]), 0);
                    if (HC != h[i])
                        goto L_nextcand;
                }
                Console.WriteLine($"{cx} {cy} {hh}");
                return;
            L_nextcand:
                ;
            }
        }

        throw new Exception();
    }
}

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