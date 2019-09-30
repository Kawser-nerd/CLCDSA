import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class D implements Runnable {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;
    String filename = D.class.getName().substring(0, 1);

    void preSolve() {

    }

    void solve(int testNumber) throws IOException {
        int n = nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        int[] r = new int[n];
        int maxR = 0;
        for (int i = 0; i < n; ++i) {
            x[i] = nextInt();
            y[i] = nextInt();
            r[i] = nextInt();
            maxR = Math.max(maxR, r[i]);
        }

        double left = maxR, right = 3000;

        System.out.println("[" + left + "; " + right + "]");

        for (int t = 0; t < 100; ++t) {
            double mid = (left + right) / 2;

            List<Double> cx = new ArrayList<Double>();
            List<Double> cy = new ArrayList<Double>();
            Set<Long> mask = new HashSet<Long>();

            for (int i = 0; i < n; ++i) {
                cx.add((double)x[i]);
                cy.add((double)y[i]);
            }

            for (int c1 = 0; c1 < n; ++c1) {
                for (int c2 = 0; c2 < c1; ++c2) {
                    double x1 = x[c1];
                    double y1 = y[c1];
                    double d1 = mid - r[c1];

                    double x2 = x[c2];
                    double y2 = y[c2];
                    double d2 = mid - r[c2];

                    double q2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

                    if (Math.abs(q2) < 1e-9) {
                        continue;
                    }

                    double underRoot1 = (d1 * d1 + d2 * d2 + q2) * (d1 * d1 + d2 * d2 + q2);
                    double underRoot2 = (d1 * d1) * (d1 * d1) + (d2 * d2) * (d2 * d2) + q2 * q2;
                    double u = (d1 * d1 + q2 - d2 * d2) / (2 * q2);
                    double v = Math.sqrt(underRoot1 - 2 * underRoot2) / (2 * q2);

                    if (Double.isNaN(v)) {
                        continue;
                    }

                    double rx1 = x1 + (x2 - x1) * u + (y2 - y1) * v;
                    double ry1 = y1 + (y2 - y1) * u - (x2 - x1) * v;
                    double rx2 = x1 + (x2 - x1) * u - (y2 - y1) * v;
                    double ry2 = y1 + (y2 - y1) * u + (x2 - x1) * v;

                    if (Math.abs((rx1 - x1) * (rx1 - x1) + (ry1 - y1) * (ry1 - y1) - d1 * d1) > 1e-6) {
                        throw new AssertionError();
                    }
                    if (Math.abs((rx1 - x2) * (rx1 - x2) + (ry1 - y2) * (ry1 - y2) - d2 * d2) > 1e-6) {
                        throw new AssertionError();
                    }
                    if (Math.abs((rx2 - x1) * (rx2 - x1) + (ry2 - y1) * (ry2 - y1) - d1 * d1) > 1e-6) {
                        throw new AssertionError();
                    }
                    if (Math.abs((rx2 - x2) * (rx2 - x2) + (ry2 - y2) * (ry2 - y2) - d2 * d2) > 1e-6) {
                        throw new AssertionError();
                    }

                    cx.add(rx1);
                    cy.add(ry1);
                    cx.add(rx2);
                    cy.add(ry2);
                }
            }

            for (int i = 0; i < cx.size(); ++i) {
                double xx = cx.get(i);
                double yy = cy.get(i);
                long mm = 0;
                for (int j = 0; j < n; ++j) {
                    if ((xx - x[j]) * (xx - x[j]) + (yy - y[j]) * (yy - y[j]) <= (mid - r[j]) * (mid - r[j]) + 1e-7) {
                        mm |= 1L << j;
                    }
                }
                mask.add(mm);
            }

            boolean can = false;
            long all = (1L << n) - 1;
            for (long m : mask) {
                for (long m2 : mask) {
                    if ((m | m2) == all) {
                        can = true;
                        break;
                    }
                }
            }

            if (can) {
                right = mid;
            } else {
                left = mid;
            }
        }
        out.println("Case #" + testNumber + ": " + (left + right) / 2);
    }

    public void run() {
        try {
            in = new BufferedReader(new FileReader(filename + ".in"));
            out = new PrintWriter(filename + ".out");
            eat(null);

            preSolve();
            int nt = nextInt();
            for (int i = 1; i <= nt; ++i) {
                long t0 = System.currentTimeMillis();
                solve(i);
                t0 = System.currentTimeMillis() - t0;
                System.out.println(i + "/" + nt + " done in " + t0 + " ms.");
            }

            out.close();
            in.close();
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
    }

    void eat(String s) {
        st = s == null ? null : new StringTokenizer(s);
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    int[] nextIntArray() throws IOException {
        int n = nextInt();
        int[] rv = new int[n];
        for (int i = 0; i < n; ++i) {
            rv[i] = nextInt();
        }
        return rv;
    }

    int[] nextIntArrayFromLine() throws IOException {
        StringTokenizer st = new StringTokenizer(nextLine());
        int[] rv = new int[st.countTokens()];
        for (int i = 0; i < rv.length; ++i) {
            rv[i] = Integer.parseInt(st.nextToken());
        }
        return rv;
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    String nextLine() throws IOException {
        eat(null);
        return in.readLine();
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new Thread(new D()).start();
    }
}