import java.io.*;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.regex.Pattern;

public class D implements Runnable {

    // all files <INPUT_PREFIX>-*.in will be solved
    private static final String INPUT_PREFIX = "D";
    private static final String OUTPUT_SUFFIX = "-default";

    private class TestCaseSolver {

        int n;
        int[] x, y, r;
        double[][] cx, cy, cr;
        double[][] cx0, cy0, cx1, cy1;

        double dist(double x1, double y1, double x2, double y2) {
            return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }

        double getNext(double x0, double x1, double t) {
            return x0 + (x1 - x0) * t;
        }

        final double mx = 1e6;
        final int MAX_STEPS = 1000;

        boolean[] was;

        private void solve() {
            n = nextInt();
            x = new int[n];
            y = new int[n];
            r = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
                y[i] = nextInt();
                r[i] = nextInt();
            }

            cx0 = new double[n][n];
            cy0 = new double[n][n];
            cx1 = new double[n][n];
            cy1 = new double[n][n];

            cx = new double[n][n];
            cy = new double[n][n];
            cr = new double[n][n];
            for (int i1 = 0; i1 < n; i1++)
                for (int i2 = i1; i2 < n; i2++) {

                    // corner case
                    if (x[i1] == x[i2] && y[i1] == y[i2]) {
                        cx[i1][i2] = x[i1];
                        cy[i1][i2] = y[i1];
                        cr[i1][i2] = Math.max(r[i1], r[i2]);
                        continue;
                    }

                    double distance = dist(x[i1], y[i1], x[i2], y[i2]);

                    {
                        double tLo = -mx;
                        double tHi = 0;
                        double requiredDistance = r[i1];
                        double requiredDistanceFromX = x[i1];
                        double requiredDistanceFromY = y[i1];
                        for (int steps = 0; steps < MAX_STEPS; steps++) {
                            double tMid = (tLo + tHi) / 2.0;

                            double xMid = getNext(x[i1], x[i2], tMid);
                            double yMid = getNext(y[i1], y[i2], tMid);

                            if (dist(xMid, yMid, requiredDistanceFromX, requiredDistanceFromY) > requiredDistance) {
                                tLo = tMid;
                            } else {
                                tHi = tMid;
                            }
                        }

                        double t = (tLo + tHi) / 2.0;
                        cx0[i1][i2] = getNext(x[i1], x[i2], t);
                        cy0[i1][i2] = getNext(y[i1], y[i2], t);
                    }

                    {
                        double tLo = 1;
                        double tHi = mx;
                        double requiredDistance = r[i2];
                        double requiredDistanceFromX = x[i2];
                        double requiredDistanceFromY = y[i2];
                        for (int steps = 0; steps < MAX_STEPS; steps++) {
                            double tMid = (tLo + tHi) / 2.0;

                            double xMid = getNext(x[i1], x[i2], tMid);
                            double yMid = getNext(y[i1], y[i2], tMid);

                            if (dist(xMid, yMid, requiredDistanceFromX, requiredDistanceFromY) > requiredDistance) {
                                tHi = tMid;
                            } else {
                                tLo = tMid;
                            }
                        }

                        double t = (tLo + tHi) / 2.0;
                        cx1[i1][i2] = getNext(x[i1], x[i2], t);
                        cy1[i1][i2] = getNext(y[i1], y[i2], t);
                    }

                    double between = dist(cx0[i1][i2], cy0[i1][i2], cx1[i1][i2], cy1[i1][i2]);
                    double betweenMust = distance + r[i1] + r[i2];
                    if (Math.abs(between - betweenMust) > EPS) {
                        throw new IllegalStateException();
                    }

                    cx[i1][i2] = (cx0[i1][i2] + cx1[i1][i2]) / 2.0;
                    cy[i1][i2] = (cy0[i1][i2] + cy1[i1][i2]) / 2.0;
                    cr[i1][i2] = (distance + r[i1] + r[i2]) / 2.0;

                    if (!inside(x[i1], y[i1], r[i1], cx[i1][i2], cy[i1][i2], cr[i1][i2])) {
                        throw new IllegalStateException();
                    }
                    if (!inside(x[i2], y[i2], r[i2], cx[i1][i2], cy[i1][i2], cr[i1][i2])) {
                        throw new IllegalStateException();
                    }
                }

            double answer = Double.MAX_VALUE;
            was = new boolean[n];
            for (int i1 = 0; i1 < n; i1++)
                for (int i2 = i1; i2 < n; i2++)
                    for (int i3 = 0; i3 < n; i3++)
                        for (int i4 = i3; i4 < n; i4++) {
                            Arrays.fill(was, false);
                            markWas(i1, i2);
                            markWas(i3, i4);

                            int count = 0;
                            for (int i = 0; i < n; i++)
                                if (was[i]) {
                                    count++;
                                }

                            if (count >= n) {
                                double r = Math.max(cr[i1][i2], cr[i3][i4]);
                                answer = Math.min(answer, r);
                            }
                        }

            out.print(' ');
            out.printf("%.8f", answer);
        }

        private void markWas(int i1, int i2) {
            double xc = cx[i1][i2];
            double yc = cy[i1][i2];
            double rc = cr[i1][i2];

            for (int i = 0; i < n; i++)
                if (inside(x[i], y[i], r[i], xc, yc, rc)) {
                    was[i] = true;
                }
        }

        final double EPS = 1e-8;

        private boolean inside(double x1, double y1, double r1, double x2, double y2, double r2) {
            double d = dist(x1, y1, x2, y2);
            if (d + r1 < r2 + EPS) {
                return true;
            }
            return false;
        }

    }

    private BufferedReader in;
    private PrintWriter out;

    private StringTokenizer tokenizer = new StringTokenizer("");

    private String nextToken() {
        while (!tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = in.readLine();
            } catch (IOException e) {
                throw new IllegalStateException(e);
            }
            if (line == null) {
                return null;
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    private String nextLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }
    }

    private int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private int estimatedTimeLeft(int tc, int tCount, long timeStart) {
        long time = System.currentTimeMillis();
        double timePerTest = (1.0 * (time - timeStart)) / tc;
        return (int) (timePerTest * (tCount - tc) / 1000.0);
    }

    private void solve(File inFile) {
        long timeStart = System.currentTimeMillis();

        try {
            in = new BufferedReader(new FileReader(inFile));
            out = new PrintWriter(new FileWriter(inFile.getName() + OUTPUT_SUFFIX + ".out"));
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }

        int tCount = nextInt();
        for (int tc = 0; tc < tCount; tc++) {
            System.out.print("Solving test case #" + (tc + 1) + "/" + tCount);
            if (tc > 0) {
                System.out.print(", estimated time left: " + estimatedTimeLeft(tc, tCount, timeStart) + " sec");
            }
            System.out.println();

            out.print("Case #" + (tc + 1) + ":");
            new D.TestCaseSolver().solve();
            out.println();
        }

        try {
            in.close();
            out.close();
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }
    }

    public void run() {
        final Pattern inPattern = Pattern.compile("^" + Pattern.quote(INPUT_PREFIX) + "\\-.*\\.in$", Pattern.CASE_INSENSITIVE);
        final File[] inFiles = new File(".").listFiles(
            new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return inPattern.matcher(name).matches();
                }
            }
        );
        for (File inFile : inFiles) {
            System.out.println("Solving [" + inFile.getName() + ']');
            solve(inFile);
        }
    }

    public static void main(String[] args) {
        new Thread(new D()).start();
    }
}
