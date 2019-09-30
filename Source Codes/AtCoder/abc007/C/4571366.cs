using System;
using System.Collections;
using System.Collections.Generic;

namespace ABC007 {
  class ProblemC {
    class Point {
      public int x;
      public int y;
      public Point(int x, int y) {
        this.x = x;
        this.y = y;
      }
    }
    static void Main(string[] args) {
      string[] str = System.Console.ReadLine().Split(' ');
      int r = int.Parse(str[0]), c = int.Parse(str[1]);
      str = System.Console.ReadLine().Split(' ');
      int sy = int.Parse(str[0]) - 1, sx = int.Parse(str[1]) - 1;
      str = System.Console.ReadLine().Split(' ');
      int gy = int.Parse(str[0]) - 1, gx = int.Parse(str[1]) - 1;
      string[] map = new string[r];
      string str2;
      for (int i = 0; i < r; i++) {
        str2 = System.Console.ReadLine();
        map[i] = str2;
      }

      bool[,] isUsed = new bool[r,c];
      int[,] steps = new int[r,c];
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          isUsed[i, j] = false;
        }
      }
      steps[sy, sx] = 0;
      isUsed[sy, sx] = true;
      int[] dx = new int[]{1, 0, -1, 0}, dy = new int[]{0, 1, 0, -1};
      int ans = 0;
      
      var queue = new Queue<Point>();
      queue.Enqueue(new Point(sx, sy));

      while (queue.Count > 0) {
        var q = queue.Dequeue();
        if (q.x == gx && q.y == gy) {
          ans = steps[gy, gx];
          break;
        }

        for (int i = 0; i < 4; i++) {
          int xx = q.x + dx[i], yy = q.y + dy[i];
          if (map[yy][xx] != '#' && !isUsed[yy, xx]) {
            queue.Enqueue(new Point(xx, yy));
            steps[yy, xx] = steps[q.y, q.x] + 1;
            isUsed[yy, xx] = true;
          }
        }
      }

      // for (int i = 0; i < r; i++) {
      //   for (int j = 0; j < c; j++) {
      //     System.Console.Write(steps[i, j] + " ");
      //   }
      //   System.Console.WriteLine();
      // }
      System.Console.WriteLine(ans);
    }
  }
}