namespace ZTGCJ2014.Round_1A
{
    using System;
    using System.Collections.Generic;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class FullBinaryTree : SolverBase
    {
        public FullBinaryTree()
            //: base(@"Round 1A\B-small-attempt0")
            : base(@"Round 1A\B-large")
        {
        }

        public override void Solve(InputHelper input)
        {
            int N = input.ReadInt();

            this.edge = new List<List<int>>();

            // index start from 1
            for (int i = 0; i <= N; ++i)
                this.edge.Add(new List<int>());

            for (int i = 1; i < N; ++i)
            {
                int x = input.ReadInt();
                int y = input.ReadInt();
                this.edge[x].Add(y);
                this.edge[y].Add(x);
            }

            int r = int.MaxValue;
            for (int i = 1; i <= N; ++i)
            {
                var cur = Dfs(i, -1);
                r = Math.Min(cur.Item2, r);
            }

            this.SetResult(r);
        }

        private List<List<int>> edge;

        private Tuple<int, int> Dfs(int x, int f)
        {
            int[] g = new int[3];
            g[1] = g[2] = int.MaxValue / 2;
            foreach (var y in this.edge[x])
            {
                if (y == f) continue;
                var cur = Dfs(y, x);
                g[2] = Math.Min(g[1] + cur.Item2, g[2] + cur.Item1);
                g[1] = Math.Min(g[0] + cur.Item2, g[1] + cur.Item1);
                g[0] += cur.Item1;
            }
            return Tuple.Create(g[0] + 1, Math.Min(g[0], g[2]));
        }
    }
}