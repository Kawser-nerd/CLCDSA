import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class B {
    private final Scanner in;
    private final PrintWriter out;

    public B(Scanner in, PrintWriter out) {
        this.in = in;
        this.out = out;
    }

    public static void main(String[] args) {
        final String filename = "B-large";
        try (Scanner in = new Scanner(new FileReader(new File(filename + ".in")));
             PrintWriter out = new PrintWriter(filename + ".out")) {
            new B(in, out).solve();
        } catch (Throwable t) {
            t.printStackTrace();
            System.exit(-1);
        }
    }

    private void solve() {
        int tests = in.nextInt();
        for (int test = 1; test <= tests; ++test) {
            System.out.println(test);

            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }

            int ans = 0;
            int l = 0;
            int r = n - 1;
            for (int i = 0; i < n - 1; ++i) {
                int mi = l;
                for (int j = l + 1; j <= r; ++j) {
                    if (a[mi] > a[j]) {
                        mi = j;
                    }
                }

                if (mi - l < r - mi) {
                    ans += mi - l;
                    int m = a[mi];
                    for (int j = mi - 1; j >= l; --j) {
                        a[j + 1] = a[j];
                    }
                    a[l] = m;
                    ++l;
                } else {
                    ans += r - mi;
                    int m = a[mi];
                    for (int j = mi + 1; j <= r; ++j) {
                        a[j - 1] = a[j];
                    }
                    a[r] = m;
                    --r;
                }
            }

            System.out.println(Arrays.toString(a));

            out.print("Case #" + test + ": ");
            out.println(ans);
        }
    }
}
