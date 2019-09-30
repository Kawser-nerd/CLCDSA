import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class D {

    static Scanner in;
    static PrintWriter out;
    private static final int MOD = 30031;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("d.in"));     
        out = new PrintWriter("d.out");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new D().solve());
            System.out.println("Test " + (i + 1) + " of " + n);
        }
        out.close();
    }

    private Object solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        int p = in.nextInt();
        
        int[] u = new int[1 << p];
        Arrays.fill(u, -1);
        int[] w = new int[1 << p];
        int c = 0;
        
        for (int m = 0; m < (1 << p); m++) {
            int q = 0;
            for (int i = 0; i < p; i++) if ((m & (1 << i)) > 0) q++;
            if (q == k) {
                u[m] = c;
                w[c] = m;
                c++;
            }
        }
        
        int[][] a = new int[c][c];
        for (int i = 0; i < c; i++) {
            int q = w[i];
            if ((q & 1) > 0) {
                int qq = (q >> 1) + (1 << (p - 1));
                a[i][u[qq]] = 1;
            } else {
                for (int j = 0; j < p; j++) {
                    if ((q & (1 << j)) > 0) {
                        int qq = (q >> 1) - (1 << (j - 1)) + (1 << (p - 1));
                        a[i][u[qq]] = 1;
                    }
                }
            }
        }
        
        int pow = (n - k);
        int[][] b = new int[c][c];
        for (int i = 0; i < c; i++) b[i][i] = 1;
        
        while (pow > 0) {
            if (pow % 2 == 0) {
                int[][] aa = new int[c][c];
                mult(a, a, aa);
                a = aa;
                pow /= 2;                        
            } else {
                int[][] bb = new int[c][c];
                mult(b, a, bb);
                b = bb;
                pow -= 1;
            }
        }

        int q = (1 << p) - (1 << (p - k));

        return b[u[q]][u[q]];
    }

    private void mult(int[][] a, int[][] b, int[][] c) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a.length; j++) {
                for (int k = 0; k < a.length; k++) {
                    c[i][k] += a[i][j] * b[j][k];
                    c[i][k] %= MOD;
                }
            }
        }
        //To change body of created methods use File | Settings | File Templates.
    }
}
