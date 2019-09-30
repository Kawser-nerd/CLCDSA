import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int M = scanner.nextInt();
    int[][] edges = new int[M][3];

    int[][] dist = new int[N][N];
    int INF = 100_000_000;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dist[i][j] = INF;
    for (int i = 0; i < M; i++) {
      int a = scanner.nextInt() - 1;
      int b = scanner.nextInt() - 1;
      int c = scanner.nextInt();
      edges[i][0] = a;
      edges[i][1] = b;
      edges[i][2] = c;
      dist[a][b] = dist[b][a] = c;
    }

    for (int k = 0; k < N; k++)
      for (int i = 0; i < N; i++)
          for (int j = 0; j < N; j++)
              if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];

    int num = 0;
    for (int i = 0; i < M; i++) {
      int a = edges[i][0];
      int b = edges[i][1];
      int c = edges[i][2];
      if (dist[a][b] == c) num++;
    }
    System.out.println(M - num);
  }
}