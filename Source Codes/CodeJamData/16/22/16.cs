namespace ZT.Contests.GCJ2016.Round_1B
{
    using System;
    using System.Linq;
    using ZT.Common.Contest.GCJ;
    using ZT.Common.InputHelper;

    internal class CloseMatch : GcjSolverBase
    {
        public CloseMatch(GcjContestMain gcjMain) : base(gcjMain, "B", "Round 1B", false)
        {
            this.bases = new long[19];
            this.bases[0] = 1;
            for (var i = 1; i <= 18; ++i) this.bases[i] = this.bases[i - 1]*10;
        }

        public override void Solve(InputHelper input)
        {
            this.cStr = input.ReadString().ToArray();
            this.jStr = input.ReadString().ToArray();
            this.minDiff = this.bases.Last();
            this.Result = null;
            this.Search(0, 0L);
        }

        private readonly long[] bases;
        private char[] cStr, jStr;
        private long minDiff;
        private static readonly bool bruteForce = false;

        private void Search(int index, long diff)
        {
            if (Math.Abs(diff) >= minDiff + this.bases[this.cStr.Length - index])
            {
                return;
            }

            if (index == this.cStr.Length)
            {
                if (Math.Abs(diff) > this.minDiff) return;

                if (Math.Abs(diff) < this.minDiff)
                {
                    this.minDiff = Math.Abs(diff);
                    this.Result = null;
                }

                var currentResult = string.Join(string.Empty, cStr.Concat(new[] {' '}).Concat(jStr));

                if (this.Result == null || string.Compare(currentResult, this.Result.ToString(), StringComparison.InvariantCultureIgnoreCase) < 0)
                {
                    this.SetResult(currentResult);
                }

                return;
            }

            Func<long> curDiff = () => (cStr[index] - jStr[index])* this.bases[this.cStr.Length - index - 1];
            Action search = () => this.Search(index + 1, diff + curDiff());

            char[] currentStr = cStr, otherStr = jStr;
            Action<char> tryFunc = c =>
            {
                if (c < '0' || c > '9') return;
                currentStr[index] = c;
                search();
                currentStr[index] = '?';
            };

            var cond = (cStr[index] == '?' ? 2 : 0) + (jStr[index] == '?' ? 1 : 0);

            switch (cond)
            {
                case 3:
                    if (bruteForce)
                    {
                        for (var i = '0'; i <= '9'; ++i)
                        {
                            otherStr[index] = i;
                            for (var j = '0'; j <= '9'; ++j) tryFunc(j);
                            otherStr[index] = '?';
                        }
                    }
                    else
                    {
                        if (diff < 0)
                        {
                            otherStr[index] = '0';
                            tryFunc('9');
                            otherStr[index] = '?';
                        }
                        else if (diff > 0)
                        {
                            otherStr[index] = '9';
                            tryFunc('0');
                            otherStr[index] = '?';
                        }
                        else
                        {
                            Action<char> curTryFunc = c =>
                            {
                                otherStr[index] = c;
                                tryFunc('0');
                                tryFunc('1');
                                otherStr[index] = '?';
                            };

                            curTryFunc('0');
                            curTryFunc('1');
                        }
                    }
                    break;
                case 0:
                    search();
                    break;
                default:
                    if (cond == 1)
                    {
                        currentStr = jStr;
                        otherStr = cStr;
                    }

                    if (bruteForce)
                    {
                        for (var j = '0'; j <= '9'; ++j) tryFunc(j);
                    }
                    else
                    {
                        if (diff == 0)
                        {
                            var o = otherStr[index];
                            tryFunc(o);
                            tryFunc((char)(o - 1));
                            tryFunc((char)(o + 1));
                        }
                        else
                        {
                            tryFunc((diff >= 0) == (cond == 2) ? '0' : '9');
                        }
                    }

                    break;
            }
        }
    }
}
