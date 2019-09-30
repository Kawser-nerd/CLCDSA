using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;

class Program
{
    static int R, C;
    static int sx, sy;
    static int gx, gy;
    static char[][] map;

    public static void Main(string[] args)
    {
        R = Input.NextInt();
        C = Input.NextInt();
        sy = Input.NextInt() - 1;
        sx = Input.NextInt() - 1;
        gy = Input.NextInt() - 1;
        gx = Input.NextInt() - 1;

        map = new char[R][];
        for (int i = 0; i < R; i++)
        {
            var s = Input.LineString().ToArray()[0];
            map[i] = s.ToCharArray();
        }

        var distances = new int[R][];
        for (int i = 0; i < R; i++)
        {
            distances[i] = new int[C];
        }

        int px = sx;
        int py = sy;
        distances[py][px] = int.MaxValue;
        var pointers = new List<Tuple<int, int>>();
        pointers.Add(new Tuple<int, int>(px, py));
        int currDepth = 0;
        for (; ; )
        {
            currDepth++;
            if (pointers.Count == 0)
            {
                Console.WriteLine("Error");
                return;
            }

            var newPointers = new List<Tuple<int, int>>();
            foreach (var pointer in pointers)
            {
                px = pointer.Item1;
                py = pointer.Item2;
                if (px == gx && py == gy)
                {
                    goto L_Found;
                }
                if (map[py - 1][px] == '.')
                    if (distances[py - 1][px] == 0)
                    {
                        distances[py - 1][px] = currDepth;
                        newPointers.Add(new Tuple<int, int>(px, py - 1));
                    }

                if (map[py + 1][px] == '.')
                    if (distances[py + 1][px] == 0)
                    {
                        distances[py + 1][px] = currDepth;
                        newPointers.Add(new Tuple<int, int>(px, py + 1));
                    }
                if (map[py][px - 1] == '.')
                    if (distances[py][px - 1] == 0)
                    {
                        distances[py][px - 1] = currDepth;
                        newPointers.Add(new Tuple<int, int>(px - 1, py));
                    }
                if (map[py][px + 1] == '.')
                    if (distances[py][px + 1] == 0)
                    {
                        distances[py][px + 1] = currDepth;
                        newPointers.Add(new Tuple<int, int>(px + 1, py));
                    }
            }
            pointers = newPointers;
        }
    L_Found:
        Console.WriteLine(currDepth - 1);
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