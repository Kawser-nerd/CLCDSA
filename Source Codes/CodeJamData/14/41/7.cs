namespace ZTGCJ2014.Round_2
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class DataPacking : SolverBase
    {
        public DataPacking()
            : base(@"Round 2\A-large")
            //: base(@"Round 2\A-small-attempt0")
            //: base(@"Round 2\sample")
        {
        }

        public override void Solve(InputHelper input)
        {
            int n = input.ReadInt(), x = input.ReadInt();
            var S = new List<int>();
            for (int i = 0; i < n; ++i) S.Add(input.ReadInt());
            S.Sort();

            int res = 0;
            while (S.Count > 0)
            {
                int m = S.Last();
                S.RemoveAt(S.Count() - 1);

                if (S.Count > 0)
                {
                    int s = -1, t = S.Count();
                    while (s + 1 < t)
                    {
                        int d = (s + t) / 2;
                        if (S[d] + m <= x) s = d;
                        else t = d;
                    }

                    if (s > -1)
                    {
                        S.RemoveAt(s);
                    }
                }

                ++res;
            }

            this.SetResult(res);
        }
    }
}
