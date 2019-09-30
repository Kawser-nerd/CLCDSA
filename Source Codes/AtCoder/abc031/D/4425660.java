import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int K = scanner.nextInt();
    int N = scanner.nextInt();
    String[] v = new String[N];
    String[] w = new String[N];
    for (int i = 0; i < N; i++) {
      v[i] = scanner.next();
      w[i] = scanner.next();
    }

    String[] map = new String[K + 1];
    dfs(map, N, v, w, new int[]{0, 0, 0});
    for (int i = 1; i <= K; i++) {
      System.out.println(map[i]);
    }
  }

  private static boolean dfs(String[] map, int N, String[] v, String[] w, int[] pos) {
    int i = pos[0];
    int j = pos[1];
    int k = pos[2];
    if (i == N) return j == 0 && k == 0;
    if (j == v[i].length() && k == w[i].length()) return dfs(map, N, v, w, new int[]{i + 1, 0, 0});
    if (j >= v[i].length() || k >= w[i].length()) return false;

    while (j < v[i].length() && k < w[i].length()) {
      int num = v[i].charAt(j) - '0';
      if (map[num] != null) {
        j++;
        k += map[num].length();
      } else {
        break;
      }
    }

    if (j == v[i].length() && k == w[i].length()) return dfs(map, N, v, w, new int[]{i + 1, 0, 0});
    if (j >= v[i].length() || k >= w[i].length()) return false;

    for (int l = 1; l <= 3 && k + l <= w[i].length(); l++) {
      int num = v[i].charAt(j) - '0';
      String str = w[i].substring(k, k + l);

      map[num] = str;
      if (dfs(map, N, v, w, new int[]{i, j + 1, k + l})) {
        return true;
      }
      map[num] = null;
    }
    return false;
  }
}