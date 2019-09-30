using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        double Deg = NextDouble() + 112.5;
        int Dis = NextInt();
        string[] D = new string[16] {
            "N","NNE","NE","ENE",
            "E", "ESE", "SE","SSE",
            "S","SSW", "SW", "WSW",
            "W", "WNW", "NW", "NNW" };
        string ans = D[(int)Math.Floor(Deg / 225) % 16];
        if (Dis <= 14) ans = "C 0";
        else if (Dis <= 92) ans += " 1";
        else if (Dis <= 200) ans += " 2";
        else if (Dis <= 326) ans += " 3";
        else if (Dis <= 476) ans += " 4";
        else if (Dis <= 644) ans += " 5";
        else if (Dis <= 830) ans += " 6";
        else if (Dis <= 1028) ans += " 7";
        else if (Dis <= 1244) ans += " 8";
        else if (Dis <= 1466) ans += " 9";
        else if (Dis <= 1706) ans += " 10";
        else if (Dis <= 1958) ans += " 11";
        else ans += " 12";
        Console.WriteLine(ans);
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