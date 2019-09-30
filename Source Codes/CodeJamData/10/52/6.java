import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
    public void solve() throws FileNotFoundException {
        Scanner in = new Scanner(new File("B-small-attempt0.in"));
        PrintWriter out = new PrintWriter("B-small-attempt0.out");

        int testN = in.nextInt();
        for (int test = 1; test <= testN; test++) {
            out.print("Case #" + test + ": ");

            long l = in.nextLong();
            int k = in.nextInt();

            int[] b = new int[k];
            for (int i = 0; i < k; i++) {
                b[i] = in.nextInt();
            }
            Arrays.sort(b);
            int z = b[b.length - 1];

            int[] a = new int[z * z];
            Arrays.fill(a, Integer.MAX_VALUE);
            a[0] = 0;
            for (int i = 0; i < b.length; i++) {
                for (int j = 0; j < a.length - b[i]; j++) {
                    if (a[j] != Integer.MAX_VALUE) {
                        a[j + b[i]] = Math.min(a[j + b[i]], a[j] + 1);
                    }
                }
            }

            long ans = Long.MAX_VALUE;
            for (int i = 0; i < b.length; i++) {
                long u = (l - z * z) / b[i] + 1;
                int r = (int) (l - u * b[i]);
                if (a[r] != Integer.MAX_VALUE) {
                    long v = u + a[r];
                    if (v < ans) {
                        ans = v;
                    }
                }
            }
            if (ans == Long.MAX_VALUE) {
                out.println("IMPOSSIBLE");
            } else {
                out.println(ans);
            }
        }

        in.close();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new B().solve();
    }
}