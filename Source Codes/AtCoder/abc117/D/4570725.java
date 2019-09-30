import java.util.Scanner;

class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    long k = scanner.nextLong();
    long[] a = new long[n];
    for (int i = 0; i < n; i++) {
      a[i] = scanner.nextLong();
    }
    scanner.close();
    int count = 0;
    for (; ((long) 1 << (count + 1)) <= k; count++)
      ;
    long x = 0;
    for (; count >= 0; count--) {
      long tmp = x + ((long) 1 << count);
      if (tmp > k)
        continue;
      long t = 0;
      long u = 0;
      for (long l : a) {
        t += l ^ tmp;
        u += l ^ x;
      }
      if (t >= u) {
        x = tmp;
      }
    }
    long ans = 0;
    for (long l : a) {
      ans += l ^ x;
    }
    System.out.println(ans);

  }

}