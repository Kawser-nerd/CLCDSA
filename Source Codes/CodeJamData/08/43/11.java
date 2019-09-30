import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class C {

    static Scanner in;
    static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("input.txt"));
        out = new PrintWriter("output.txt");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new C().solve());
        }
        out.close();
    }

    private Object solve() {
        int n = in.nextInt();
        double[][] c = new double[3][n];
        double[] p = new double[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                c[j][i] = in.nextInt();
            }
            p[i] = in.nextInt();
        }

        double l = 0;
        double r = 1e100;
        while (r > l + 1e-9) {
            double m = (l + r) / 2;
            double[] q = new double[8];
            Arrays.fill(q, 1e100);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 8; j++) {
                    double qq = m * p[i];
                    for (int k = 0; k < 3; k++) {
                        if ((j & (1 << k)) > 0) {
                            qq += c[k][i];
                        } else {
                            qq -= c[k][i];
                        }
                    }
                    q[j] = Math.min(q[j], qq);
                }
            }
            boolean b = true;
            for (int i = 0; i < 8; i++) {
                if (q[i] < -q[i ^ 7]) b = false;
            }
            if (b) r = m; else l = m;
        }

        return "" + r;
    }
}
