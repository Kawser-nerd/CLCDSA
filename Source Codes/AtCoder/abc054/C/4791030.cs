using System;
using System.Collections.Generic;
using System.Linq;

public static partial class Program
{
    public static long n;
    public static bool[,] graph = new bool[8, 8];
    public static void Main()
    {
        var nm = CRL().ArrayLongs();
        n = nm[0];
        for (int i = 0; i < nm[1]; i++)
        {
            var ab = CRL().ArrayLongs().Select(x => x - 1).ToArray();
            graph[ab[0], ab[1]] = true;
            graph[ab[1], ab[0]] = true;
        }

        var passed = new bool[n, n];
        var visited = new bool[n];
        visited[0] = true;
        CWL(DFS(0, passed, visited));
    }

    public static int DFS(int vert, bool[,] passed, bool[] visited)
    {
        if (visited.All(x => x))
        {
            return 1;
        }

        var ret = 0;
        for (int next = 0; next < n; next++)
        {
            //???????
            if (graph[vert, next] == false)
            {
                continue;
            }

            //??????????
            if (passed[vert, next])
            {
                continue;
            }

            //????????
            if (visited[next])
            {
                continue;
            }

            visited[next] = true;      //??
            passed[vert, next] = true; //?(????)
            passed[next, vert] = true; //?(????)
            ret += DFS(next, passed, visited);
            visited[next] = false;
            passed[vert, next] = false;
            passed[next, vert] = false;
        }

        return ret;
    }
}

public static partial class Program
{
    //????????
    private static long ToInt(this string str) => long.Parse(str);
    private static long[] ToInt(this IEnumerable<string> strs) => strs.Select(x => x.ToInt()).ToArray();
    public static long[] ArrayLongs(this string str, char opr = ' ') => str.Split(opr).ToInt();
    public static string CRL() => Console.ReadLine();
    public static void CWL(object obj) => Console.WriteLine(obj);
    public static long Diff(long a, long b) => Math.Abs(Math.Max(a, b) - Math.Min(a, b));
    public static long Sign(this long i) => Math.Sign(i);
    public static bool IsEven(this long i) => i % 2 == 0;
    public static bool IsEven(this int i) => i % 2 == 0;
    public static long[] dx = new long[] { 0, -1, 0, 1 };
    public static long[] dy = new long[] { -1, 0, 1, 0 };
    public static long mod = 1000000007;
    public static string alphabet = "abcdefghijklmnopqrstuvwxyz";
    public static long ToLong(this char c) => c.ToString().ToInt();
    //????????
}