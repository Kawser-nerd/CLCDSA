import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static final long MOD = 1_000_000_007;

  public static void main(String[] args) {
    int N = sc.nextInt();
    int X = sc.nextInt();
    int Y = sc.nextInt();
    ArrayList<ArrayList<Integer>> list = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      list.add(new ArrayList<>());
    }
    for (int i = 0; i < N; i++) {
      int C = Integer.parseInt(sc.next()) - 1;
      int W = Integer.parseInt(sc.next());
      list.get(C).add(W);
    }
    int[] min = new int[N];
    int m = 2_000_000_000;
    for (int i = 0; i < N; i++) {
      if (list.get(i).isEmpty()) continue;
      Collections.sort(list.get(i));
      min[i] = m;
      m = Math.min(m, list.get(i).get(0));
    }
    m = 2_000_000_000;
    for (int i = N - 1; i >= 0; i--) {
      if (list.get(i).isEmpty()) continue;
      min[i] = Math.min(min[i], m);
      m = Math.min(m, list.get(i).get(0));
    }
    ArrayList<Integer> count = new ArrayList<Integer>();
    int sum = 0;
    for (int i = 0; i < N; i++) {
      if (list.get(i).isEmpty()) continue;
      if (list.get(i).get(0) + min[i] > Y) continue;
      int c = 0;
      for (int j = 0; j < list.get(i).size(); j++) {
        if (list.get(i).get(j) + min[i] > Y && list.get(i).get(j) + list.get(i).get(0) > X) break;
        ++c;
      }
      count.add(c);
      sum += c;
    }
    long ans = 1;
    for (int i = 1; i <= sum; i++) {
      ans *= i;
      ans %= MOD;
    }
    for (int c : count) {
      for (int i = 2; i <= c; i++) {
        ans *= inv(i);
        ans %= MOD;
      }
    }

    System.out.println(ans);
  }

  static long inv(long v) {
    return pow(v, (int) MOD - 2);
  }

  static long pow(long b, int p) {
    if (p == 0) return 1;
    if (p == 1) return b;
    long ret = pow(b, p / 2);
    ret *= ret;
    ret %= MOD;
    if (p % 2 == 1) {
      ret *= b;
      ret %= MOD;
    }
    return ret;
  }

}