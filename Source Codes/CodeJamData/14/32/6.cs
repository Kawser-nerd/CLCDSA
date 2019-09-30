namespace ZTGCJ2014.Round_1C
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class ReorderingTrainCars : SolverBase
    {
        public ReorderingTrainCars()
            : base(@"Round 1C\B-large")
            //: base(@"Round 1C\B-small-attempt0")
            //: base(@"Round 1C\sample")
        {
        }

        public override void Solve(InputHelper input)
        {
            int n = input.ReadInt();
            var trains = new List<string>();
            for (int i = 0; i < n; ++i) trains.Add(input.ReadString());
            //var easy = this.SolveEasy(n, trains);
            this.SetResult(this.SolveHard(n, trains));
        }

        private const long Mod = 1000000007;

        private int SolveHard(int n, List<string> trains)
        {
            var eIn = new Dictionary<int, int>();
            var eOut = new Dictionary<int, int>();
            var cnt = new Dictionary<int, int>();
            var middle = new HashSet<int>();
            foreach (var s in trains)
            {
                List<char> cur;
                if (Valid(s, out cur))
                {
                    cur.Skip(1).Take(cur.Count - 2).ForEach(x => middle.Add(x - 'a'));

                    int first = cur.First() - 'a';
                    int last = cur.Last() - 'a';

                    if (first == last)
                    {
                        cnt[first] = cnt.ContainsKey(first) ? cnt[first] + 1 : 1;
                    }
                    else if (eOut.ContainsKey(first))
                    {
                        return 0;
                    }
                    else if (eIn.ContainsKey(last))
                    {
                        return 0;
                    }
                    else
                    {
                        eOut.Add(first, last);
                        eIn.Add(last, first);
                    }
                }
                else
                {
                    return 0;
                }
            }

            if (eIn.Keys.Intersect(middle).Count() > 0 ||
                eOut.Keys.Intersect(middle).Count() > 0)
            {
                return 0;
            }

            long res = 1;
            int segs = 0;
            var used = new HashSet<int>();
            foreach (var i in eOut.Keys.Union(cnt.Keys).Where(x => !eIn.ContainsKey(x)))
            {
                res = res * ++segs % Mod;
                var cur = i;
                var lst = new List<int>();
                while (true)
                {
                    lst.Add(cur);
                    if (eOut.ContainsKey(cur))
                    {
                        cur = eOut[cur];
                        if (cur == lst.First()) break;
                    }
                    else
                    {
                        break;
                    }
                }
                if (lst.Count > 1 && cur == lst.First()) return 0;
                lst.ForEach(x => used.Add(x));
            }

            if (eOut.Keys.Union(cnt.Keys).Except(used).Count() > 0) return 0;

            foreach (var c in cnt.Values)
                for (int i = 1; i <= c; ++i)
                    res = res * i % Mod;

            return (int)res;
        }

        private int SolveEasy(int n, List<string> trains)
        {
            var array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = i;
            int cnt = 0;
            var res = new StringBuilder();
            do
            {
                res.Clear();
                array.ForEach(x => res.Append(trains[x]));
                List<char> dummy;
                if (Valid(res.ToString(), out dummy)) ++cnt;
            } while (array.NextPermutation());
            return cnt;
        }

        private bool Valid(string s, out List<char> res)
        {
            res = new List<char>();
            var set = new HashSet<char>();
            char last = ' ';
            foreach (var c in s)
            {
                if (c != last)
                {
                    if (set.Contains(c))
                    {
                        return false;
                    }
                    else
                    {
                        last = c;
                        res.Add(last);
                        set.Add(c);
                    }
                }
            }
            return true;
        }
    }
}
