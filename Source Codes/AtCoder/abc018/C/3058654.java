import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int r = in.nextInt(), c = in.nextInt(), k = in.nextInt() - 1;
            int[][] s = new int[c + 1][r];
            for (int i = 0; i < r; i++) {
                String l = in.next();
                for (int j = 0; j < c; j++) {
                    s[j + 1][i] = s[j][i] + (l.charAt(j) == 'o' ? 1 : 0);
                }
            }

            // System.out.println(Arrays.deepToString(s));
            int ans = 0;
            for (int i = k; i < r - k; i++) {
                mid:
                for (int j = k + 1; j <= c - k; j++) {
                    // System.out.println(i+","+j);
                    for (int l = -k; l <= k; l++) {
                        int d = k - Math.abs(l);
                        if (s[j + d][i + l] - s[j - d - 1][i + l] != 2 * d + 1) {
                            continue mid;
                        }
                    }
                    ans++;
                }
            }
            out.println(ans);
        }

    }
}