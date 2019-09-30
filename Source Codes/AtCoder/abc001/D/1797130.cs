using System;
using System.Globalization;

 using System.Collections.Generic;
 using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Threading;

// using System.Text;
public class Program
{
    public static void Main(string[] args)
    {
        // ????????
        var a = int.Parse(Console.ReadLine());
        // ????????????? Deg Dis
        var rainTimes = new List<RainTime>();
        for (var i = 0; i < a; i++)
        {
            var input = Console.ReadLine().Split('-');
            rainTimes.Add(new RainTime(input[0], input[1]));
        }
        
        rainTimes.Sort((x, y) => x.StartRain.CompareTo(y.StartRain));

        var outRainTimes = new List<RainTime>() {rainTimes[0]};

        foreach (var list in rainTimes)
        {
            if (list.StartRain.CompareTo(outRainTimes.Last().EndRain) > 0)
            {
                outRainTimes.Add(list);
            }

            if (list.StartRain.CompareTo(outRainTimes.Last().StartRain) >= 0)
            {

                if (list.StartRain.CompareTo(outRainTimes.Last().EndRain) == 1)
                {
                    continue;
                }

                if (list.EndRain.CompareTo(outRainTimes.Last().EndRain) == 0)
                {
                    continue;
                }
                else if (list.EndRain.CompareTo(outRainTimes.Last().EndRain) == 1)
                {
                    outRainTimes.Last().EndRain = list.EndRain;
                }
            }
        }

        foreach (var output in outRainTimes)
        {
            Console.WriteLine(output.OutStr());
        }
        Console.ReadLine();
    }

    class RainTime
    {

        private static readonly TimeSpan Interval = TimeSpan.FromMinutes(5);

        public RainTime(string start, string end)
        {
            
            var st = (start == "2400") ? TimeSpan.FromDays(1):TimeSpan.ParseExact(start, @"hhmm", null);
            var ed = (end == "2400") ? TimeSpan.FromDays(1) : TimeSpan.ParseExact(end, @"hhmm", null);
            
            // ???,start????end???
            this.StartRain = new TimeSpan(((st.Ticks + Interval.Ticks) / Interval.Ticks - 1) * Interval.Ticks);
            this.EndRain = new TimeSpan((ed.Ticks + Interval.Ticks - 1) / Interval.Ticks * Interval.Ticks);
            
        }

        public TimeSpan StartRain { get; set; }
        public TimeSpan EndRain { get; set; }

        public string OutStr()
        {
            var outst = "";
            outst += (StartRain.Days == 1) ? "2400" : StartRain.ToString("hhmm");
            outst += "-";
            outst += (EndRain.Days == 1) ? "2400" : EndRain.ToString("hhmm");
            return outst;
        }
    }
}