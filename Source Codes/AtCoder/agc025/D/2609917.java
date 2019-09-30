import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static int N;

  public static void main(String[] args) {
    N = sc.nextInt();
    int D1 = sc.nextInt();
    int D2 = sc.nextInt();
    int[][] f1 = solve(D1);
    int[][] f2 = solve(D2);
    PrintWriter writer = new PrintWriter(System.out);
    int c = 0;
    for (int i = 0; i < 2 * N && c < N * N; i++) {
      for (int j = 0; j < 2 * N && c < N * N; j++) {
        if (f1[i][j] == 1 && f2[i][j] == 1) {
          ++c;
          writer.println(i + " " + j);
        }
      }
    }
    writer.flush();
  }

  static int[][] solve(int d) {
    ArrayList<Pair> pairs = new ArrayList<>();
    for (int i = 0; i * i <= d; i++) {
      if (isSq(d - i * i)) {
        int j = (int) Math.sqrt(d - i * i);
        pairs.add(new Pair(i, j));
        pairs.add(new Pair(i, -j));
        pairs.add(new Pair(-i, j));
        pairs.add(new Pair(-i, -j));
      }
    }
    int[][] f = new int[2 * N][2 * N];
    for (int y = 0; y < 2 * N; y++) {
      for (int x = 0; x < 2 * N; x++) {
        if (f[y][x] != 0) continue;
        ArrayList<Integer> cur = new ArrayList<>();
        cur.add((y << 16) | x);
        f[y][x] = 1;
        for (int i = 0; !cur.isEmpty(); i++) {
          ArrayList<Integer> next = new ArrayList<>();
          for (int pos : cur) {
            int cy = pos >> 16;
            int cx = pos & 0xFFFF;
            for (Pair p : pairs) {
              int ny = cy + p.s;
              int nx = cx + p.e;
              if (0 <= ny && ny < 2 * N && 0 <= nx && nx < 2 * N && f[ny][nx] == 0) {
                next.add((ny << 16) | nx);
                f[ny][nx] = i % 2 == 0 ? -1 : 1;
              }
            }
          }
          cur = next;
        }
      }
    }
    return f;
  }

  static boolean isSq(int v) {
    if (v < 0) return false;
    int sqrt = (int) Math.sqrt(v);
    return sqrt * sqrt == v;
  }

  static class Pair {
    int s, e;

    Pair(int s, int e) {
      this.s = s;
      this.e = e;
    }
  }
}