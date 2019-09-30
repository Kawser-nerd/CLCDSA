namespace ZTGCJ2014.Round_2
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class TrieSharding : SolverBase
    {
        public TrieSharding()
            //: base(@"Round 2\D-large")
            : base(@"Round 2\D-small-attempt0")
            //: base(@"Round 2\sample")
        {
        }

        public override void Solve(InputHelper input)
        {
            int M = input.ReadInt(), N = input.ReadInt();
            var S = new List<string>();
            for (int i = 0; i < M; ++i) S.Add(input.ReadString());

            this.max = int.MinValue;
            this.count = 0;
            var sets = new Stack<string>[N];
            for (int i = 0; i < N; ++i) sets[i] = new Stack<string>();
            this.CalMethods(S, sets, 0);
            this.SetResult(string.Format("{0} {1}", this.max, this.count));
        }

        private int max = int.MinValue;
        private int count;

        private void CalMethods(List<string> S, Stack<string>[] stacks, int i)
        {
            if (i == S.Count)
            {
                if (stacks.All(x => x.Count > 0))
                {
                    int cnt = 0;
                    foreach (var stk in stacks)
                    {
                        var r = new HashSet<string>();
                        foreach (var s in stk)
                        {
                            for (int c = 0; c < s.Length; ++c)
                                r.Add(s.Substring(0, c + 1));
                        }
                        cnt += r.Count + 1;
                    }
                    if (cnt > this.max)
                    {
                        this.max = cnt;
                        this.count = 0;
                    }
                    if (cnt == this.max)
                    {
                        ++this.count;
                    }
                }
            }
            else
            {
                for (int j = 0; j < stacks.Length; ++j)
                {
                    stacks[j].Push(S[i]);
                    CalMethods(S, stacks, i + 1);
                    stacks[j].Pop();
                }
            }
        }
    }
}
