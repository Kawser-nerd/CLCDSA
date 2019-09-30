using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            List<DateInfo> calendar = new List<DateInfo>();
            for (int cnt = 1, m = 1, d = 1, l = GetTotalDaysOfMonth(m); cnt <= 366; cnt++)
            {
                calendar.Add(new DateInfo()
                {
                    Month = m,
                    Day = d,
                    Holiday = (cnt % 7) <= 1
                });
                if (++d > l)
                {
                    m += 1;
                    d = 1;
                    l = GetTotalDaysOfMonth(m);
                }
            }

            int N = int.Parse(ReadLine());
            DateTime[] holidaiys = new DateTime[N];
            for (int i = 0; i < N; i++)
            {
                string line = ReadLine();

                int index = calendar.FindIndex(_ => _.Name == line);
                for (; index < calendar.Count; index++)
                {
                    if (!calendar[index].Holiday)
                    {
                        calendar[index].Holiday = true;
                        break;
                    }
                }
            }
            List<int> results = new List<int>();
            int holidays = 0;
            foreach (DateInfo date in calendar)
            {
                if (date.Holiday)
                {
                    holidays++;
                }
                else
                {
                    if (holidays > 0)
                    {
                        results.Add(holidays);
                        holidays = 0;
                    }
                }
            }
            if (holidays > 0)
            {
                results.Add(holidays);
            }
            WriteLine(results.Max());
            ReadLine();
        }
        static int GetTotalDaysOfMonth(int month)
        {
            if (month == 2)
                return 29;
            if (month == 4 || month == 6 || month == 9 || month == 11)
                return 30;
            return 31;
        }
    }
    class DateInfo
    {
        public int Month { get; set; }
        public int Day { get; set; }
        public bool Holiday { get; set; }

        public string Name => $"{Month}/{Day}";
        public override string ToString() => Name;
    }
}