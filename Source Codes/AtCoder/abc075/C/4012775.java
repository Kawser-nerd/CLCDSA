import java.util.*;

public class Main {
  public static int N;
  public static int M;
  public static boolean[][] path;
  public static boolean[] visit;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    M = sc.nextInt();
    int[] a = new int[M];
    int[] b = new int[M];
    for (int i = 0; i < M; i++) {
      a[i] = sc.nextInt() - 1;
      b[i] = sc.nextInt() - 1;
    }
    path = new boolean[N][N];
    visit = new boolean[N];
    int ans = 0;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        Arrays.fill(path[j], false);
      }
      Arrays.fill(visit, false);
      for (int j = 0; j < M; j++) {
        path[a[j]][b[j]] = true;
        path[b[j]][a[j]] = true;
      }
      path[a[i]][b[i]] = false;
      path[b[i]][a[i]] = false;
      dfs(0);
      boolean allVisit = true;
      for (int j = 0; j < N; j++) {
        if (!visit[j]) {
          allVisit = false;
        }
      }
      if (!allVisit) {
        ans++;
      }
    }
    System.out.println(ans);
  }

  public static void dfs(int point) {
    visit[point] = true;
    for (int i = 0; i < N; i++) {
      if (path[point][i] && !visit[i]) {
        dfs(i);
      }
    }
  }
}