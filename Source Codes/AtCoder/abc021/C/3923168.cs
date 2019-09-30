using System;
using System.Collections.Generic;
using System.Linq;
using static Atcoder;
using System.Threading.Tasks;
using System.ComponentModel;

public class Hello
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int N = IntRead();
        int[] ab = IntLine();
        int start = ab[0] - 1, goal = ab[1] - 1;
        List<Node> node = new List<Node>();
        int M = IntRead();
        for (int i = 0; i < N; i++) { Node n = new Node(INF); node.Add(n); }
        for (int i = 0; i < M; i++)
        {
            int[] box = IntLine().Select(v => v - 1).ToArray();
            node[box[0]].relate.Add(box[1]);
            node[box[1]].relate.Add(box[0]);
        }

        Queue<Node> queue = new Queue<Node>();

        node[start].cost = 0;
        node[start].routes = 1;
        queue.Enqueue(node[start]);
        int nc = 0;

        while (queue.Count != 0)
        {
            Node now_queue = queue.Dequeue();
            now_queue.routes %= INF;
            if (!now_queue.fin)
            {
                foreach (int sff in now_queue.relate)
                {
                    if (!node[sff].fin)
                    {
                        nc = now_queue.cost + 1;
                        if (nc == node[sff].cost) { node[sff].routes = (node[sff].routes + now_queue.routes) % INF; }
                        else if (nc < node[sff].cost) { node[sff].cost = nc; node[sff].routes = now_queue.routes; }
                        //else { node[sff].cost = nc; node[sff].routes = now_queue.routes; }
                        queue.Enqueue(node[sff]);
                    }
                }
                now_queue.fin = true;
            }
        }
        Console.WriteLine(node[goal].routes);
    }


}

public class Node
{
    public HashSet<int> relate = new HashSet<int>();

    public bool fin = false;

    public int cost;

    public long routes = 0;

    public Node(int inf) { cost = inf; }
}

public class Atcoder
{
    public static void Swap<T>(ref T a, ref T b)
    {
        var t = a;
        a = b;
        b = t;
    }
    public static int LCM(int a, int b)
    {
        int c = a * b;
        if (a < b) Swap(ref a, ref b);
        int d = a % b;
        while (d != 0)
        {
            a = b;
            b = d;
            d = a % b;
        }
        return c / b;
    }
    public static string StrReverce(string s)
    {
        return new string(s.Reverse().ToArray());
    }
    public static int IntRead()
    {
        return int.Parse(Console.ReadLine());
    }
    public static bool IsPrime(int n)
    {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        //double sqrtNum = Math.Sqrt(n);
        for (int i = 3; i < n; i += 2)
        {
            if (n % i == 0) return false;
        }
        return true;
    }
    public static string[] SpRead(char c)
    {
        return Console.ReadLine().Split(c);
    }
    public static long[] LSRead()
    {
        return Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
    }
    public static long Combination(int n, int r)
    {
        if (n == r) return 1;
        return
            Enumerable.Range((n - r + 1), r).ToList().Aggregate((now, next) => now * next) /
            Enumerable.Range(1, r).ToList().Aggregate((now, next) => now * next);
    }
    public static long Permutation(int n, int r)
    {
        if (n == r) return 1;
        return
            Enumerable.Range((n - r), r).ToList().Aggregate((now, next) => now * next);
    }
    public static long LongRead()
    {
        return long.Parse(Console.ReadLine());
    }
    public static long[] LongLine()
    {
        return Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
    }
    public static int[] IntLine()
    {
        return Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    }
}