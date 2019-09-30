import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.math.BigInteger;
import java.awt.*;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class B {

    static Scanner in;
    static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("b.in"));
        out = new PrintWriter("b.out");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new B().solve());
        }
        out.close();
    }

    private Object solve() {
        int w = in.nextInt();
        int h = in.nextInt();
        int x1 = in.nextInt();
        int y1 = in.nextInt();
        int x2 = in.nextInt();
        int y2 = in.nextInt();
        int x0 = in.nextInt();
        int y0 = in.nextInt();

        {
        int x = x0;
        int y = y0;
        Set<Point> m = new HashSet<Point>();
        dfs(new Point(x, y), x1, y1, x2, y2, w, h, m);
        return m.size();
       }
//        if ((long) x1 * y2 == (long) x2 * y1) {
//            int x = x0;
//            int y = y0;
//            Set<Point> m = new HashSet<Point>();
//            dfs(new Point(x, y), x1, y1, x2, y2, w, h, m);
//            return m.size();
//        } else {
//            int x = x0;
//            int y = y0;
//            long res = 0;
//            long l = 0;
//            long r = 2000000;
//            while (true) {
//                while (l < 2000000 && !isOk(x + x2 * l, y + y2 * l, w, h)) l++;
//                while (isOk(x + x2 * (l - 1), y + y2 * (l - 1), w, h)) l--;
//                while (r >= 0 && !isOk(x + x2 * r, y + y2 * r, w, h)) r--;
//                while (isOk(x + x2 * (r + 1), y + y2 * (r + 1), w, h)) r++;
//                System.out.println("" + x + " " + y + " " + l + " " + r);
//                if (r < l) break;
//                res += r - l + 1;
//                x += x1;
//                y += y1;
//            }
//            return res;
//        }

    }

    private void dfs(Point p, int x1, int y1, int x2, int y2, int w, int h, Set<Point> m) {
        if (m.contains(p)) return;
        if (!isOk(p.x, p.y, w, h)) return;
        m.add(p);
        dfs(new Point(p.x + x1, p.y + y1), x1, y1, x2, y2, w, h, m);
        dfs(new Point(p.x + x2, p.y + y2), x1, y1, x2, y2, w, h, m);
    }

    private long count(int x, int y, int dx, int dy, int w, int h) {
        int l = 0;
        int r = 2000000;
        while (r > l + 1) {
            int m = (l + r) / 2;
            long xx = x + m * dx;
            long yy = y + m * dy;
            if (isOk(xx, yy, w, h)) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }

    private boolean isOk(long x, long y, int w, int h) {
        return (x >= 0 && y >= 0 && x < w && y < h);
    }
}
