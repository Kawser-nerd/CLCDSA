import java.util.Scanner;

class Main {

  // data???????a????index???
  static int binarysearch(long[] a, long data) {
    int ok = 0;
    int ng = a.length;
    int mid = (ok + ng) / 2;
    while (ng - ok > 1) {
      if (a[mid] < data) {
        ok = mid;
      } else {
        ng = mid;
      }
      mid = (ok + ng) / 2;
    }
    return ok;
  }

  static long calc(long[] s, long[] t, long x) {
    long[] a, b;
    long[] ans = new long[8];
    int ans_idx = 0;
    for (int i = 0; i < 2; i++) {
      if (i == 0) {
        a = s;
        b = t;
      } else {
        a = t;
        b = s;
      }
      for (int j = 0; j < 2; j++) {
        int apor = binarysearch(a, x) + j;
        long ax = a[apor];
        for (int k = 0; k < 2; k++) {
          int bpor = binarysearch(b, ax) + k;
          long bx = b[bpor];
          ans[ans_idx++] = Math.abs(x - ax) + Math.abs(ax - bx);
        }
      }
    }
    long min = Long.MAX_VALUE;
    for (int i = 0; i < 8; i++) {
      if (min > ans[i]) {
        min = ans[i];
      }
    }
    return min;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int a = scanner.nextInt();
    int b = scanner.nextInt();
    int q = scanner.nextInt();
    long[] s = new long[a + 2];
    long[] t = new long[b + 2];
    long[] x = new long[q];
    s[0] = Long.MIN_VALUE / 4;
    for (int i = 1; i < a + 1; i++) {
      s[i] = scanner.nextLong();
    }
    s[a + 1] = Long.MAX_VALUE / 4;
    t[0] = Long.MIN_VALUE / 4;
    for (int i = 1; i < b + 1; i++) {
      t[i] = scanner.nextLong();
    }
    t[b + 1] = Long.MAX_VALUE / 4;
    for (int i = 0; i < q; i++) {
      x[i] = scanner.nextLong();
    }
    scanner.close();

    for (int i = 0; i < x.length; i++) {
      System.out.println(calc(s, t, x[i]));
    }
  }
}