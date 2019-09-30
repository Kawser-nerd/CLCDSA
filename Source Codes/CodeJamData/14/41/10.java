import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class A {
    private final Scanner in;
    private final PrintWriter out;

    public A(Scanner in, PrintWriter out) {
        this.in = in;
        this.out = out;
    }

    public static void main(String[] args) {
        final String filename = "A-large";
        try (Scanner in = new Scanner(new FileReader(new File(filename + ".in")));
             PrintWriter out = new PrintWriter(filename + ".out")) {
            new A(in, out).solve();
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
            int X = in.nextInt();

            int[] s = new int[n];
            for (int i = 0; i < n; ++i) {
                s[i] = in.nextInt();
            }

            Arrays.sort(s);

            int ans = 0;
            int i = 0;
            for (int j = s.length - 1; j >= i; --j) {
                ++ans;
                if (i < j && s[j] + s[i] <= X) {
                    ++i;
                }
            }

            out.print("Case #" + test + ": ");
            out.println(ans);
        }
    }
}
