namespace ZTGCJ2014.Round_2
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class UpAndDown : SolverBase
    {
        public UpAndDown()
            : base(@"Round 2\B-large")
            //: base(@"Round 2\B-small-attempt1")
            //: base(@"Round 2\sample")
        {
        }

        public override void Solve(InputHelper input)
        {
            int n = input.ReadInt();
            var S = new List<int>();
            for (int i = 0; i < n; ++i) S.Add(input.ReadInt());

            var T = new List<int>(S);
            T.Sort();

            int r = 0;
            foreach (var x in T)
            {
                int y = S.FindIndex(d => d == x);
                r += Math.Min(y, S.Count() - y - 1);
                S.RemoveAt(y);
            }
            this.SetResult(r);
        }
    }
}
