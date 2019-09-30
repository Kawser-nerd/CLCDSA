namespace ZT.Contests.GCJ2016.Round_2
{
    using System;
    using System.Linq;
    using System.Runtime.InteropServices;
    using ZT.Common;
    using ZT.Common.Contest.GCJ;
    using ZT.Common.InputHelper;

    internal class RedTapeCommittee : GcjSolverBase
    {
        public RedTapeCommittee(GcjContestMain gcjMain) : base(gcjMain, "B", "Round 2") { }

        public override void Solve(InputHelper input)
        {
            var n = input.ReadInt();
            var k = input.ReadInt();
            var p = Misc.GetNaturalNumber().Take(n).Select(i => input.ReadDouble()).ToList();

            var res = 0.0;
            for (int i = 0; i < (1 << n); ++i)
            {
                var c = 0;
                for (int j = 0; j < n; ++j) if ((i & (1 << j)) > 0) ++c;
                if (c != k) continue;
                var f = new double[k, k + 1];
                c = 0;
                for (int j = 0; j < n; ++j)
                    if ((i & (1 << j)) > 0)
                    {
                        if (c == 0)
                        {
                            f[c, 0] = 1 - p[j];
                            f[c, 1] = p[j];
                        }
                        else
                        {
                            for (int x = 0; x <= k; ++x)
                                f[c, x] = (x == 0 ? 0.0 : f[c - 1, x - 1])*p[j] + f[c - 1, x]*(1 - p[j]);
                        }

                        ++c;
                    }
                res = Math.Max(res, f[k - 1, k/2]);
            }
            this.SetResult(res);
        }
    }
}
