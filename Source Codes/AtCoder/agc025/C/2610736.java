import java.util.Arrays;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    Interval[] li = new Interval[N];
    for (int i = 0; i < N; i++) {
      int l = Integer.parseInt(sc.next());
      int r = Integer.parseInt(sc.next());
      li[i] = new Interval(l, r);
    }
    Interval[] ri = li.clone();
    Arrays.sort(li, (i1, i2) -> Integer.compare(i2.l, i1.l));
    Arrays.sort(ri, (i1, i2) -> Integer.compare(i1.r, i2.r));
    long ans = solve(li, ri);
    for (int i = 0; i < N; i++) {
      ri[i].used = false;
    }
    ans = Math.max(ans, solve(ri, li));
    System.out.println(ans);
  }

  static long solve(Interval[] f, Interval[] s) {
    int fi = 0;
    int si = 0;
    int t = 0;
    int p = 0;
    long sum = 0;
    while (true) {
      while (f[fi].used) {
        ++fi;
      }
      f[fi].used = true;
      if (p < f[fi].l) {
        sum += f[fi].l - p;
        p = f[fi].l;
      } else if (f[fi].r < p) {
        sum += p - f[fi].r;
        p = f[fi].r;
      }
      ++t;
      if (t == f.length) break;

      while (s[si].used) {
        ++si;
      }
      s[si].used = true;
      if (p < s[si].l) {
        sum += s[si].l - p;
        p = s[si].l;
      } else if (s[si].r < p) {
        sum += p - s[si].r;
        p = s[si].r;
      }
      ++t;
      if (t == s.length) break;
    }
    sum += Math.abs(p);
    return sum;
  }


  static class Interval {
    int l, r;
    boolean used;

    Interval(int l, int r) {
      this.l = l;
      this.r = r;
    }
  }
}