namespace ZT.Contests.GCJ2016.Round_2
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using ZT.Common.Contest.GCJ;
    using ZT.Common.InputHelper;

    internal class RatherPerplexingShowdown : GcjSolverBase
    {
        public RatherPerplexingShowdown(GcjContestMain gcjMain) : base(gcjMain, "A", "Round 2") { }

        public override void Solve(InputHelper input)
        {
            var n = input.ReadInt();
            var r = input.ReadInt();
            var p = input.ReadInt();
            var s = input.ReadInt();

            var count = new[] {p, r, s};
            var candidate = new[] {'P', 'R', 'S'};

            var possible = candidate.Select(a => Trans(a, n)).Where(
                a =>
                {
                    var cur = candidate.Select(x => a.Count(c => x == c)).ToList();
                    var check = cur.Select((c, i) => c == count[i]).All(b => b);
                    Console.WriteLine(a + " " + string.Join(",", cur) + " " + check);
                    return check;
                }).OrderBy(a => a).ToList();

            if (!possible.Any())
            {
                this.SetResult("IMPOSSIBLE");
            }
            else
            {
                this.SetResult(possible.First());
            }
        }

        private static readonly Dictionary<char, string> transitions = new Dictionary<char, string> {{'P', "PR"}, {'R', "RS"}, {'S', "PS"}};

        private static Dictionary<Tuple<char, int>, string> cache = new Dictionary<Tuple<char, int>, string>();

        private static string Trans(char start, int n)
        {
            if (n == 0) return new string(start, 1);
            var key = Tuple.Create(start, n);
            string result;
            if (cache.TryGetValue(key, out result))
            {
                return result;
            }

            var trans = transitions[start];
            var first = Trans(trans[0], n - 1);
            var second = Trans(trans[1], n - 1);

            result = first + second;
            var other = second + first;
            return cache[key] = string.Compare(result, other) < 0 ? result : other;
        }
    }
}
