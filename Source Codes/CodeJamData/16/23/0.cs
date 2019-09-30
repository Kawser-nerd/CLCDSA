using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class C
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);

            int n = int.Parse(Console.ReadLine());
            string[][] ws = new string[n][];
            for (int i = 0; i < n; i++)
                ws[i] = Console.ReadLine().Split();

            Dictionary<string, int> count1 = new Dictionary<string, int>();
            Dictionary<string, int> count2 = new Dictionary<string, int>();
            for(int i = 0; i < n; i++)
            {
                if (count1.ContainsKey(ws[i][0]))
                    count1[ws[i][0]]++;
                else
                    count1[ws[i][0]] = 1;
                if (count2.ContainsKey(ws[i][1]))
                    count2[ws[i][1]]++;
                else
                    count2[ws[i][1]] = 1;
            }

            string[] firsts = count1.Keys.ToArray();
            string[] seconds = count2.Keys.ToArray();

            MaxFlow mf = new MaxFlow(n * 2);
            for (int i = 0; i < firsts.Length; i++)
                mf.Add(mf.Source, i, count1[firsts[i]] - 1);

            for (int i = 0; i < seconds.Length; i++)
                mf.Add(n + i, mf.Sink, count2[seconds[i]] - 1);

            for (int i = 0; i < n; i++)
            {
                mf.Add(Array.IndexOf(firsts, ws[i][0]), n + Array.IndexOf(seconds, ws[i][1]), 1);
            }

            Console.WriteLine("Case #" + CASE + ": " + mf.NetworkFlow());
        }
    }


    public class MaxFlow
    {
        public int Nodes;
        public int Source;
        public int Sink;
        public int[,] Capacity;
        LinkedList<int>[] Neighbours;
        bool[,] NeighbourAdded;

        public MaxFlow(int Nodes)
        {
            this.Nodes = Nodes + 2;
            this.Source = Nodes;
            this.Sink = Nodes + 1;
            Neighbours = new LinkedList<int>[this.Nodes];
            for (int i = 0; i < this.Nodes; i++)
                Neighbours[i] = new LinkedList<int>();
            Capacity = new int[this.Nodes, this.Nodes];
            NeighbourAdded = new bool[this.Nodes, this.Nodes];
        }

        public void Add(int From, int To, int Cap)
        {
            Capacity[From, To] += Cap;
            if (!NeighbourAdded[From, To])
            {
                NeighbourAdded[From, To] = true;
                NeighbourAdded[To, From] = true;
                Neighbours[From].AddLast(To);
                Neighbours[To].AddLast(From);
            }
        }

        public int NetworkFlow()
        {
            int[,] flow = new int[Nodes, Nodes];
            int[] parent = new int[Nodes];
            int[] cap = new int[Nodes];

            int total = 0;
            while (true)
            {
                for (int i = 0; i < Nodes; i++)
                    parent[i] = -1;
                parent[this.Source] = -2;
                cap[this.Source] = int.MaxValue;
                Queue<int> Q = new Queue<int>();
                Q.Enqueue(this.Source);
                while (Q.Count > 0 && parent[this.Sink] == -1)
                {
                    int act = Q.Dequeue();
                    foreach (int next in Neighbours[act])
                    {
                        if (parent[next] == -1 && Capacity[act, next] > flow[act, next])
                        {
                            parent[next] = act;
                            cap[next] = Math.Min(cap[act], Capacity[act, next] - flow[act, next]);
                            Q.Enqueue(next);
                        }
                    }
                }

                if (parent[this.Sink] == -1)
                    return total;

                total += cap[this.Sink];
                int j = this.Sink;
                while (j != this.Source)
                {
                    flow[parent[j], j] += cap[this.Sink];
                    flow[j, parent[j]] -= cap[this.Sink];
                    j = parent[j];
                }
            }
        }
    }
}
