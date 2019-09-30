using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using GCJ2011;

namespace Round2
{
    public class ProblemD : Problem
    {
        public override string Solve()
        {
            int cases;
            string result = string.Empty;
            int lineIndex = 1;

            cases = int.Parse(this.Lines[0].Trim());
            for (int i = 1; i <= cases; ++i)
            {
                string line = this.Lines[lineIndex++];
                int pos = 0;
                p = base.ReadNum(line, ref pos);
                int w = base.ReadNum(line, ref pos);

                map = new List<int>[p + 1];
                for (int j = 0; j <= p; ++j)
                {
                    map[j] = new List<int>();
                }

                line = this.Lines[lineIndex++];
                pos = 0;
                for (int j = 0; j < w; ++j)
                {
                    int n = base.ReadNum(line, ref pos);
                    int m = base.ReadNum(line, ref pos);
                    map[n].Add(m);
                    map[m].Add(n);
                }
                threating = new int[p + 1];
                conquered = new bool[p + 1];
                leastConquer = p + 1;
                mostThreat = -1;

                this.Conquer(0, 0);

                result += string.Format("Case #{0}: {1} {2}\r\n", i, leastConquer, mostThreat);
            }

            return result;
        }

        List<int>[] map;
        int p;
        int leastConquer, mostThreat;
        int[] threating;
        bool[] conquered;

        private void Conquer(int current, int step)
        {
            if (step > leastConquer)
                return;
            for (int i = 0; i < map[current].Count; ++i)
            {
                ++threating[map[current][i]];
            }

            if (threating[1] > 0)
            {
                int c = 0, t = 0;
                for (int i = 1; i < p; ++i)
                {
                    if (conquered[i])
                        ++c;
                    if (threating[i] > 0 && !conquered[i])
                        ++t;
                }

                if (c < leastConquer)
                {
                    leastConquer = c;
                    mostThreat = t;
                }
                else if (c == leastConquer && t >= mostThreat)
                {
                    mostThreat = t;
                }
            }

            for (int i = 0; i < map[current].Count; ++i)
            {
                if (threating[map[current][i]] > 0 && !conquered[map[current][i]])
                {
                    conquered[map[current][i]] = true;
                    this.Conquer(map[current][i], step + 1);
                    conquered[map[current][i]] = false;
                }
            }

            for (int i = 0; i < map[current].Count; ++i)
            {
                --threating[map[current][i]];
            }
        }
    }
}
