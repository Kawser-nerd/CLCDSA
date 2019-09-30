import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
    public void solve() throws FileNotFoundException {
        Scanner in = new Scanner(new File("B-large.in"));
        PrintWriter out = new PrintWriter("B-large.out");

        int testN = in.nextInt();
        for (int test = 1; test <= testN; test++) {
            out.print("Case #" + test + ": ");

            int n = in.nextInt();
            int k = in.nextInt();
            long b = in.nextInt();
            long t = in.nextInt();
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = in.nextLong();
            }
            long[] v = new long[n];
            for (int i = 0; i < n; i++) {
                v[i] = in.nextLong();
            }

            int can = 0;
            long[] r = new long[n];
            for (int i = 0; i < n; i++) {
                r[i] = (b - x[i] + v[i] - 1) / v[i];
                if (r[i] <= t) {
                    can++;
                }
            }

            if (can < k) {
                out.println("IMPOSSIBLE");
                continue;
            }


            int[] needPass = new int[n];
            for (int i = 0; i < n; i++) {
                if (r[i] <= t) {
                    for (int j = 0; j < n; j++) {
                        if (r[j] > t && x[j] > x[i]) {
                            needPass[i]++;
                        }
                    }
                } else {
                    needPass[i] = Integer.MAX_VALUE;
                }
            }

            Arrays.sort(needPass);
            int res = 0;
            for (int i = 0; i < k; i++) {
                res += needPass[i];
            }
            out.println(res);
        }

        in.close();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new B().solve();
    }
}