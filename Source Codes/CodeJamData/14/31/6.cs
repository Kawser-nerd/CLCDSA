namespace ZTGCJ2014.Round_1C
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class PartElf : SolverBase
    {
        public PartElf()
            : base(@"Round 1C\A-large")
            //: base(@"Round 1C\A-small-attempt0")
            //: base(@"Round 1C\sample")
        {
        }

        public override void Solve(InputHelper input)
        {
            const int Max = 40;
            var frag = input.ReadString().Split('/').Select(x => long.Parse(x)).ToArray();
            long a = frag[0], b = frag[1];
            long g = MathUtility.GCD(a, b);
            a /= g; b /= g;
            if (b != (b & -b) || b > (1L << Max))
            {
                this.SetResult("impossible");
            }
            else
            {
                for (int i = 1; i <= Max; ++i)
                {
                    if (a >= (b >> i))
                    {
                        this.SetResult(i);
                        return;
                    }
                }
            }
        }
    }
}
