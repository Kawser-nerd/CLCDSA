
import java.util.*;
import java.io.File;
import java.io.PrintWriter;

/**
 * Created by IntelliJ IDEA.
 * User: Fedor
 * Date: Jul 27, 2008
 * Time: 2:26:28 PM
 * To change this template use File | Settings | File Templates.
 */
public class Speed {
    private static final int MOD = 1000000007;


    public static void main(String[] args) throws Exception {
//n, A, B, C, D, x0, y0 and M

        Scanner in = new Scanner(new File("C-small-attempt1.in.txt"));
        PrintWriter out = new PrintWriter("speed.out");

        int tests = in.nextInt();

        for (int t = 1; t <= tests; t++) {
            long result = 0;

            // n, m, X, Y and Z
            int n = in.nextInt();
            int m = in.nextInt();
            long X = in.nextInt();
            long Y = in.nextInt();
            long Z = in.nextInt();

            int[] a = new int[m];
            int[] x = new int[n];
            long[] d = new long[n];
            for (int i = 0; i < m; i++) {
                a[i] = in.nextInt();
            }

            for (int i = 0; i < n; i++) {
                x[i] = a[i % m];
                a[i % m] = (int)((X * a[i % m] + Y * (i + 1)) % Z);
            }

            for (int i = 0; i < n; i++) {

                d[i] = 1;

                for (int j = i-1; j >= 0; j--) {
                    if (x[j] < x[i]) {
                        d[i] = (d[i] + d[j]) % MOD;
                    }
                }
//
//                if (k == -1) {
//                    d[i] = 1;
//                } else {
//                    d[i] = 1 + d[k];
//                    for (int j = i-1; j > k; j--) {
//                        if (x[j] < x[i]) {
//                            d[i] += d[j];
//                        }
//                    }
//                }

                result = (result + d[i]) % MOD;

            }


            out.println("Case #" + t + ": " + result);


        }


        in.close();
        out.close();


    }


}
