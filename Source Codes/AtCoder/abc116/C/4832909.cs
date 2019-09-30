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
    static int N;
    static int[] h;

    public static void Main(string[] args)
    {
        N = Input.NextInt();
        h = Input.LineInt();

        int c = 0;
        for (int max = h.Max(); max > 0; max--)
        {
            int mode = 0; // non-max
            for (int j = 0; j < h.Length; j++)
            {
                if (h[j] == max)
                {
                    if (mode == 0)
                    {
                        mode = 1;
                        c++;
                    }
                    h[j] = max - 1;
                }
                else
                {
                    if (mode != 0)
                    {
                        mode = 0;
                    }
                }
            }
        }
        
        Console.WriteLine(c);
    }
}