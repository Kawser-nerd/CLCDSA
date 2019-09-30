using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var p = new Program();
            p.Solve();

        }

        void Solve()
        {
            int n = int.Parse(Console.ReadLine());
            Times[] times = new Times[n];
            for (int i = 0; i < n; i++)
            {
                var tmp = Array.ConvertAll(Console.ReadLine().Split('-'), int.Parse);
                times[i] = new Times(new Time(tmp[0]), new Time(tmp[1]));
            }



            foreach (var item in times)
            {
                item.Round();
            }

            //narabekae 
            times = times.OrderBy(x => x.StartTime.HourMinute)
                .ThenBy(x => x.EndTime.HourMinute)
                .ToArray();

            //Console.WriteLine("");
            //foreach (var item in times)
            //{
            //    Console.WriteLine(item.ToString());
            //}
            //Console.WriteLine();
            //

            var ansList = new List<Times>();
            Times time = times[0];
            for (int i = 1; i < n; i++)
            {
                if (times[i].StartTime.HourMinute <= time.EndTime.HourMinute)
                {
                    if (times[i].EndTime.HourMinute <= time.EndTime.HourMinute)
                        continue;
                    time.EndTime = times[i].EndTime;
                }
                else
                {
                    ansList.Add(time);
                    time = times[i];
                }
            }
            ansList.Add(time);
            ansList.ForEach(x => Console.WriteLine(x.ToString()));
        }
    }

    class Times
    {
        public Time StartTime { get; set; }
        public Time EndTime { get; set; }

        public Times(Time startTime, Time endTime)
        {
            StartTime = startTime;
            EndTime = endTime;
        }

        public void Round()
        {
            StartTime.Minute = StartTime.Minute - StartTime.Minute % 5;
            EndTime.Minute = EndTime.Minute + (5 - EndTime.Minute % 5) % 5;
            if(EndTime.Minute>=60)
            {
                EndTime.Minute -= 60;
                EndTime.Hour++;
            }
        }

        public override string ToString()
        {
            return StartTime.ToString() + "-" + EndTime.ToString();
        }
    }

    class Time
    {
        public int Hour { get; set; }
        public int Minute { get; set; }
        public int HourMinute
        {
            get { return Hour * 100 + Minute; }
        }

        public Time(int hourMinute)
        {
            Hour = hourMinute / 100;
            Minute = hourMinute % 100;
        }

        public override string ToString()
        {
            return string.Format("{0:0000}", HourMinute);
        }

    }
}