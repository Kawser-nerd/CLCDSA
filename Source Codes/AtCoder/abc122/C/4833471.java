import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CGeTAC solver = new CGeTAC();
        solver.solve(1, in, out);
        out.close();
    }

    static class CGeTAC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            String s = in.next();

            int p[] = new int[n];
            char a[] = s.toCharArray();
            if (a[0] == 'A' && a[1] == 'C') p[0] = 1;
            for (int i = 1; i < n - 1; i++) {
                if (a[i] == 'A' && a[i + 1] == 'C') {
                    p[i] = p[i - 1] + 1;
                } else {
                    p[i] = p[i - 1];
                }
            }
            p[n - 1] = p[n - 2];
            int ans = 0;
            for (int i = 0; i < q; i++) {
                int l = in.nextInt();
                int r = in.nextInt();
                l--;
                r--;
                if (l == 0) {
                    ans = p[r - 1];
                } else {
                    ans = p[r - 1] - p[l - 1];
                }
                out.println(ans);
            }
        }

    }
}