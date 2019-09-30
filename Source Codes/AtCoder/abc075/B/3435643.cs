using System;
using System.Linq;
using System.Text;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int h = arr[0];
    int w = arr[1];
    var s = new string[h + 2];
    s[0] = new string(' ', w + 2);
    for (int i = 1; i <= h; i++) {
      s[i] = " " + Console.ReadLine() + " ";
    }
    s[h + 1] = new string(' ', w + 2);
    StringBuilder sb = new StringBuilder();
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        int cnt = 0;
        if (s[i][j] == '.') {
          if (s[i - 1][j - 1] == '#') cnt++;
          if (s[i - 1][j] == '#') cnt++;
          if (s[i - 1][j + 1] == '#') cnt++;
          if (s[i][j - 1] == '#') cnt++;
          if (s[i][j + 1] == '#') cnt++;
          if (s[i + 1][j - 1] == '#') cnt++;
          if (s[i + 1][j] == '#') cnt++;
          if (s[i + 1][j + 1] == '#') cnt++;
          sb.Append(cnt);
        } else {
          sb.Append("#");
        }
      }
      sb.AppendLine();
    }
    Console.Write(sb);
  }
}