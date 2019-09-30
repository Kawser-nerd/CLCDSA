namespace ZT.Contests.GCJ2016.Round_1B
{
    using System.Collections.Generic;
    using System.Linq;
    using ZT.Common;
    using ZT.Common.Contest.GCJ;
    using ZT.Common.Extensions;
    using ZT.Common.InputHelper;

    internal class GettingTheDigits : GcjSolverBase
    {
        public GettingTheDigits(GcjContestMain gcjMain) : base(gcjMain, "A", "Round 1B") { }

        public override void Solve(InputHelper input)
        {
            const int n = 10;
            var numbers = Misc.GetNaturalNumber().Take(n).ToList();
            var words = numbers.Select(d => EnglishNumeral.NumbersLessThan20[d].ToUpperInvariant()).ToList();
            var allNumberChars = words.SelectMany(w => w).GroupBy(c => c).ToDictionary(g => g.Key, g => g.Count());

            var st = input.ReadString();
            var inputAll = st.GroupBy(c => c).ToDictionary(g => g.Key, g => g.Count());

            var used = new Dictionary<int, int>();
            while (used.Count < n)
            {
                foreach (var w in numbers.Except(used.Keys))
                {
                    var single = words[w].FirstOrDefault(c => allNumberChars[c] == 1);

                    if (single != default(char))
                    {
                        int u;
                        inputAll.TryGetValue(single, out u);
                        used.Add(w, u);
                        words[w].ForEach(
                            c =>
                            {
                                if (inputAll.ContainsKey(c)) inputAll[c] -= u;
                                --allNumberChars[c];
                            });
                    }
                }
            }

            if (inputAll.Any(p => p.Value != 0))
            {
                throw new ZtCommonException("Solution failed...");
            }

            this.SetResult(string.Join(
                string.Empty,
                used.OrderBy(p => p.Key).Select(
                    p =>
                    {
                        var r = "";
                        for (int i = 0; i < p.Value; ++i) r += p.Key;
                        return r;
                    })));
        }
    }
}
