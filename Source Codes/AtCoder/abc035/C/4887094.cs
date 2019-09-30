using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static int N;
    static int Q;
    static int[] l;
    static int[] r;

    public static void Main(string[] args)
    {
        checked
        {
            N = Input.NextInt();
            Q = Input.NextInt();

            var table = new bool[N+1];
            for (int i = 0; i < Q; i++)
            {
                var s = Input.LineInt();
                var l = s[0] - 1;
                var r = s[1] - 1 + 1;

                table[l] = !table[l];
                table[r] = !table[r];
            }

            var sb = new StringBuilder();
            int koma = 0;
            for (int i = 0; i < N; i++)
            {
                if (table[i])
                    koma = koma == 0 ? 1 : 0;
                sb.Append(koma);
            }
            Console.WriteLine(sb.ToString());
        }
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