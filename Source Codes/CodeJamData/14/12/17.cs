//#define ONLINE_JUDGE
#define DEBUG

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class Program
{

    static int tests = 3;

#if (ONLINE_JUDGE)
    static TextReader r = Console.In;
    static TextWriter w = Console.Out;
#else
    static string path = @"C:\Y\Prog\GoogleCodeJam\02\";
    static string answerFile = "0{0}Answer.txt";
    static string resultFile = "0{0}Result.txt";
    static string sourceFile = "0{0}Source.txt";
    
    static TextReader r;
    static TextWriter w;
#endif

    static void Main(string[] args)
    {
        for (int i = 1; i <= tests; i++)
        {
#if (!ONLINE_JUDGE)
            r = new StreamReader(string.Format(path + sourceFile, i));
            w = new StreamWriter(string.Format(path + resultFile, i), false);
#endif
            int cases = Convert.ToInt32(r.ReadLine());
            for (int j = 0; j < cases; j++)
                solve(j+1);
#if (!ONLINE_JUDGE)
            w.Flush(); w.Close();
            Console.WriteLine("CASE: {0}", i);
            string answer = File.ReadAllText(string.Format(path + answerFile, i));
            string result = File.ReadAllText(string.Format(path + resultFile, i));
            if (answer != result)
            {
                Console.WriteLine("FAIL:");
                Console.WriteLine("Result" + Environment.NewLine + result);
                Console.WriteLine("Answer" + Environment.NewLine + answer);
            }
            else
                Console.WriteLine("OK");
#endif
        }
    }

    public static void solve(int sc)
    {
        int n = Convert.ToInt32(r.ReadLine());
        BTree t = new BTree(n);
        for (int i = 0; i < n; i++)
            t.links[i] = new List<int>();
        for (int i = 0; i < n - 1; i++)
        {
            string[] b = r.ReadLine().Split(' ');
            int n1 = Convert.ToInt32(b[0]) - 1;
            int n2 = Convert.ToInt32(b[1]) - 1;
            t.links[n1].Add(n2);
            t.links[n2].Add(n1);
        }
        
        //for (int i = 0; i < n; i++)
        //{
        //    foreach (int n2 in t.links[i])
        //        t.whenRoot[i, n2] = 1 + t.getDeleted(i, n2); 
        //}
        int best = 1;
        for (int i = 0; i < n; i++)
        {
            foreach (int n1 in t.links[i])        
                foreach (int n2 in t.links[i])
                {
                    if (n1 == n2) continue;
                    best = Math.Max(best, 1 +
                        t.maxChildWhenParent(i, n1) + t.maxChildWhenParent(i, n2));
                }
        }

        w.WriteLine("Case #{0}: {1}", sc, n - best); 
    }

}

public class BTree
{
    public List<int>[] links;
    public int[,] whenRoot;
    public int[,] maxChildsWhenParent; //parent - first
        
    public BTree(int n)
    {
        links = new List<int>[n];
        whenRoot = new int[n, n];
        maxChildsWhenParent = new int[n, n];
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                maxChildsWhenParent[i, j] = -1;        
    }
    public int getDeleted(int root, int node)
    {
        int sum = 0;
        foreach (int n2 in links[node])
        { 
            whenRoot[root, node] = 1 + getDeleted(root, n2);
            sum += whenRoot[root, node];
        }
        return sum;
    }
    public int maxChildWhenParent(int parent, int node)
    {
        if (maxChildsWhenParent[parent, node] >= 0) return maxChildsWhenParent[parent, node];
        if (links[node].Count == 1 || links[node].Count == 2)
        {
            maxChildsWhenParent[parent, node] = 1;
            return maxChildsWhenParent[parent, node];
        }

        maxChildsWhenParent[parent, node] = 1;
        foreach (int n1 in links[node])        
            foreach (int n2 in links[node])
            {
                if (n1 == parent || n2 == parent || n1 == n2) continue;
                maxChildsWhenParent[parent, node] = Math.Max(maxChildsWhenParent[parent, node], 1 +
                    maxChildWhenParent(node, n1) + maxChildWhenParent(node, n2));
            }
        return maxChildsWhenParent[parent, node];
    }
}