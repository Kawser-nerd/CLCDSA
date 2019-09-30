using System;
using System.Collections.Generic;
using System.Linq;
using GoogleCodeJam.Utilities;

namespace GoogleCodeJam2017.Round1C
{
    public class B
    {
        public static void Main(string[] args)
        {
            var numberOfCases = IO.ReadInt();
            for (var i = 0; i < numberOfCases; i++)
            {
                var result = Calculate();
                IO.Write(i + 1, result);
            }
        }

        public static int Calculate()
        {
            var input = IO.ReadIntArray();
            var acn = input[0];
            var ajn = input[1];

            var ac = IO.ReadIntJagged(acn).Select(x=> new Activity(x[0], x[1], true));
            var aj = IO.ReadIntJagged(ajn).Select(x => new Activity(x[0], x[1], false));

            var activities = ac.Concat(aj).OrderBy(x => x.Start).ToArray();

            var lastWasCameron = activities.First().IsCameron;
            var exchanges = 0;
            var mightExchangeGaps = new List<Activity>();

            var minCTime = activities.Where(x => !x.IsCameron).Sum(x => x.Length);
            var maxCTime = minCTime;

            for (var i = 1; i < activities.Length; i++)
            {
                var a = activities[i];
                var last = activities[i - 1];

                if (lastWasCameron != a.IsCameron)
                {
                    lastWasCameron = a.IsCameron;
                    exchanges++;
                    maxCTime += a.Start - last.End;
                }
                else
                {
                    if (!a.IsCameron)
                    {
                        minCTime += a.Start - last.End;
                        maxCTime += a.Start - last.End;
                    }

                    mightExchangeGaps.Add(new Activity(last.End, a.Start, !a.IsCameron));
                }
            }

            var a1 = activities[0];
            var last1 = activities[acn+ajn-1];

            if (lastWasCameron != a1.IsCameron)
            {
                lastWasCameron = a1.IsCameron;
                exchanges++;
                maxCTime += a1.Start + (1440 - last1.End);
            }
            else
            {
                if (!a1.IsCameron)
                {
                    minCTime += a1.Start + (1440 - last1.End);
                    maxCTime += a1.Start + (1440 - last1.End);
                }


                mightExchangeGaps.Add(new Activity(last1.End, 1440 + a1.Start, !a1.IsCameron));
            }

            if (minCTime <= 720 && maxCTime >= 720)
            {
                return Math.Max(exchanges, 2);
            }

            // else need to exchange in gaps
            var gapsByTime = mightExchangeGaps.OrderByDescending(x => x.Length);
            var timeLeft = minCTime > 720 ? minCTime - 720 : 720 - maxCTime;
            foreach (var g in gapsByTime)
            {
                timeLeft -= g.Length;
                exchanges += 2;
                if (timeLeft <= 0)
                {
                    return Math.Max(exchanges, 2);
                }
            }

            return Math.Max(exchanges, 2);
        }

        private class Activity
        {
            public int Start { get; set; }
            public int End { get; set; }
            public bool IsCameron { get; set; }
            public int Length => End - Start;

            public Activity(int start, int end, bool isCameron)
            {
                Start = start;
                End = end;
                IsCameron = isCameron;
            }
        }
    }
}
