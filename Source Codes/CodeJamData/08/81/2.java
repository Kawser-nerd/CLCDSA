import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.awt.*;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class A {

    static Scanner in;
    static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("a.in"));
        out = new PrintWriter("a.out");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new A().solve());
        }
        out.close();
    }

    private Object solve() {
        Point[] t1 = new Point[3];
        Point[] t2 = new Point[3];
        for (int i = 0; i < 3; i++) t1[i] = new Point(in.nextInt(), in.nextInt());
        for (int i = 0; i < 3; i++) t2[i] = new Point(in.nextInt(), in.nextInt());

        for (int k = 0; k < 3; k++) {

            Point t = t1[2];
            t1[2] = t1[1];
            t1[1] = t1[0];
            t1[0] = t;

            Point v1 = new Point(t1[1].x - t1[0].x, t1[1].y - t1[0].y);
            Point v2 = new Point(t1[2].x - t1[0].x, t1[2].y - t1[0].y);
            Point v3 = new Point(t2[1].x - t2[0].x, t2[1].y - t2[0].y);
            Point v4 = new Point(t2[2].x - t2[0].x, t2[2].y - t2[0].y);

            if (v1.x * v2.y - v1.y * v2.x < 0) {
                t = v1;
                v1 = v2;
                v2 = t;
            }
            if (v3.x * v4.y - v3.y * v4.x < 0) {
                t = v3;
                v3 = v4;
                v4 = t;
            }

            double d1 = (v1.x * v1.x + v1.y * v1.y) / (v3.x * v3.x + v3.y * v3.y);
            double d2 = (v2.x * v2.x + v2.y * v2.y) / (v4.x * v4.x + v4.y * v4.y);
            double dd = (v1.x * v2.y - v1.y * v2.x) / (v3.x * v4.y - v3.y * v4.x);

            if (Math.abs(d1 - d2) < 1e-9 && Math.abs(dd - d1) < 1e-9) {


                double a1 = (v1.x - v3.x);
                double b1 = (v2.x - v4.x);
                double c1 = t2[0].x - t1[0].x;

                double a2 = (v1.y - v3.y);
                double b2 = (v2.y - v4.y);
                double c2 = t2[0].y - t1[0].y;

                double x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
                double y = (c1 * a2 - c2 * a1) / (b1 * a2 - b2 * a1);

                double xx = t1[0].x + v1.x * x + v2.x * y;
                double yy = t1[0].y + v1.y * x + v2.y * y;


                return "" + xx + " " + yy;
            }
        }
        return "???";
    }
}
