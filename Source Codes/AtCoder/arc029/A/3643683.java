import java.util.*;

public class Main {
  public static int N;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    String t = "";
    for (int i = 0; i < N; i++) {
      int tmp = sc.nextInt();
      t += Integer.toString(tmp);
      if (i != N - 1) {
        t += ":";
      }
    }
    String p1 = "0";
    String p2 = "0";
    System.out.println(dfs(0, t, p1, p2));
  }

  public static int dfs(int depth, String t, String p1, String p2) {
    if (depth == N) {
      int sum1 = 0;
      int sum2 = 0;
      String[] p1_ary = p1.split(":");
      String[] p2_ary = p2.split(":");
      for (int i = 0; i < p1_ary.length; i++) {
        sum1 += Integer.parseInt(p1_ary[i]);
      }
      for (int i = 0; i < p2_ary.length; i++) {
        sum2 += Integer.parseInt(p2_ary[i]);
      }
      return Math.max(sum1, sum2);
    }
    String[] t_ary = t.split(":");
    String add = t_ary[0];
    String t_new = "";
    for (int i = 1; i < t_ary.length; i++) {
      t_new += t_ary[i];
      if (i != t_ary.length - 1) {
        t_new += ":";
      }
    }
    return Math.min(dfs(depth + 1, t_new, p1 + ":" + add, p2), dfs(depth + 1, t_new, p1, p2 + ":" + add));
  }
}