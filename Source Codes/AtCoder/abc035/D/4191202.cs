using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

class Node
{
    public int Next { get; }
    public int Cost { get; }
    public Node(int next, int cost)
    {
        Next = next;
        Cost = cost;
    }
}

class Program
{
    static int[] MoveCost(List<Node>[] nodes, int n)
    {
        int[] costs = new int[n].Select(x => int.MaxValue).ToArray();
        costs[0] = 0;
        var que = new Queue<int>();
        que.Enqueue(0);
        while(que.Any())
        {
            int p = que.Dequeue();
            foreach(var next in nodes[p])
            {
                if(costs[next.Next] > next.Cost + costs[p])
                {
                    costs[next.Next] = costs[p] + next.Cost;
                    que.Enqueue(next.Next);
                }
            }
        }
        return costs;
    }
    public void Slove()
    {    
        var inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int m = int.Parse(inputs[1]);
        int t = int.Parse(inputs[2]);
        int[] points =
            Console.ReadLine().Split()
            .Select(int.Parse)
            .ToArray();
        var goNodes = Enumerable.Range(0, n).Select(x => new List<Node>()).ToArray();
        var backNodes = Enumerable.Range(0, n).Select(x => new List<Node>()).ToArray();
        foreach(int i in Enumerable.Range(0, m))
        {
            inputs = Console.ReadLine().Split();
            int a = int.Parse(inputs[0]) - 1;
            int b = int.Parse(inputs[1]) - 1;
            int cost = int.Parse(inputs[2]);
            goNodes[a].Add(new Node(b, cost));
            backNodes[b].Add(new Node(a, cost));
        }
        int[] goTime = MoveCost(goNodes, n);
        int[] backTime = MoveCost(backNodes, n);
        var getPoints =
            Enumerable.Range(0, n)
            .Where(x => goTime[x] < t && backTime[x] < t)
            .Select(x => (t - goTime[x] - backTime[x]) * (long)points[x])
            ;
        long max = getPoints.Max();
        Console.WriteLine(max);
    }

    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}