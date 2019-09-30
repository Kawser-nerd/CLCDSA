import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int l = sc.nextInt();
    int p = sc.nextInt();
    int q = sc.nextInt();
    int r = sc.nextInt();
    int ans = 0;
    int n1 = (n / p) * (m / q) * (l / r);
    int n2 = (n / p) * (m / r) * (l / q);
    int n3 = (n / q) * (m / p) * (l / r);
    int n4 = (n / q) * (m / r) * (l / p);
    int n5 = (n / r) * (m / p) * (l / q);
    int n6 = (n / r) * (m / q) * (l / p);
    ans = Math.max(ans, n1);
    ans = Math.max(ans, n2);
    ans = Math.max(ans, n3);
    ans = Math.max(ans, n4);
    ans = Math.max(ans, n5);
    ans = Math.max(ans, n6);
    System.out.println(ans);
  }
}