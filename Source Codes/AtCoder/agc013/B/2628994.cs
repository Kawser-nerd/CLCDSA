using System;
using System.Collections.Generic;
//using System.Linq;
class Program
{
    static void Main()
    {
        string[] s = Console.ReadLine().Split(' ');
        int n, m;
        n = int.Parse(s[0]);
        m = int.Parse(s[1]);
        Graph g = new Graph(n);
        List<int> path = new List<int>();
        for (int i = 0; i < m; i++)
        {
            s = Console.ReadLine().Split(' ');
            int a, b;
            a = int.Parse(s[0]);
            b = int.Parse(s[1]);
            g.SetEdge(a, b);
        }
        path.Add(1);
        g.node[0].IsVisited = true;
        int add;
        do
        {
            add = Check(g, path);
            if (add != 0)
            {
                path.Add(add);
                g.node[add - 1].IsVisited = true;
            }
        } while (add != 0);
        path.Reverse();
        do
        {
            add = Check(g, path);
            if (add != 0)
            {
                path.Add(add);
                g.node[add - 1].IsVisited = true;
            }
        } while (add != 0);
        C.WriteLine(path.Count);
        for (int i = 0; i < path.Count - 1; i++)
            C.Write(path[i] + " ");
        C.WriteLine(path[path.Count - 1]);
    }
    static int Check(Graph g, List<int> path)
    {
        int r = 0;
        int l = path[path.Count - 1];
        foreach (var i in g.node[l - 1].children)
        {
            if (g.node[i - 1].IsVisited)
                continue;
            r = i;
            break;
        }
        return r;
    }
}
//????????
class Node
{
    public int id;
    public bool IsVisited { get; set; }
    public List<int> children = new List<int>();
    public Node(int id) { this.id = id; }
}
class Graph
{
    public Node[] node;
    public int n { get; }
    public Graph(int n)
    {
        this.n = n;
        node = new Node[n];
        for (int i = 0; i < n; i++)
            node[i] = new Node(i + 1);
    }
    public void SetEdge(int n1, int n2)
    {
        node[n1 - 1].children.Add(n2);
        node[n2 - 1].children.Add(n1);
    }
}
//???????????
static class C
{
    [System.Runtime.InteropServices.DllImport("msvcrt.dll")]
    private static extern void printf(string s);
    public static void Write(string s) { printf(s); }
    public static void Write(char c) { printf(c.ToString()); }
    public static void Write(long n) { printf(n.ToString()); }
    public static void Write(int n) { printf(n.ToString()); }
    public static void Write(double d) { printf(d.ToString()); }
    public static void WriteLine() { printf("\n"); }
    public static void WriteLine(string s) { printf(s + "\n"); }
    public static void WriteLine(char c) { WriteLine(c.ToString()); }
    public static void WriteLine(long n) { WriteLine(n.ToString()); }
    public static void WriteLine(int n) { WriteLine(n.ToString()); }
    public static void WriteLine(double d) { WriteLine(d.ToString()); }
    public static void WriteLines(string[] s) { foreach (var i in s) WriteLine(i); }
    public static void WriteLines(char[] c) { foreach (var i in c) WriteLine(i); }
    public static void WriteLines(long[] c) { foreach (var i in c) WriteLine(i); }
    public static void WriteLines(int[] c) { foreach (var i in c) WriteLine(i); }
    public static void WriteLines(double[] d) { foreach (var i in d) WriteLine(i); }
}