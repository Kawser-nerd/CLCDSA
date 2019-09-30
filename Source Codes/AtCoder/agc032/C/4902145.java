import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int M = scanner.nextInt();
    int[] edges = new int[M];
    List<Integer>[] n2e = new List[N];
    for (int i = 0; i < N; i++) n2e[i] = new ArrayList<>();
    for (int i = 0; i < M; i++) {
      int a = scanner.nextInt() - 1;
      int b = scanner.nextInt() - 1;
      n2e[a].add(i);
      n2e[b].add(i);
      edges[i] = a ^ b;
    }

    if (solve(N, M, n2e, edges)) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }

  private static boolean solve(int N, int M, List<Integer>[] n2e, int[] edges) {
    int numOver4 = 0;
    int numOver6 = 0;
    for (List<Integer> es : n2e) {
      if (es.size() % 2 == 1) return false;
      if (es.size() >= 4) numOver4++;
      if (es.size() >= 6) numOver6++;
    }

    if (numOver6 >= 1) return true;
    if (numOver4 >= 3) return true;
    if (numOver4 < 2) return false;

    int n = -1;
    for (int i = 0; i < N; i++) {
      if (n2e[i].size() >= 4) {
        n = i;
        break;
      }
    }

    int[] pred = new int[N];
    Arrays.fill(pred, -1);
    List<List<Integer>> loops = new ArrayList<>();
    dfs(0, n, n, N, M, n2e, edges, pred, loops);

    for (List<Integer> loop : loops) {
      boolean found = false;
      for (int i : loop) {
        if (n2e[i].size() >= 4) {
          found = true;
        }
      }
      if (!found) return true;
    }
    return false;
  }

  private static void dfs(int parent, int s, int i, int N, int M, List<Integer>[] n2e, int[] edges,
      int[] pred, List<List<Integer>> loops) {
    pred[i] = parent;
    for (int e : n2e[i]) {
      int to = edges[e] ^ i;
      if (to == parent) continue;
      if (to == s) {
        ArrayList<Integer> path = new ArrayList<>();
        int j = i;
        while (j != s) {
          path.add(j);
          j = pred[j];
        }
        loops.add(path);
        continue;
      }
      if (pred[to] < 0) dfs(i, s, to, N, M, n2e, edges, pred, loops);
    }
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.