import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int M = scanner.nextInt();

    final long INF = -1_000_000_000_000_000L;
    long[] dist = new long[N];
    for (int i = 1; i < N; i++) dist[i] = INF;
    int[][] edges = new int[M][2];
    int[] costs = new int[M];

    for (int i = 0; i < M; i++) {
      edges[i] = new int[] {scanner.nextInt() - 1, scanner.nextInt() - 1};
      costs[i] = scanner.nextInt();
    }

    int[] prev = new int[N];
    prev[0] = -1;
    for (int i = 0; i < 2 * N; i++) {
      for (int j = 0; j < M; j++) {
        int from = edges[j][0];
        int to = edges[j][1];
        int cost = costs[j];
        if (dist[from] > INF) {
          long newValue = dist[from] + cost;
          if (newValue > dist[to]) {
            dist[to] = newValue;
            prev[to] = from;
          }
        }
      }
    }

    boolean[] visited = new boolean[N];
    int i = N - 1;
    while (i != -1) {
      visited[i] = true;
      i = prev[i];
      if (i >= 0 && visited[i]) {
        System.out.println("inf");
        return;
      }
    }
    System.out.println(dist[N - 1]);
  }
}