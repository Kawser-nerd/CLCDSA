using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class B
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);

            string ans = Solve();
            Console.WriteLine("Case #" + CASE + ": " + (ans == null ? "IMPOSSIBLE" : ans));
        }
    }

    public static string Solve()
    {
        // Read input
        string[] ps = Console.ReadLine().Split();
        int N = int.Parse(ps[0]);
        int R = int.Parse(ps[1]);
        int O = int.Parse(ps[2]);
        int Y = int.Parse(ps[3]);
        int G = int.Parse(ps[4]);
        int B = int.Parse(ps[5]);
        int V = int.Parse(ps[6]);

        // Static stuff
        int[] counts = new int[6];
        string chars = "RYBGVO";
        counts[0] = R;
        counts[1] = Y;
        counts[2] = B;
        counts[3] = G;
        counts[4] = V;
        counts[5] = O;
        bool[,] conflicts = new bool[7, 7];
        for (int i = 0; i < 6; i++)
            conflicts[i, i] = true;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != j)
                    conflicts[i, 3 + j] = conflicts[3 + j, i] = true;

        // Do a matching to find a neighbour for everyone
        MaxFlow mf = new MaxFlow(N * 2);
        int idx = 0;
        int[] col = new int[N];
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < counts[i]; j++)
                col[idx++] = i;
        for (int i = 0; i < N; i++)
        {
            mf.Add(mf.Source, i, 1);
            mf.Add(N + i, mf.Sink, 1);
            for (int j = 0; j < N; j++)
                if (!conflicts[col[i], col[j]])
                    mf.Add(i, N + j, 1);
        }
        if (mf.NetworkFlow() != N) return null;
        int[] next = new int[N];
        for(int i = 0; i < N; i++)
            while (mf.flow[i, N + next[i]] == 0)
                next[i]++;

        // Construct cycles
        bool[] done = new bool[N];
        List<List<int>> cycles = new List<List<int>>();
        for(int i = 0; i < N; i++)
        {
            if (done[i]) continue;
            List<int> cycle = new List<int>();
            cycle.Add(i);
            int cur = next[i];
            while(cur != i)
            {
                done[cur] = true;
                cycle.Add(cur);
                cur = next[cur];
            }
            cycles.Add(cycle);
        }

        while (cycles.Count > 1)
        {
            // merge two cycles
            bool found = false;
            int mergeC = -1;
            int mergeI = -1;
            int mergeK = -1;
            for (int i = 0; !found && i < cycles[0].Count; i++)
            {
                for (int j = 1; !found && j < cycles.Count; j++)
                {
                    for (int k = 0; !found && k < cycles[j].Count; k++)
                    {
                        if (col[cycles[0][i]] == col[cycles[j][k]])
                        {
                            found = true;
                            mergeC = j;
                            mergeI = i;
                            mergeK = k;
                        }
                    }
                }
            }
            if (!found) return null;
            List<int> comb = new List<int>();

            comb.AddRange(cycles[0].GetRange(0, mergeI));
            comb.AddRange(cycles[mergeC].GetRange(mergeK, cycles[mergeC].Count - mergeK));
            comb.AddRange(cycles[mergeC].GetRange(0, mergeK));
            comb.AddRange(cycles[0].GetRange(mergeI, cycles[0].Count - mergeI));

            cycles.RemoveAt(0);
            cycles.RemoveAt(0);
            cycles.Add(comb);
        }

        // Construct the anwer
        char[] res = new char[N];
        for (int i = 0; i < N; i++)
            res[i] = chars[col[cycles[0][i]]];
        return new string(res);
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

        public int[,] flow;
        private int[] visit;
        private int it;

        public int NetworkFlow()
        {
            flow = new int[Nodes, Nodes];
            visit = new int[Nodes];
            int res = 0;
            it = 1;
            for (it = 1; dfs(Source); it++)
                res++;
            return res;
        }

        private bool dfs(int cur)
        {
            if (cur == Sink) return true;
            if (visit[cur] == it) return false;
            visit[cur] = it;
            foreach(int nb in Neighbours[cur])
            {
                if(flow[cur, nb] < Capacity[cur, nb] && dfs(nb))
                {
                    flow[cur, nb]++;
                    flow[nb, cur]--;
                    return true;
                }
            }
            return false;
        }
    }


    static Random rand = new Random();

    // Random greedy
    public static string Try(int N, int R, int O, int Y, int G, int B, int V)
    {
        int[] ans = new int[N];
        int[] counts = new int[6];

        // Order matters
        string chars = "RYBGVO";
        counts[0] = R;
        counts[1] = Y;
        counts[2] = B;
        counts[3] = G;
        counts[4] = V;
        counts[5] = O;
        bool[,] conflicts = new bool[7, 7];
        for(int i = 0; i < 6; i++)
            conflicts[i, i] = true;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != j)
                    conflicts[i, 3 + j] = conflicts[3 + j, i] = true;
        
        
        // Now fill in greedily with some randomness
        int prev = 6;
        for (int i = 0; i < N; i++)
        {
            List<int> possible = new List<int>();
            int leftsum = 0;
            for (int j = 0; j < 6; j++)
            {
                if (counts[j] > 0 && !conflicts[j, prev])
                {
                    possible.Add(j);
                    leftsum += counts[j] * (j >= 3 ? 2 : 1);
                }
            }
            if (possible.Count == 0)
                return null;

            int pick = rand.Next(leftsum);
            for(int j = 0; j < possible.Count; j++)
            {
                if(pick <= counts[possible[j]])
                {
                    ans[i] = possible[j];
                    counts[ans[i]]--;
                    prev = ans[i];
                    break;
                }
                pick -= counts[possible[j]] * (possible[j] >= 3 ? 2 : 1);
            }
        }

        // Is the end allright?
        if (conflicts[ans[0], ans[N-1]]) return null;

        // Construct the naswer
        char[] cs = new char[N];
        for (int i = 0; i < N; i++)
            cs[i] = chars[ans[i]];
        return new string(cs);
    }
}
