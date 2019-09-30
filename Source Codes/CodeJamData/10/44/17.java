import java.io.*;
import java.util.*;

/**
 * @author def
 * @version 1.0
 */
public class D {

    public static void main(String args[]) throws IOException {
        new D().solve();
    }

    void solve() throws IOException {
        in = new BufferedReader(new FileReader("D-small-attempt0.in"));
        out = new PrintWriter("D-small-attempt0.out");

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int[] px = new int[n];
            int[] py = new int[n];
            for (int i = 0; i < n; ++i) {
                st = new StringTokenizer(in.readLine());
                px[i] = Integer.parseInt(st.nextToken());
                py[i] = Integer.parseInt(st.nextToken());
            }
            out.print("Case #" + c + ":");
            for (int i = 0; i < m; ++i) {
                st = new StringTokenizer(in.readLine());
                int qx = Integer.parseInt(st.nextToken());
                int qy = Integer.parseInt(st.nextToken());
                double r1 = dist(px[0], py[0], qx, qy);
                double r2 = dist(px[1], py[1], qx, qy);
                double l = dist(px[0], py[0], px[1], py[1]);
                double a1 = acos(r1, l, r2);
                double a2 = acos(r2, l, r1);
                double tr1 = 0.5 * r1 * r1 * Math.sin(2.0 * a1);
                double tr2 = 0.5 * r2 * r2 * Math.sin(2.0 * a2);
                double s = (a1 * r1 * r1 - tr1) + (a2 * r2 * r2 - tr2);
                out.print(" " + new Formatter(Locale.US).format("%.7f", s));
            }
            out.println();
        }

        out.close();
    }

    double dist(int x1, int y1, int x2, int y2) {
        return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

    double acos(double a, double b, double c) {
        return Math.acos(0.5 * (a * a + b * b - c * c) / a / b); 
    }

    BufferedReader in;
    PrintWriter out;
}