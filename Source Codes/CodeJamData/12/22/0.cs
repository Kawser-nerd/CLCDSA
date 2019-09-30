#region Template code
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Globalization;

static class MyLinq
{
    public static int MaxIdx<T>(this IEnumerable<T> seq) where T : IComparable
    {
        int res = -1;
        T max = default(T);
        int i = 0;
        foreach (T t in seq)
        {
            if (res == -1 || t.CompareTo(max) > 0) { res = i; max = t; }
            i += 1;
        }
        return res;
    }
    public static int MaxIdx<T, S>(this IEnumerable<T> seq, Func<T, S> func) where S : IComparable
    {
        return seq.Select(func).MaxIdx();
    }
    public static int MinIdx<T>(this IEnumerable<T> seq) where T : IComparable
    {
        int res = -1;
        T min = default(T);
        int i = 0;
        foreach (T t in seq)
        {
            if (res == -1 || t.CompareTo(min) < 0) { res = i; min = t; }
            i += 1;
        }
        return res;
    }
    public static int MinIdx<T, S>(this IEnumerable<T> seq, Func<T, S> func) where S : IComparable
    {
        return seq.Select(func).MinIdx();
    }

}

class Program
{
    static void Main(string[] args)
    {
        System.Threading.Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        Solution sol = new Solution();
        sol.go();
    }
}

partial class Solution
{
    #region I/O
    protected TextReader input = null;
    protected TextWriter output = null;

    string[] line;
    int index;
    protected string ReadLine()
    {
        line = null;
        return input.ReadLine();
    }

    protected int ReadLine_int()
    {
        line = null;
        return Convert.ToInt32(input.ReadLine());
    }

    protected string[] SplitLine()
    {
        index = 0;
        return line = input.ReadLine().Split();
    }

    protected List<int> SplitLine_int()
    {
        index = 0;
        line = input.ReadLine().Split();

        List<int> result = new List<int>();
        foreach (string s in line)
        {
            if (s == "") continue;
            result.Add(Convert.ToInt32(s));
        }
        return result;
    }

    protected string GetString()
    {
        return line[index++];
    }

    protected int GetInt()
    {
        return Convert.ToInt32(line[index++]);
    }

    protected long GetLong()
    {
        return Convert.ToInt64(line[index++]);
    }

    protected double GetDouble()
    {
        return Convert.ToDouble(line[index++], CultureInfo.InvariantCulture);
    }

    protected void Write(string s)
    {
        output.Write(s);
        Console.Out.Write(s);
    }

    protected void Write(string format, params object[] ss)
    {
        output.Write(format, ss);
        Console.Out.Write(format, ss);
    }

    protected void WriteLine()
    {
        output.WriteLine();
        Console.Out.WriteLine();
    }

    protected void WriteLine(string s)
    {
        output.WriteLine(s);
        Console.Out.WriteLine(s);
    }

    protected void WriteLine(string format, params object[] ss)
    {
        output.WriteLine(format, ss);
        Console.Out.WriteLine(format, ss);

    }

    #endregion

    static string hex(int x)
    {
        return String.Format("{0:x}", x);
    }

    public void go()
    {
        Environment.CurrentDirectory = "../..";
        input = File.OpenText(name + ".in");
        output = File.CreateText(name + ".out");
        int N = ReadLine_int();
        for (cas = 1; cas <= N; cas++)
        {
            Solve();
        }

        output.Close();
        input.Close();
        Console.Out.WriteLine("Done...");
        Console.In.ReadLine();
    }
    int cas = -1;
}
#endregion

class PrioElem
{
    public int time; 
    public int i, j;
}
class PrioQueue
{
    List<PrioElem> arr = new List<PrioElem>();
    public bool IsEmpty() { return arr.Count == 0; }
    public void Add(PrioElem elm)
    {
        int i = arr.Count;
        arr.Add(elm);
        while (i > 0 && arr[(i - 1) / 2].time > elm.time)
        {
            PrioElem t = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = arr[i];
            arr[i] = t;
            i = (i - 1) / 2;
        }
    }
    public PrioElem Pop()
    {
        PrioElem result = arr[0];
        arr[0] = arr[arr.Count - 1];
        arr.RemoveAt(arr.Count - 1);
        int i = 0;
        while (true)
        {
            int minidx = i;
            if (2 * i + 1 < arr.Count && arr[2 * i + 1].time < arr[minidx].time) minidx = 2 * i + 1;
            if (2 * i + 2 < arr.Count && arr[2 * i + 2].time < arr[minidx].time) minidx = 2 * i + 2;
            if (minidx == i) break;
            PrioElem t = arr[i];
            arr[i] = arr[minidx];
            arr[minidx] = t;
            i = minidx;
        }
        return result;
    }
}

partial class Solution
{
    const string name = "B-large";

    int[,] ceil;
    int[,] floor;
    int[,] visited;
    int N, M;
    void Solve()
    {
        var firstline = SplitLine_int();
        int H = firstline[0];
        N = firstline[1];
        M = firstline[2];

        ceil = new int[N, M];
        floor = new int[N, M];
        visited = new int[N, M];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                visited[i, j] = -1;

        for (int i = 0; i < N; i++)
        {
            var line = SplitLine_int();
            for (int j = 0; j < M; j++) ceil[i, j] = line[j];
        }
        for (int i = 0; i < N; i++)
        {
            var line = SplitLine_int();
            for (int j = 0; j < M; j++) floor[i, j] = line[j];
        }

        PrioQueue q = new PrioQueue();
        q.Add(new PrioElem { time = 0, i = 0, j = 0 });
        visited[0, 0] = 0;
        while (true)
        {
            var cur = q.Pop();
            int i = cur.i;
            int j = cur.j;
            if (i==N-1 && j==M-1)
            {
                // DONE!
                WriteLine("Case #{0}: {1}", cas, cur.time*.1);
                return;
            }
            foreach (var adj in mkAdj(cur.i, cur.j))
            {
                int i2 = adj.i;
                int j2 = adj.j;
                if (floor[i2, j2] > ceil[i2, j2] - 50) continue;
                if (floor[i2, j2] > ceil[i, j] - 50) continue;
                if (floor[i, j] > ceil[i2, j2] - 50) continue;
                int reqwater = ceil[i2, j2] - 50;
                int reqtime = 0;
                if (reqwater < H) reqtime = H - reqwater;
                if (reqtime > cur.time)
                {
                    q.Add(new PrioElem { time = reqtime, i = i, j = j });
                    continue;
                }
                int newtime = cur.time;
                if (newtime > 0)
                {
                    if (H - cur.time < floor[i, j] + 20) newtime += 100; // 10 seconds (dragging)
                    else newtime += 10; // 1 second (floating)
                }
                if (visited[i2, j2] == -1 || visited[i2, j2] > newtime)
                {
                    visited[i2, j2] = newtime;
                    q.Add(new PrioElem { time = newtime, i = i2, j = j2 });
                }
            }


        }
        //WriteLine("Case #{0}: {1}", cas, result);
    }

    private IEnumerable<PrioElem> mkAdj(int i, int j)
    {
        if (i > 0) yield return new PrioElem { i = i - 1, j = j };
        if (i < N - 1) yield return new PrioElem { i = i + 1, j = j };
        if (j > 0) yield return new PrioElem { i = i, j = j - 1 };
        if (j < M-1) yield return new PrioElem { i = i, j = j + 1 };
    }


}

