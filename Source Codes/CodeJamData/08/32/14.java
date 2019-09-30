
import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;

/**
 * Created by IntelliJ IDEA.
 * User: Fedor
 * Date: Jul 27, 2008
 * Time: 1:18:55 PM
 * To change this template use File | Settings | File Templates.
 */
public class Ugly {


    static int[] x;
    static int n;
    static long result;

    static long sign(long x) {
        return x < 0 ? -1 : 1;
    }

    static void dfs(int k, long value, long last) {
        if (k >= n) {
            value += last;
            if (value % 2 == 0 || value % 3 == 0 || value % 5 == 0 || value % 7 == 0) {
                result++;
            }
        } else {

            dfs(k+1, value, sign(last) * (Math.abs(last)*10L + x[k]));
            dfs(k+1, value + last, x[k]);
            dfs(k+1, value + last, -x[k]);

        }

    }

    static int mod(int val) {
        int result = val % 210;
        if (result < 0) result += 210;
        return result;
    }

    public static void main(String[] args) throws Exception {
//n, A, B, C, D, x0, y0 and M

        Scanner in = new Scanner(new File("B-large.in.txt"));
        PrintWriter out = new PrintWriter("ugly.out");

        int tests = in.nextInt();
        in.nextLine();

        for (int t = 1; t <= tests; t++) {
            result = 0;

            String s = in.nextLine();
            n = s.length();
            x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = s.charAt(i) - '0';
            }

//            dfs(1, 0, x[0]);
            int[][] w = new int[n+1][n+1];
            for (int i = 0; i <= n; i++) {
                for (int j = i+1; j <= n; j++) {
                    for (int k = i; k < j; k++) {
                        w[i][j] = mod(w[i][j]*10 + x[k]);
                    }
                }
            }

            long[][] d = new long[n+1][210];

            d[0][0] = 1;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 210; j++) {
                    for (int k = i+1; k <= n; k++) {
                        {
                            int r = mod(j + w[i][k]);
                            d[k][r] += d[i][j];
                        }
                        if (i > 0) {
                            int r = mod(j - w[i][k]);
                            d[k][r] += d[i][j];
                        }
                    }
//                    if (d[i][j] > 0) {
//                        System.out.println("d[" + i + "][" + j + "] = " + d[i][j]);
//                    }
                }
            }



            result = 0;
            for (int i = 0; i < 210; i++) {
                if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
                    result += d[n][i];
                }
//                if (d[n][i] > 0) {
//                    System.out.println("d[" + n + "][" + i + "] = " + d[n][i]);
//                }
            }


            out.println("Case #" + t + ": " + result);


        }


        in.close();
        out.close();


    }


}
