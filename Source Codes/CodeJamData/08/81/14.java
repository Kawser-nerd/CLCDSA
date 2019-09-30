import java.io.*;
import java.util.StringTokenizer;
import java.util.Locale;

/**
 * @author Ivan Romanov
 */
public class A {
    private static final String PROBLEM = "A";

    private static final double EPS = 1e-7;

    private static final String SIZE = "large";
    //private static final String SIZE = "small";
    //private static final String SIZE = "small-attempt0";

    private String solve() throws IOException {
        double[] x = new double[6];
        double[] y = new double[6];
        for (int i = 0; i < x.length; i++) {
            x[i] = nextDouble();
            y[i] = nextDouble();
        }

        double[] dummy = solve(new double[]{1, 3, 5}, new double[]{2, 1, -1}, new double[]{9, 9, 7});

        double[] z = new double[]{x[3], x[4], x[5]};
        double[] a = solve(x, y, z);

        z = new double[]{y[3], y[4], y[5]};
        double[] b = solve(x, y, z);

        double[] ans = solve(a[0] - 1, a[1], -a[2], b[0], b[1] - 1, -b[2]);

        return String.format("%.6f %.6f", ans[0], ans[1]);
    }

    private double[] solve(double[] x, double[] y, double[] z) {
        return solve(x, y, new double[]{1, 1, 1}, z);
    }

    private double[] solve(double[] x, double[] y, double[] z, double[] t) {
        double  d = det(new double[]{x[0], y[0], z[0]}, new double[]{x[1], y[1], z[1]}, new double[]{x[2], y[2], z[2]});
        double d1 = det(new double[]{t[0], y[0], z[0]}, new double[]{t[1], y[1], z[1]}, new double[]{t[2], y[2], z[2]});
        double d2 = det(new double[]{x[0], t[0], z[0]}, new double[]{x[1], t[1], z[1]}, new double[]{x[2], t[2], z[2]});
        double d3 = det(new double[]{x[0], y[0], t[0]}, new double[]{x[1], y[1], t[1]}, new double[]{x[2], y[2], t[2]});

        double[] a = new double[] {d1 / d, d2 / d, d3 / d};
        return a;
    }

    private double det(double[] a, double[] b, double[] c) {
        return  a[0] * (b[1] * c[2] - b[2] * c[1])
              - a[1] * (b[0] * c[2] - b[2] * c[0])
              + a[2] * (b[0] * c[1] - b[1] * c[0]);
    }

    private double[] solve(double a, double b, double c, double d) {
        if (Math.abs(a * d - b * c) < EPS) {
            return null;
        } else {
            return solve(a, b, 0, c, d, 0);
        }
    }

    private double[] solve(double x0, double y0, double x3, double x1, double y1, double x4) {
        double d =  x0 * y1 - x1 * y0;
        double d1 = x3 * y1 - x4 * y0;
        double d2 = x0 * x4 - x1 * x3;
        return new double[] {d1 / d, d2 / d};
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

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private void run() throws IOException {
        Locale.setDefault(Locale.UK);
        reader = new BufferedReader(new FileReader(PROBLEM + "-" + SIZE + ".in"));
        PrintWriter writer = new PrintWriter(new File(PROBLEM + "-" + SIZE + ".out"));
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
            new A().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}