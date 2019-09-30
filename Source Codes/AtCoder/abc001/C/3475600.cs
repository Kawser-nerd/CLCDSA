using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int deg = arr[0];
    int dis = arr[1];
    int w = W(dis);
    Console.WriteLine(w == 0 ? $"C {w}" : $"{Dir(deg)} {w}");
  }

  static string Dir(int deg) {
    deg *= 10;
    string[] dir = {"NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW",
                     "SW", "WSW", "W", "WNW", "NW", "NNW"};
    if (deg < 1125 || 34875 <= deg) return "N";
    int t = 0;
    for (int i = 1125; i < 34875; i += 2250) {
      if (i <= deg && deg < i + 2250) break;
      else t++;
    }
    return dir[t];
  }

  static int W(double dis) {
    dis = dis * 10 / 60.0;
    int d = (int)Math.Round(dis, MidpointRounding.AwayFromZero);
    int[] w = { 2, 15, 33, 54, 79, 107, 138, 171, 207, 244, 284, 326, 2000 };
    int t = 0;
    for (int i = 0; i < w.Length; i++) {
      if (d <= w[i]) break;
      else t++;
    }
    return t;
  }
}