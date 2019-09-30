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
        int s = ab[0] - 1, g = ab[1] - 1;
        int M = IntRead();
        Node[] node = new Node[N];
        for (int i = 0; i < N; i++) node[i] = new Node(INF);
        for (int i = 0; i < M; i++)
        {
            ab = IntLine();
            node[ab[0] - 1].to.Add(ab[1] - 1);
            node[ab[0] - 1].name = ab[0] - 1;
            node[ab[1] - 1].to.Add(ab[0] - 1);
            node[ab[1] - 1].name = ab[1] - 1;
        }

        Queue<Node> queue = new Queue<Node>();
        node[s].cost = 0;
        node[s].count = 1;
        queue.Enqueue(node[s]);

        while (queue.Count() != 0)
        {
            Node n = queue.Dequeue();
            if (n.visit) continue;
            n.visit = true;
            n.count %= INF;
            foreach (int i in n.to)
            {
                node[i].count %= INF;
                if (n.cost + 1 < node[i].cost)
                {
                    node[i].visit = false;
                    node[i].count = n.count;
                    node[i].cost = n.cost + 1;
                    queue.Enqueue(node[i]);
                }
                else if (n.cost + 1 == node[i].cost)
                {
                    node[i].count += n.count;
                    queue.Enqueue(node[i]);
                }
            }
            //Console.WriteLine("Locking -> " + (n.name + 1));
            //for (int i = 0; i < N; i++)
            //{
            //    Console.WriteLine((i + 1) + " : " + node[i].count);
            //}
        }
        Console.WriteLine(node[g].count);
    }
}

public class Node
{
    public List<int> to = new List<int>();
    public int name;
    public long cost;
    public long count = 0;
    public bool visit = false;
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
    public static long LCM(long a, long b)
    {
        long c = a * b;
        if (a < b) Swap(ref a, ref b);
        long d = a % b;
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
    public static int[] SpIntRead(char c)
    {
        return Console.ReadLine().Split(c).Select(int.Parse).ToArray();
    }
    public static string ToConvertBit(int N, int e)
    {
        string ret = "";
        int r = 0;
        while (N != 0)
        {
            r = N % e;
            ret += r.ToString();
            N -= r;
            N /= e;
        }
        ret = StrReverce(ret);
        return ret;
    }
    public static int IntRead()
    {
        return int.Parse(Console.ReadLine());
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