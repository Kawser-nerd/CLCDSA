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
        DStaticSushi solver = new DStaticSushi();
        solver.solve(1, in, out);
        out.close();
    }

    static class DStaticSushi {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            /* INPUT BEGIN */
            int n = in.nextInt();
            long c = in.nextLong();
            long[] x = new long[n];
            long[] v = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = in.nextLong();
                v[i] = in.nextLong();
            }
            /* INPUT END */

            /* PREPROCESS BEGIN */
            long c2 = c * 2;
            long[] r = new long[n + 1];//CALORIE INCOME(R)
            long[] mrd = new long[n + 1];//MAX  CALORIE(R)
            long[] mrd2 = new long[n + 1];//MAX CALORIE(R, CONSUMPTION DOUBLED)
            long[] l = new long[n + 1];//CALORIE INCOME(L)
            long[] mld = new long[n + 1];//MAX  CALORIE(L)
            long[] mld2 = new long[n + 1];//MAX CALORIE(L, CONSUMPTION DOUBLED)
            for (int i = 1; i <= n; i++) {//LETS CALC:3
                r[i] = r[i - 1] + v[i - 1];
                mrd[i] = Math.max(mrd[i - 1], r[i] - x[i - 1]);
                mrd2[i] = Math.max(mrd2[i - 1], r[i] - (x[i - 1] << 1));
                l[i] = l[i - 1] + v[n - i];
                mld[i] = Math.max(mld[i], l[i] - c + x[n - i]);
                mld2[i] = Math.max(mld2[i], l[i] - c2 + (x[n - i] << 1));
            }
            /* PREPROCESS END */

            /* DEBUG CODE START */
            //System.out.println(Arrays.toString(r));
            //System.out.println(Arrays.toString(mrd));
            //System.out.println(Arrays.toString(mrd2));
            //System.out.println(Arrays.toString(l));
            //System.out.println(Arrays.toString(mld));
            //System.out.println(Arrays.toString(mld2));
            /* DEBUG CODE END */

            long ans = 0;
            /* WE WANT TO MAXIMIZE mrd[i] + mld[n - i] */
            for (int i = 0; i <= n; i++) {
                ans = Math.max(ans, mrd[i] + mld2[n - i]);
                ans = Math.max(ans, mrd2[i] + mld[n - i]);
            }
            out.println(ans);/* OUTPUT */
        }

    }
}