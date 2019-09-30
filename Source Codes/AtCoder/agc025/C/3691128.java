import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    Point[] lefts = new Point[N];
    Point[] rights = new Point[N];
    boolean[] visited = new boolean[N];

    for (int i = 0; i < N; i++) {
      int left = scanner.nextInt();
      int right = scanner.nextInt();
      lefts[i] = new Point(i, left);
      rights[i] = new Point(i, right);
    }
    Arrays.sort(lefts, (o1, o2) -> o2.pos - o1.pos);
    Arrays.sort(rights, Comparator.comparingInt(o -> o.pos));

    long leftd = 0;
    int c = 0;
    int l = 0;
    int r = 0;
    while (l < N && r < N) {
      while (l < N && (visited[lefts[l].id] || lefts[l].pos <= c)) l++;
      if (l < N) {
        leftd += lefts[l].pos - c;
        c = lefts[l].pos;
        visited[lefts[l].id] = true;
      }
      while (r < N && (visited[rights[r].id] || rights[r].pos >= c)) r++;
      if (r < N) {
        leftd += c - rights[r].pos;
        c = rights[r].pos;
        visited[rights[r].id] = true;
      }
    }
    leftd += Math.abs(c);

    long rightd = 0;
    for (int i = 0; i < N; i++) visited[i] = false;
    c = 0;
    l = 0;
    r = 0;
    while (l < N && r < N) {
      while (r < N && (visited[rights[r].id] || rights[r].pos >= c)) r++;
      if (r < N) {
        rightd += c - rights[r].pos;
        c = rights[r].pos;
        visited[rights[r].id] = true;
      }
      while (l < N && (visited[lefts[l].id] || lefts[l].pos <= c)) l++;
      if (l < N) {
        rightd += lefts[l].pos - c;
        c = lefts[l].pos;
        visited[lefts[l].id] = true;
      }
    }
    rightd += Math.abs(c);

    System.out.println(Math.max(leftd, rightd));
  }

  static class Point {
    final int id;
    final int pos;

    Point(int id, int pos) {
      this.id = id;
      this.pos = pos;
    }
  }
}