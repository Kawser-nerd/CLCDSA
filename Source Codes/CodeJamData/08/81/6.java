import java.io.IOException;
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Locale;

public class A implements Runnable {

    double det2(double a1, double a2, double b1, double b2) {
        return a1 * b2 - a2 * b1;
    }

    double det3(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3) {
        return
                a1 * det2(b2, b3, c2, c3) +
                a2 * det2(b3, b1, c3, c1) +
                a3 * det2(b1, b2, c1, c2);
    }

    double[] tri(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y) {
        double[] r = new double[3];
        double d = det3(x1, x2, x3, y1, y2, y3, 1, 1, 1);
        r[0] = det3(x, x2, x3, y, y2, y3, 1, 1, 1) / d;
        r[1] = det3(x1, x, x3, y1, y, y3, 1, 1, 1) / d;
        r[2] = det3(x1, x2, x, y1, y2, y, 1, 1, 1) / d;
        return r;
    }

    void apply(double[] x, double[] y, double[][] m, double[] nx, double[] ny) {
        for (int i = 0; i < 3; i++) {
            nx[i] = 0;
            ny[i] = 0;
            for (int j = 0; j < 3; j++) {
                nx[i] += x[j] * m[i][j];
                ny[i] += y[j] * m[i][j];
            }
        }
    }

    public void solve() throws IOException {
        Locale.setDefault(Locale.US);
        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new File("A-large.out"));

        int tn = in.nextInt();
        for (int test = 1; test <= tn; test++) {
            double[] x = new double[3];
            double[] y = new double[3];
            for (int i = 0; i < 3; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }
            double[] nx = new double[3];
            double[] ny = new double[3];
            for (int i = 0; i < 3; i++) {
                nx[i] = in.nextInt();
                ny[i] = in.nextInt();
            }
            double[][] mt = new double[3][];
            for (int i = 0; i < 3; i++) {
                mt[i] = tri(x[0], y[0], x[1], y[1], x[2], y[2], nx[i], ny[i]);
            }
            for (int i = 0; i < 10000000; i++) {
                x = nx;
                y = ny;
                nx = new double[3];
                ny = new double[3];
                apply(x, y, mt, nx, ny);
            }

            System.out.println(nx[0] + " " + ny[0] + "  " + nx[1] + " " + ny[1] + "  " + nx[2] + " " + ny[2]);
            out.printf("Case #%d: %.10f %.10f\n", test, nx[0], ny[0]);
        }

        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Thread(new A()).start();
    }
}
