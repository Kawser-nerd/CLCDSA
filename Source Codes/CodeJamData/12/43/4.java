
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int[] x = new int[n];
        for (int i = 0; i < n - 1; i++) {
            x[i] = in.nextInt() - 1;
        }
        int[] h = new int[n];
        double[] z = new double[n];
        int[] lb = new int[n];

        for (int i = n - 1; i >= 0; i--) {
            boolean first = true;
            int yy = 0;
            int pr = 0;
            double zz = z[i];
            for (int j = 0; j < i; j++) if (x[j] == i) {
                if (j < lb[i]) return "Impossible";
                if (first) {
                    first = false;
                    lb[j] = lb[i];
                } else {
                    lb[j] = pr;
                }
                yy = (int) Math.floor(h[i] - zz * (i - j) - 1e-5);
                h[j] = yy;
                z[j] = 1.0 * (h[i] - h[j]) / (i - j);
                zz = z[j];
                pr = j;
            }
        }

        int min = h[0];
        for (int i = 1; i < n; i++) {
            min = Math.min(min, h[i]);
        }
        for (int i = 0; i < n; i++) {
            h[i] -= min;
            if (h[i] > 1000000000) throw new RuntimeException();
        }

        for (int i = 0; i < n - 1; i++) {
            int k = i;
            double p = 0;
            for (int j = i + 1; j < n; j++) {
                double pp = 1.0 * (h[j] - h[i]) / (j - i);
                if (pp > p) {
                    p = pp;
                    k = j;
                }
            }
            if (k != x[i]) {
                System.out.println("BOTVA " + Arrays.toString(x) + " " + i + " " + k);
                break;
            }
        }

        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; i++) {
            res.append(h[i]).append(" ");
        }
        return res.toString();
    }
}