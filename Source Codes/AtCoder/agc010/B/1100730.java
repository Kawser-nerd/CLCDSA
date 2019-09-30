import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

  private void solve(Scanner in, PrintWriter out) {
    int N = in.nextInt();
    long[] a = new long[N];
    for (int i = 0; i < N; i++) {
      a[i] = in.nextInt();
    }

    long[] d = new long[N];
    for (int i = 0; i < N; i++) {
      d[i] = a[(i + 1) % N] - a[i];
    }

    long sum = Arrays.stream(a).sum();
    if (sum % ((long) N * ((long) N + 1) / 2) != 0) {
      out.println("NO");
      return;
    }

    long k = sum / ((long) N * ((long) N + 1) / 2);
    //1-N
    long count = 0;
    for (long e : d) {
      e -= k;

      if (e > 0 || (-e) % (long) N != 0) {
        out.println("NO");
        return;
      } else {
        count += (-e) / (long) N;
      }
    }
    if (count != k) {
      out.println("NO");
    } else {
      out.println("YES");
    }
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);
    new Main().solve(in, out);
    in.close();
    out.close();
  }
}