using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        var N = ReadInt();
        var H = ReadInts();

        var cnt = Count(H);

        Console.WriteLine(cnt);
    }

    static int Count(int[] h)
    {
        var cnt = 0;
        while (h != null && h.Length != 0 && h.Any(_ => _ != 0))
        {
            if (h.Contains(0))
            {
                var idx = Array.IndexOf(h, 0);
                if (idx != 0) cnt += Count(h.Take(idx).ToArray());
                if (idx != h.Length - 1) cnt += Count(h.Skip(idx + 1).ToArray());
                break;
            }

            var min = h.Min();
            cnt += min;
            for (var i = 0; i < h.Length; i++)
            {
                h[i] -= min;
            }
        }
        return cnt;

    }

    public static string Read() { return Console.ReadLine(); }
    public static int ReadInt() { return int.Parse(Read()); }
    public static long ReadLong() { return long.Parse(Read()); }
    public static double ReadDouble() { return double.Parse(Read()); }

    public static string[] Reads() { return Console.ReadLine().Split(' '); }
    public static int[] ReadInts() { return Reads().Select(_ => int.Parse(_)).ToArray(); }
    public static long[] ReadLongs() { return Reads().Select(_ => long.Parse(_)).ToArray(); }
    public static double[] ReadDoubles() { return Reads().Select(_ => double.Parse(_)).ToArray(); }
}