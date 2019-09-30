/*
 * Copyright (C) 2008 TopCoder Inc., All Rights Reserved.
 */

import java.io.*;
import java.util.*;

import java.io.PrintWriter;

public class C {
    PrintWriter out;
    Scanner in;

    int n;
    int[] x, y, z, p;

    boolean checkPoint(double x0, double y0, double z0, double t) {
        for (int i = 0; i < n; ++i) {
            double d = Math.abs(x0 - x[i]) + Math.abs(y0 - y[i]) + Math.abs(z0 - z[i]);
            d /= p[i];
            if (d > t + 1e-6) {
                return false;
            }
        }
        return true;
    }

    boolean check(double t) {
        double[] max = new double[4];
        double[] min = new double[4];
        for (int i = 0; i < 4; ++i) {
            max[i] = -100000000;
            min[i] = 100000000;
        }

        double[] val = new double[4];
        for (int i = 0; i < n; ++i) {
            double d = p[i] * t;
            max[0] = Math.max(max[0], x[i] + y[i] + z[i] - d);
            min[0] = Math.min(min[0], x[i] + y[i] + z[i] + d);
            max[1] = Math.max(max[1], x[i] + y[i] - z[i] - d);
            min[1] = Math.min(min[1], x[i] + y[i] - z[i] + d);
            max[2] = Math.max(max[2], x[i] - y[i] + z[i] - d);
            min[2] = Math.min(min[2], x[i] - y[i] + z[i] + d);
            max[3] = Math.max(max[3], -x[i] + y[i] + z[i] - d);
            min[3] = Math.min(min[3], -x[i] + y[i] + z[i] + d);
        }
        for (int i = 0; i < 4; ++i) {
            if (min[i] < max[i] + 1e-7) {
                return false;
            }
        }

        /*for (int i = 0; i < n; ++i) {
            double d = p[i] * t;

            if (checkPoint(x[i], y[i], z[i], t)) {
                return true;
            }

            if (checkPoint(x[i] + d, y[i], z[i], t)) {
                return true;
            }
            if (checkPoint(x[i] - d, y[i], z[i], t)) {
                return true;
            }
            if (checkPoint(x[i], y[i] + d, z[i], t)) {
                return true;
            }
            if (checkPoint(x[i], y[i] - d, z[i], t)) {
                return true;
            }
            if (checkPoint(x[i], y[i], z[i] + d, t)) {
                return true;
            }
            if (checkPoint(x[i], y[i], z[i] - d, t)) {
                return true;
            }

            if (checkPoint(x[i] + d / 2, y[i] + d / 2, z[i], t)) {
                return true;
            }
            if (checkPoint(x[i] + d / 2, y[i] - d / 2, z[i], t)) {
                return true;
            }
            if (checkPoint(x[i] + d / 2, y[i], z[i] + d / 2, t)) {
                return true;
            }
            if (checkPoint(x[i] + d / 2, y[i], z[i] - d / 2, t)) {
                return true;
            }
            if (checkPoint(x[i] - d / 2, y[i] + d / 2, z[i], t)) {
                return true;
            }
            if (checkPoint(x[i] - d / 2, y[i] - d / 2, z[i], t)) {
                return true;
            }
            if (checkPoint(x[i] - d / 2, y[i], z[i] + d / 2, t)) {
                return true;
            }
            if (checkPoint(x[i] - d / 2, y[i], z[i] - d / 2, t)) {
                return true;
            }
            if (checkPoint(x[i], y[i] + d / 2, z[i] + d / 2, t)) {
                return true;
            }
            if (checkPoint(x[i], y[i] + d / 2, z[i] - d / 2, t)) {
                return true;
            }
            if (checkPoint(x[i], y[i] - d / 2, z[i] + d / 2, t)) {
                return true;
            }
            if (checkPoint(x[i], y[i] - d / 2, z[i] - d / 2, t)) {
                return true;
            }

            if (checkPoint(x[i] + d / 3, y[i] + d / 3, z[i] + d / 3, t)) {
                return true;
            }
            if (checkPoint(x[i] + d / 3, y[i] + d / 3, z[i] - d / 3, t)) {
                return true;
            }
            if (checkPoint(x[i] + d / 3, y[i] - d / 3, z[i] + d / 3, t)) {
                return true;
            }
            if (checkPoint(x[i] + d / 3, y[i] - d / 3, z[i] - d / 3, t)) {
                return true;
            }
            if (checkPoint(x[i] - d / 3, y[i] + d / 3, z[i] + d / 3, t)) {
                return true;
            }
            if (checkPoint(x[i] - d / 3, y[i] + d / 3, z[i] - d / 3, t)) {
                return true;
            }
            if (checkPoint(x[i] - d / 3, y[i] - d / 3, z[i] + d / 3, t)) {
                return true;
            }
            if (checkPoint(x[i] - d / 3, y[i] - d / 3, z[i] - d / 3, t)) {
                return true;
            }
        }*/
        return true;
    }

    void solve() throws Exception {
        Locale.setDefault(Locale.ENGLISH);
        out = new PrintWriter(new FileOutputStream("c.out"));
        in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("c.in"))));

        int N = in.nextInt();
        for (int t = 1; t <= N; ++t) {
            out.print("Case #" + t + ": ");
            n = in.nextInt();
            x = new int[n];
            y = new int[n];
            z = new int[n];
            p = new int[n];
            for (int i = 0; i < n; ++i) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
                z[i] = in.nextInt();
                p[i] = in.nextInt();
            }

            double lo = 0;
            double hi = 100000000;
            while (hi - lo >= 1e-9) {
                double mid = (hi + lo) / 2;
                if (check(mid)) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            out.println(lo);
        }

        out.close();
    }

    public static void main(String[] args) throws Exception {
        new C().solve();
    }
}
