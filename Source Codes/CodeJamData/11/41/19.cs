using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using GCJ2011;

namespace Round2
{
    public class ProblemA : Problem
    {
        public override string Solve()
        {
            int cases;
            string result = string.Empty;
            int lineIndex = 1;

            cases = int.Parse(this.Lines[0].Trim());
            for (int i = 1; i <= cases; ++i)
            {
                int pos = 0;
                string line = this.Lines[lineIndex++];
                int length = base.ReadNum(line, ref pos);
                int speedWalk = base.ReadNum(line, ref pos);
                int speedRun = base.ReadNum(line, ref pos);
                double timeRun = base.ReadNum(line, ref pos);
                int walkWays = base.ReadNum(line, ref pos);

                List<Segment> segments = new List<Segment>(walkWays + 1);
                int totalLength = 0;

                for (int j = 0; j < walkWays; ++j)
                {
                    line = this.Lines[lineIndex++];
                    pos = 0;
                    int start = base.ReadNum(line, ref pos);
                    int end = base.ReadNum(line, ref pos);
                    int speed = base.ReadNum(line, ref pos);

                    Segment segment = new Segment() { Length = end - start, Speed = speed + speedWalk };
                    segments.Add(segment);
                    totalLength += segment.Length;
                }
                segments.Add(new Segment() { Length = length - totalLength, Speed = speedWalk });

                segments.Sort(new SegmentComparer());

                int speedX = speedRun - speedWalk;
                double totalTime = 0;
                for (int j = 0; j < segments.Count; ++j)
                { 
                    Segment segment = segments[j];
                    int speed = segment.Speed;
                    double tRun = 0;
                    if (timeRun > 0)
                    {
                        tRun = segment.Length / (double)(segment.Speed + speedX);
                        if (tRun <= timeRun)
                        {
                            totalTime += tRun;
                            timeRun -= tRun;
                        }
                        else
                        {
                            totalTime += timeRun;
                            totalTime += (segment.Length - timeRun * (segment.Speed + speedX)) / (double)segment.Speed;
                            timeRun = -1;
                        }
                        continue;
                    }
                    totalTime += (segment.Length - timeRun * (segment.Speed + speedX)) / (double)segment.Speed;
                }

                result += string.Format("Case #{0}: {1}\r\n", i, totalTime);
            }

            return result;
        }
    }

    public struct Segment
    {
        public int Length;
        public int Speed;
    }

    public class SegmentComparer : IComparer<Segment>
    {
        #region IComparer<Segment> Members

        public int Compare(Segment x, Segment y)
        {
            return x.Speed - y.Speed;
        }

        #endregion
    }
}
