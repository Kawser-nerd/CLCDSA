
import javax.swing.plaf.basic.ComboPopup;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(B.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(B.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int w = in.nextInt();
        int h = in.nextInt();
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            r[i] = in.nextInt();
        }
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (r[p[j]] > r[p[i]]) {
                    int t = p[i];
                    p[i] = p[j];
                    p[j] = t;
                }
            }
        }
        double[] x = new double[n];
        double[] y = new double[n];
        for (int ii = 0; ii < n; ii++) {
            int i = p[ii];
            double ll = 0;
            double rr = h;
            while (rr > ll + 1e-9) {
                double mm = (ll + rr) / 2;
                List<Segment> segments = new ArrayList<Segment>();
                for (int jj = 0; jj < ii; jj++) {
                    int j = p[jj];
                    double y1 = Math.max(mm - r[i], y[j] - r[j]);
                    double y2 = Math.min(mm + r[i], y[j] + r[j]);
                    if (y2 > y1) {
                        segments.add(new Segment(x[j] - r[j] - r[i], x[j] + r[j] + r[i]));
                    }
                }
                Collections.sort(segments);
                double xx = 0;
                boolean ok = false;
                for (Segment segment : segments) {
                    if (segment.l >= xx) {
                        ok = true;
                        x[i] = xx;
                        y[i] = mm;
                        break;
                    } else {
                        xx = Math.max(xx, segment.r);
                    }
                }
                if (!ok) {
                    if (xx <= w) {
                        ok = true;
                        x[i] = xx;
                        y[i] = mm;
                    }
                }
                if (ok) {
                    rr = mm;
                } else {
                    ll = mm;
                }
            }
            if (y[i] == 0) {
                throw new RuntimeException();
            }
        }
        StringBuffer res = new StringBuffer();
        for (int i = 0; i < n; i++) {
            res.append(x[i]).append(" ").append(y[i]).append(" ");
        }
        return res.toString();
    }

    class Segment implements Comparable<Segment> {
        double l;
        double r;

        Segment(double l, double r) {
            this.l = l;
            this.r = r;
        }

        public int compareTo(Segment o) {
            return l > o.l ? 1 : -1;
        }
    }
}