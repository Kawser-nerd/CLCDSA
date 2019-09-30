import java.io.*;
import java.util.StringTokenizer;
import java.util.Locale;
import static java.lang.Math.*;

/**
 * @author Ivan Romanov
 */
public class C {

    double[] x;
    double[] y;
    double[] z;
    double[] p;

    int n;
    private static final int ITER = 50;

    private String solve() throws IOException {
        n = nextInt();
        x = new double[n];
        y = new double[n];
        z = new double[n];
        p = new double[n];
        for (int i = 0; i < n; i++) {
            x[i] = nextInt();
            y[i] = nextInt();
            z[i] = nextInt();
            p[i] = nextInt();
        }
        if (n == 1) {
            return "0.000000";
        }
        double ans = Double.POSITIVE_INFINITY;

        double minX = -1e6;
        double maxX =  1e6;
        for (int i = 0; i < ITER; i++) {
            double widX  = (maxX - minX) * 0.45;
            double x1 = minX + widX;
            double x2 = maxX - widX;
            if (f(x1) > f(x2)) {
                minX = x1;
            } else {
                maxX = x2;
            }
        }
        ans = f((minX + maxX) * 0.5);


//        int m = (n * (n - 1)) / 2 + n;
//
//        double[] dx = new double[m];
//        double[] dy = new double[m];
//        double[] dz = new double[m];
//
//        int cnt = 0;
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {
//                dx[cnt] = (x[i] * p[j] + x[j] * p[i]) / (p[i] + p[j]);
//                dy[cnt] = (y[i] * p[j] + y[j] * p[i]) / (p[i] + p[j]);
//                dz[cnt] = (z[i] * p[j] + z[j] * p[i]) / (p[i] + p[j]);
//                cnt++;
//            }
//        }
//        for (int i = 0; i < n; i++) {
//            dx[cnt] = x[i];
//            dy[cnt] = y[i];
//            dz[cnt] = z[i];
//            cnt++;
//        }
//        if (cnt != m) {
//            throw null;
//        }
//
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < m; j++) {
//                for (int k = 0; k < m; k++) {
//                    ans = min(ans, calcF(dx[i], dy[j], dz[k]));
//                }
//            }
//        }
        return String.format("%6f", ans);
    }

    private double f(double x) {
        double minX = -1e6;
        double maxX =  1e6;
        for (int i = 0; i < ITER; i++) {
            double widX  = (maxX - minX) * 0.45;
            double x1 = minX + widX;
            double x2 = maxX - widX;
            if (f(x, x1) > f(x, x2)) {
                minX = x1;
            } else {
                maxX = x2;
            }
        }
        return f(x, (minX + maxX) * 0.5);
    }

    private double f(double x, double y) {
        double minX = -1e6;
        double maxX =  1e6;
        for (int i = 0; i < ITER; i++) {
            double widX  = (maxX - minX) * 0.45;
            double x1 = minX + widX;
            double x2 = maxX - widX;
            if (f(x, y, x1) > f(x, y, x2)) {
                minX = x1;
            } else {
                maxX = x2;
            }
        }
        return f(x, y, (minX + maxX) * 0.5);
    }

    private double f(double x, double y, double z) {
        return calcF(x, y, z);
    }

    private double calcF(double xx, double yy, double zz) {
        double f = 0.0;
        for (int q = 0; q < n; q++) {
            f = max(f, (abs(xx - x[q]) + abs(yy - y[q]) + abs(zz - z[q])) / p[q]);
        }
        return f;
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
        Locale.setDefault(Locale.UK);
        reader = new BufferedReader(new FileReader("C-small.in"));
        PrintWriter writer = new PrintWriter(new File("C-small.out"));
        try {
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                writer.print("Case #" + (i + 1) + ": ");
                writer.print(solve());
                writer.println();
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new C().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}