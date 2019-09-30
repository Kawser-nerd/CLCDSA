using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC001
{
    public class ABC001_D
    {
        static void Main(string[] args)
        {
            ABC001_D instance = new ABC001_D();
            instance.Answer();
        }

        public class WhetherReport
        {
            public string rainDuration;

            public WhetherReport DataUpdate()
            {
                WhetherReport updatedReport = new WhetherReport();

                int beginningRainTime = GetBeginningRainTime();
                int endingRainTime = GetEndingRainTime();

                beginningRainTime -= beginningRainTime % 5;

                int endingTimeDiff = (endingRainTime % 5);
                endingRainTime += (endingTimeDiff != 0 ? 5 - endingTimeDiff : 0);


                if (endingRainTime % 100 == 60)
                {
                    endingRainTime += 40;
                }

                if (beginningRainTime % 100 == 60)
                {
                    beginningRainTime += 40;
                }

                string begin = beginningRainTime.ToString().PadLeft(4, '0');
                string end = endingRainTime.ToString().PadLeft(4, '0');

                updatedReport.rainDuration = $"{begin}-{end}";

                return updatedReport;
            }

            public override string ToString()
            {
                return $"{rainDuration}";
            }

            public int GetBeginningRainTime()
            {
                return int.Parse(rainDuration.Split('-')[0]);
            }

            public int GetEndingRainTime()
            {
                return int.Parse(rainDuration.Split('-')[1]);
            }

            public bool IsBetweenTheDays(WhetherReport other)
            {
                bool betweenBeginRainTime = GetBeginningRainTime() <= other.GetBeginningRainTime() &&
                                            other.GetBeginningRainTime() <= GetEndingRainTime();
                return betweenBeginRainTime;
            }
            
            public override bool Equals(object obj)
            {
                var p = obj as WhetherReport;
                if (p == null)
                    return false;
                return ToString().Equals(p.ToString());
            }
        }

        public class WhetherReportComparer : IEqualityComparer<WhetherReport>
        {
            public bool Equals(WhetherReport i_lhs, WhetherReport i_rhs)
            {
                return i_lhs.rainDuration == i_rhs.rainDuration;
            }

            public int GetHashCode(WhetherReport i_obj)
            {
                return i_obj.rainDuration.GetHashCode();
            }
        }

        public void Answer()
        {
            int rainNum = Int32.Parse(Console.ReadLine());
            List<WhetherReport> whetherReports = new List<WhetherReport>();
            for (int i = 0; i < rainNum; i++)
            {
                WhetherReport report = new WhetherReport();
                report.rainDuration = Console.ReadLine();
                whetherReports.Add(report);
            }

            WhetherReportComparer comparer = new WhetherReportComparer();
            whetherReports = whetherReports.Distinct(comparer).ToList();

            whetherReports = whetherReports.Select(d => d.DataUpdate()).ToList();

            whetherReports = whetherReports.Distinct(comparer).ToList();
            whetherReports.Sort((a, b) => a.GetBeginningRainTime() - b.GetBeginningRainTime());

            List<WhetherReport> foldingReports = new List<WhetherReport>();
            var beginFoldingReport = whetherReports[0];

            for (int i = 1; i < whetherReports.Count; i++)
            {
                var nextReport = whetherReports[i];

                if (beginFoldingReport.IsBetweenTheDays(nextReport))
                {

                    WhetherReport combineReport = new WhetherReport();
                    if (beginFoldingReport.GetEndingRainTime() <= nextReport.GetEndingRainTime())
                    {
                        var beginTime = beginFoldingReport.GetBeginningRainTime().ToString().PadLeft(4, '0');
                        var endTime = nextReport.GetEndingRainTime().ToString().PadLeft(4, '0');
                        combineReport.rainDuration = $"{beginTime}-{endTime}";
                    }
                    else
                    {
                        var beginTime = beginFoldingReport.GetBeginningRainTime().ToString().PadLeft(4, '0');
                        var endTime = beginFoldingReport.GetEndingRainTime().ToString().PadLeft(4, '0');
                        combineReport.rainDuration = $"{beginTime}-{endTime}";
                    }

                    beginFoldingReport = combineReport;
                }
                else
                {
                    foldingReports.Add(beginFoldingReport);
                    beginFoldingReport = nextReport;
                }
            }

            foldingReports.Add(beginFoldingReport);

            foreach (var whetherReport in foldingReports)
            {
                Console.WriteLine(whetherReport.ToString());
            }
        }
    }
}