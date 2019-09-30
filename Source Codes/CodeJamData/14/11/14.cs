namespace ZTGCJ2014.Round_1A
{
    using System.Collections.Generic;
    using System.Linq;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class ChargingChaos : SolverBase
    {
        public ChargingChaos()
            : base(@"Round 1A\A-small-attempt0")
            //: base(@"Round 1A\sample")
        {
        }

        public override void Solve(InputHelper input)
        {
            int N = input.ReadInt(), L = input.ReadInt();
            var flows = ReadBitString(input, N).ToArray();
            var devices = ReadBitString(input, N).ToArray();
            var cnt = new Dictionary<long, int>();

            devices.ForEach(d => new HashSet<long>(flows.Select(f => d ^ f)).ForEach(x => cnt[x] = cnt.ContainsKey(x) ? cnt[x] + 1 : 1));

            if (cnt.Values.Any(x => x == N))
            {
                this.SetResult(cnt.Where(pr => pr.Value == N).Select(pr => pr.Key.GetBits().Count()).Min());
            }
            else
            {
                this.SetResult("NOT POSSIBLE");
            }
        }

        private static IEnumerable<long> ReadBitString(InputHelper input, int n)
        {
            for (int i = 0; i < n; ++i)
                yield return input.ReadString().Aggregate(0, (pre, c) => (pre << 1) | (c - '0'));
        }
    }
}
