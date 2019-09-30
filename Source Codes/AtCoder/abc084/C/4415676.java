import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] c = new int[n], s = new int[n], f = new int[n], ans = new int[n];
    for (int i = 0; i < n - 1; i++) {
      c[i] = sc.nextInt();
      s[i] = sc.nextInt();
      f[i] = sc.nextInt();
    }
    c[n - 1] = s[n - 1] = f[n - 1] = 0;
    for (int i = 0; i < n; i++) {
      ans[i] = s[i] + c[i];
      for (int j = i + 1; j < n - 1; j++) {
        ans[i] = Math.max(s[j], ((ans[i] + f[j] - 1) / f[j]) * f[j]);
        ans[i] += c[j];
      }
      System.out.println(ans[i]);
    }
  }
}