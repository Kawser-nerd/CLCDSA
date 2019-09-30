using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace TrainTimetable
{
    class Program
    {
        public class TimePoint : IComparable<TimePoint>
        {
            public int time;
            public bool departure;

            public TimePoint(int t, bool d)
            {
                time = t;
                departure = d;
            }
            #region IComparable<TimePoint> Members

            public int CompareTo(TimePoint other)
            {
                int res = time.CompareTo(other.time);
                if (res == 0)
                    res = departure.CompareTo(other.departure);
                return res;
            }
            #endregion
        }
        static int strToTime(string s)
        {
            Debug.Assert(s.Length == 5);
            Debug.Assert(s[2] == ':');
            return int.Parse(s.Substring(0, 2)) * 60 + int.Parse(s.Substring(3, 2));
        }

        static int getNumberOfTrain(TimePoint[] times)
        {
            int res = 0;
            int trains = 0;
            for (int i = 0; i < times.Length; ++i)
            {
//                if (i > 0 && times[i].time == times[i - 1].time)
//                    Debug.Assert(times[i - 1].departure.CompareTo(times[i].departure) <= 0);
                if (times[i].departure)
                {
                    if (trains > 0)
                        trains--;
                    else
                        res++;
                }
                else
                    trains++;
            }
            return res;
        }

        static void Main(string[] args)
        {
            string DataFolder = @"C:\Projects\CSharp\CodeJam2008\TrainTimetable\Data\";
            StreamReader sr = File.OpenText(DataFolder + "B-large.in");
            using (StreamWriter sw = File.CreateText(DataFolder + "B-large.out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int i = 0; i < caseCount; ++i)
                {
                    int turnaround = int.Parse(sr.ReadLine());
                    string[] s = sr.ReadLine().Split(' ');
                    int na = int.Parse(s[0]);
                    int nb = int.Parse(s[1]);
                    TimePoint[] timeA = new TimePoint[na + nb];
                    TimePoint[] timeB = new TimePoint[na + nb];

                    for (int j = 0; j < na; ++j)
                    {
                        s = sr.ReadLine().Split(' ');
                        timeA[j] = new TimePoint(strToTime(s[0]), true);
                        timeB[j] = new TimePoint(strToTime(s[1]) + turnaround, false);
                    }
                    for (int j = 0; j < nb; ++j)
                    {
                        s = sr.ReadLine().Split(' ');
                        timeA[na + j] = new TimePoint(strToTime(s[1]) + turnaround, false);
                        timeB[na + j] = new TimePoint(strToTime(s[0]), true);
                    }
                    Array.Sort(timeA);
                    Array.Sort(timeB);

                    sw.WriteLine("Case #" + (i + 1).ToString() + ": " + getNumberOfTrain(timeA).ToString() + ' ' + getNumberOfTrain(timeB).ToString());
                }
            }
        }
    }
}
