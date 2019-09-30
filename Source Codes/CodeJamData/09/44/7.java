import java.util.*;
import java.io.*;

class D implements Runnable {
    BufferedReader in;
    StringTokenizer st;

    int nextInt() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }

    class Point {
        double x;
        double y;

        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return x + " " + y;
        }
    }

    public void solve() throws IOException {
        in = new BufferedReader(new FileReader("D-large.in"));
        PrintWriter out = new PrintWriter(new File("D-large.out"));

        int testn = nextInt();
        for (int test = 0; test < testn; test++) {
            int n = nextInt();
            int[] x = new int[n];
            int[] y = new int[n];
            int[] r = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
                y[i] = nextInt();
                r[i] = nextInt();
            }

            double[][] d = new double[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] = Math.hypot(x[i] - x[j], y[i] - y[j]);
                }
            }

            double L = 0;
            double R = 10000;

            search:
            for (int iter = 0; iter < 100; iter++) {
                double M = (L + R) / 2;
                for (int i = 0; i < n; i++) {
                    if (M < r[i]) {
                        L = M;
                        continue search;
                    }
                }

                ArrayList<Point> points = new ArrayList<Point>();
                for (int i = 0; i < n; i++) {
                    points.add(new Point(x[i], y[i]));
                }

                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        double R1 = M - r[i];
                        double R2 = M - r[j];

                        if (R1 + R2 < d[i][j]) {
                            continue;
                        }
                        if (Math.abs(R1 - R2) > d[i][j]) {
                            continue;
                        }

                        double A = 2 * (x[j] - x[i]);
                        double B = 2 * (y[j] - y[i]);
                        double C = x[i] * x[i] - x[j] * x[j] + y[i] * y[i] - y[j] * y[j] + R2 * R2 - R1 * R1;
                        double D = A * A + B * B;
                        double px = -A * C / D;
                        double py = -B * C / D;
                        double lx = -B;
                        double ly = A;

                        double a = lx * lx + ly * ly;
                        double b = 2 * lx * (px - x[i]) + 2 * ly * (py - y[i]);
                        double c = (px - x[i]) * (px - x[i]) + (py - y[i]) * (py - y[i]) - R1 * R1;
                        double disc = Math.sqrt(b * b - 4 * a * c);

                        double t1 = (-b - disc) / (2 * a);
                        double t2 = (-b + disc) / (2 * a);
                        Point p1, p2;

                        points.add(p1 = new Point(px + lx * t1, py + ly * t1));
                        points.add(p2 = new Point(px + lx * t2, py + ly * t2));

                    }
                }

                int m = points.size();
                boolean found = false;
                look:
                for (int i = 0; i < m; i++) {
                    for (int j = i; j < m; j++) {
                        Point p = points.get(i);
                        Point q = points.get(j);

                        boolean ok = true;
                        for (int k = 0; k < n; k++) {
                            if (
                                    ((M - r[k]) * (M - r[k])) < (x[k] - p.x) * (x[k] - p.x) + (y[k] - p.y) * (y[k] - p.y) - 1e-6 &&
                                    ((M - r[k]) * (M - r[k])) < (x[k] - q.x) * (x[k] - q.x) + (y[k] - q.y) * (y[k] - q.y) - 1e-6
                            ) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok) {
                            found = true;
                            break look;
                        }
                    }
                }

                if (found) {
                    R = M;
                } else {
                    L = M;
                }
            }


            System.out.println("Case #" + (test + 1) + ": " + L);
            out.println("Case #" + (test + 1) + ": " + L);
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
            throw new AssertionError();
        }
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new Thread(new D()).start();
    }
}