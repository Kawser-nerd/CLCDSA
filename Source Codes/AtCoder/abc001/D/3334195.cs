using System;

namespace ABC001D
{
  class Program
  {
    static readonly int RAIN_START = 0x1;
    static readonly int RAIN_END = 0x2;
    static readonly int RAIN_RUN = 0x4;

    static void Main(string[] args)
    {
      int N = int.Parse(Console.ReadLine());
      int[] rained = new int[290];

      for (int i = 0; i < N; i++) {
        string[] buf = Console.ReadLine().Split('-');
        int start = int.Parse(buf[0]);
        int end = int.Parse(buf[1]);
        int startHour = start / 100;
        int startMinute = (start % 100) / 5;
        int endHour = end / 100;
        int endMinute = (end % 100 + 4) / 5;

        int time = startHour * 12 + startMinute;
        rained[time] |= RAIN_START;

        while (time < endHour * 12 + endMinute) {
          rained[time] |= RAIN_RUN;
          time++;
        }
        
        rained[time] |= RAIN_END;
      }

      bool raining = false;
      string res = string.Empty;

      for (int t = 0; t < rained.Length; t++) {
        if (raining
          && (rained[t] & RAIN_RUN) == 0
          && (rained[t] & RAIN_END) != 0) {
          res += "-" + (t / 12 * 100 + (t % 12) * 5).ToString("D4");
          Console.WriteLine(res);
          raining = false;
        }
        if (!raining && (rained[t] & (RAIN_START | RAIN_RUN)) != 0) {
          res = (t / 12 * 100 + (t % 12) * 5).ToString("D4");
          raining = true;
        }
      }

    }
  }
}