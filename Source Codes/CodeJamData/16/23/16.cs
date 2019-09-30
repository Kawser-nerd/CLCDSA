namespace ZT.Contests.GCJ2016.Round_1B
{
    using System;
    using System.Collections.Generic;
    using ZT.Common.Contest.GCJ;
    using ZT.Common.InputHelper;

    internal class Technobabble : GcjSolverBase
    {
        public Technobabble(GcjContestMain gcjMain) : base(gcjMain, "C", "Round 1B") { }

        public override void Solve(InputHelper input)
        {
            var n = input.ReadInt();
            var list = new List<Tuple<string, string>>();
            for (var i = 0; i < n; ++i) list.Add(Tuple.Create(input.ReadString(), input.ReadString()));

            var result = 0;
            for (var s = 0; s < (1 << n); ++s)
            {
                var cnt = 0;
                for (var i = 0; i < n; ++i)
                {
                    if ((s & (1 << i)) == 0)
                    {
                        var found = 0;
                        for (var j = 0; j < n; ++j)
                        {
                            if ((s & (1 << j)) != 0)
                            {
                                if (list[i].Item1 == list[j].Item1)
                                {
                                    ++found;
                                    break;
                                }
                            }
                        }

                        for (var j = 0; j < n; ++j)
                        {
                            if ((s & (1 << j)) != 0)
                            {
                                if (list[i].Item2 == list[j].Item2)
                                {
                                    ++found;
                                    break;
                                }
                            }
                        }

                        if (found == 2)
                        {
                            ++cnt;
                        }
                        else
                        {
                            cnt = -1;
                            break;
                        }
                    }
                }
                result = Math.Max(result, cnt);
            }
            this.SetResult(result);
        }
    }
}
