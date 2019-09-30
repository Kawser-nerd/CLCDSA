
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(A.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(A.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new A().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        double[] x = new double[n];
        double sx = 0;
        for (int i = 0; i < n; i++) {
            x[i] = in.nextDouble();
            sx += x[i];
        }
        String res = "";
        for (int i = 0; i < n; i++) {
            double l = 0;
            double r = 1;
            while (r > l + 1e-15) {
                double m = (l + r) * .5;
                double z = x[i] + m * sx;
                double s = 0;
                for (int j = 0; j < n; j++) if (j != i) {
                    if (x[j] < z) {
                        double dx = z - x[j];
                        s += dx / sx;
                    }
                }
                if (s > 1 - m) {
                    r = m;
                } else {
                    l = m;
                }
            }
            res += (l * 100) + " ";
        }
        return res;
    }
}