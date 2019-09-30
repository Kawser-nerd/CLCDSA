import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int M = scanner.nextInt();
    int R = scanner.nextInt();

    int[][] edges = new int[M][3];
    int[] r = new int[R];

    for (int i = 0; i < R; i++) r[i] = scanner.nextInt() - 1;
    for (int i = 0; i < M; i++) {
      edges[i][0] = scanner.nextInt() - 1;
      edges[i][1] = scanner.nextInt() - 1;
      edges[i][2] = scanner.nextInt();
    }

    final int[][] dist = new int[N][N];
    final int INF = 100_000_000;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (i != j) dist[i][j] = INF;
    for (int i = 0; i < M; i++) dist[edges[i][0]][edges[i][1]] = dist[edges[i][1]][edges[i][0]] = edges[i][2];

    for (int k = 0; k < N; k++) {
      for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
          dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    int cost = Integer.MAX_VALUE;
    int[] order = new int[R];
    for (int i = 0; i < R; i++) order[i] = i;
    do {
      int c = 0;
      for (int i = 0; i < R - 1; i++) {
        c += dist[r[order[i]]][r[order[i + 1]]];
      }
      cost = Math.min(cost, c);
    } while (next(order));
    System.out.println(cost);
  }

  public static boolean next(int[] p) {
    final int n = p.length;

    int i = n - 1;
    while (i > 0 && p[i - 1] >= p[i]) i--;
    if (i <= 0) return false;

    int j = n - 1;
    while (j >= i && p[j] <= p[i - 1]) j--;

    swap(p, i - 1, j);

    j = n - 1;
    while (i < j) swap(p, i++, j--);

    return true;
  }

  private static void swap(int[] a, int i, int j) {
    int tmp = a[j];
    a[j] = a[i];
    a[i] = tmp;
  }
}