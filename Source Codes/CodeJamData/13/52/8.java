import java.awt.event.MouseListener;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.awt.Color;
import java.util.Locale;
import java.awt.Container;
import java.io.PrintStream;
import java.util.Comparator;
import java.io.OutputStream;
import java.awt.event.MouseEvent;
import java.awt.Window;
import java.io.PrintWriter;
import java.io.File;
import java.io.Writer;
import java.io.FilenameFilter;
import java.awt.event.MouseAdapter;
import java.io.IOException;
import java.util.Arrays;
import java.awt.Graphics;
import javax.swing.JFrame;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.awt.Component;
import javax.swing.JPanel;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import javax.swing.JComponent;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ogiekako
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		MyScanner in = new MyScanner(inputStream);
		MyPrintWriter out = new MyPrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    int D = 5;
    public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
        int N = in.nextInt();
        Point[] ps = new Point[N];
        for (int i = 0; i < N; i++) ps[i] = Point.make(in.nextDouble(), in.nextDouble());


//        Vis vis = new Vis();
//        for(int i=0;i<N;i++)vis.addEdge(ps[i].mul(3),ps[nxt(i,N)].mul(3));
//        vis. repaint();

//        for(Point p:ps) System.err.println(p);

        Point[] conv = Polygon_methods.convexHull(ps);

//        vis = new Vis();
//        for(int i=0;i<conv.length;i++)vis.addEdge(conv[i].mul(D),conv[nxt(i,conv.length)].mul(D));
//        vis. repaint();

        double area = Polygon_methods.area(conv);
        area = Math.abs(area);

        boolean[] used = new boolean[N];
        for (int i = 0; i < N; i++) for (Point p : conv) if (p.eq(ps[i])) used[i] = true;
        while (conv.length < N) {
            int k = -1;
            int nj = -1;
            double dist = Double.POSITIVE_INFINITY;

            for (int i = 0; i < N; i++)
                if (!used[i]) {
                    for (int j = 0; j < conv.length; j++) {
                        Point p = conv[j], q = conv[nxt(j, conv.length)];
                        double curDist = Line_methods.disSP(p, q, ps[i]);
                        if (dist > curDist) {
                            k = i;
                            nj = j;
                            dist = curDist;
                        }
                    }
                }

            Point[] tmp = new Point[conv.length + 1];
            used[k] = true;
            for (int i = 0; i <= nj; i++) tmp[i] = conv[i];
            tmp[nj + 1] = ps[k];
            for (int i = nj + 2; i < tmp.length; i++) tmp[i] = conv[i - 1];
            conv = tmp;

//            vis = new Vis();
//            for(int i=0;i<conv.length;i++)vis.addEdge(conv[i].mul(D),conv[nxt(i,conv.length)].mul(D));
//            vis. repaint();
        }
        double curArea = Math.abs(Polygon_methods.area(conv));
        System.err.printf("%.2f\n", area / curArea);
        int[] res = new int[N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (conv[i].eq(ps[j])) res[i] = j;
            }
        }
        out.printFormat("Case #%d:", testNumber);
        for (int r : res) out.printFormat(" %d", r);
        out.println();
    }
    private int nxt(int i, int length) {
        int j = i + 1;
        if (j == length) return 0;
        return j;
    }
}

class MyScanner {
    private final InputStream in;

    public MyScanner(InputStream in) {
        this.in = in;
    }

    int bufLen;
    int bufPtr;
    byte[] buf = new byte[1024];

    public int read() {
        if (bufLen == -1)
            throw new InputMismatchException();
        if (bufPtr >= bufLen) {
            bufPtr = 0;
            try {
                bufLen = in.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (bufLen <= 0)
                return -1;
        }
        return buf[bufPtr++];
    }

    private char[] strBuf = new char[65536];

    public String next() {
        int strLen = 0;
        int c;
        do {
            c = read();
            if (c == -1) throw new NoSuchElementException();
        } while (Character.isWhitespace(c));
        do {
            if (strLen + 1 >= strBuf.length) {
                char[] tmp = new char[strBuf.length * 2];
                System.arraycopy(strBuf, 0, tmp, 0, strBuf.length);
                strBuf = tmp;
            }
            strBuf[strLen++] = (char) c;
            c = read();
        } while (c != -1 && !Character.isWhitespace(c));
        return new String(strBuf, 0, strLen);
    }

    public int nextInt() {
        int c = read();
        if (c == -1) throw new NoSuchElementException();
        while (c != '-' && (c < '0' || '9' < c)) {
            c = read();
            if (c == -1) throw new NoSuchElementException();
        }
        if (c == '-') return -nextInt();
        int res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = read();
        } while ('0' <= c && c <= '9');
        return res;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }


    }

class MyPrintWriter {
    PrintWriter out;

    public MyPrintWriter(OutputStream outputStream) {
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public MyPrintWriter(Writer writer) {
        out = new PrintWriter(writer);
    }

    public void println(Object... os) {
        if (os.length == 0) {
            out.println();
            return;
        }
        for (int i = 0; i < os.length - 1; i++) {
            out.print(os[i]);
            out.print(' ');
        }
        out.println(os[os.length - 1]);
    }

    public void close() {
        out.close();
    }

    public void printFormat(String format, Object... args) {
        out.printf(format, args);
    }

}

class Point implements Comparable<Point> {

    static int sgn(double d) {
        return d < -EPS.value() ? -1 : d > EPS.value() ? 1 : 0;
    }

    public final double x, y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double dist(Point p) {
        return sub(p).norm();
    }

    double norm() {
        return Math.sqrt(x * x + y * y);
    }

    public Point sub(Point p) {
        return new Point(x - p.x, y - p.y);
    }

    public Point mul(double d) {
        return new Point(x * d, y * d);
    }

    public double dot(Point p) {
        return x * p.x + y * p.y;
    }

    public double det(Point p) {
        return x * p.y - y * p.x;
    }

    public int compareTo(Point o) {
        return sgn(x - o.x) == 0 ? sgn(y - o.y) : sgn(x - o.x);
    }

    public static Point make(double x, double y) {
        return new Point(x, y);
    }
    /*
    relative or absolute error is less than eps.
    */
    public boolean eq(Point p) {
        double absDiff = dist(p);
        double myLen = norm();
        double pLen = p.norm();
        return absDiff < EPS.value() || absDiff < myLen * EPS.value() || absDiff < pLen * EPS.value();
    }
    public String toString() {
        String format = String.format("%%.%df %%.%df",precision, precision);
        return String.format(format, x, y);
    }
    static int precision = 2;
    }

class Vis extends JFrame {
    double D = 1;
    int H = 600, W = 600;
    public Vis() {
        setSize(W + 20, H + 40);
        setVisible(true);
        add(new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                g.clearRect(0, 0, H, W);
                g.setColor(Color.blue);
                for (int i = 0; i < ss.size(); i++) {
                    Point s = ss.get(i), t = ts.get(i);
                    g.drawLine(toi(s.x) + W / 2, H - toi(s.y) - H / 2, toi(t.x) + W / 2, H - toi(t.y) - H / 2);
                }
                for (int i = 0; i < os.size(); i++) {
                    g.setColor(ccs.get(i));
                    Point o = os.get(i);
                    double r = rs.get(i);
                    g.drawOval(toi(o.x - r) + W / 2, H - toi(o.y + r) - H / 2, toi(r * 2), toi(r * 2));
                    g.drawString(cnames.get(i), toi(o.x - r) + W / 2, H - toi(o.y + r) - H / 2);
                }
            }
            int toi(double d) {
                return (int) Math.round(d * D);
            }
        });
        addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                stop = false;
            }
        });
    }
    boolean stop = false;
    ArrayList<Point> ss = new ArrayList<Point>();
    ArrayList<Point> ts = new ArrayList<Point>();
    public void addEdge(Point p1, Point p2) {
        ss.add(p1);
        ts.add(p2);
    }
    ArrayList<Point> os = new ArrayList<Point>();
    ArrayList<Double> rs = new ArrayList<Double>();
    ArrayList<Color> ccs = new ArrayList<Color>();
    ArrayList<String> cnames = new ArrayList<String>();
    }

class Polygon_methods {
    public static double area(Point[] ps) {// 符号付き面積。反時計回りのとき正、時計回りのとき負。
        double S = 0;
        for (int i = 0; i < ps.length; i++)
            S += ps[i].det(ps[(i + 1) % ps.length]);
        return S / 2;
    }

    // verified: pku3348.
    // generate anti-clockwise convex hull.
    // le -> lt : include points on edge.
    static int dn;
    static Point[] ds;
    static int un;
    static Point[] us;
    public static Point[] convexHull(Point[] ps) { // O(n logn).
        ps = ps.clone();
        int n = ps.length;
        Arrays.sort(ps);
        ds = new Point[n];// ds[0] = us[un-1] = ps[0].
        us = new Point[n];// ds[dn-1] = us[0] = ps[n-1].
        dn = 0;
        un = 0;
        for (int i = 0; i < n; ds[dn++] = ps[i++])
            while (dn >= 2 && EPS.le(ds[dn - 1].sub(ds[dn - 2]).det(ps[i].sub(ds[dn - 2])), 0))
                dn--;
        for (int i = n - 1; i >= 0; us[un++] = ps[i--])
            while (un >= 2 && EPS.le(us[un - 1].sub(us[un - 2]).det(ps[i].sub(us[un - 2])), 0))
                un--;
        Point[] res = new Point[dn + un - 2];
        System.arraycopy(ds, 0, res, 0, dn - 1);
        System.arraycopy(us, 0, res, dn - 1, un - 1);
        return res;
    }

    }

class Line_methods {
    private Line_methods() {
    }

    /**
     * 点と線分の距離
     *
     * @param p1
     * @param p2
     * @param q
     * @return
     */
    public static double disSP(Point p1, Point p2, Point q) {// AOJ1265
        if (p2.sub(p1).dot(q.sub(p1)) < 0) return q.sub(p1).norm();
        if (p1.sub(p2).dot(q.sub(p2)) < 0) return q.sub(p2).norm();
        return disLP(p1, p2, q);
    }
    /**
     * 直線と線分の距離
     *
     * @param p1
     * @param p2
     * @param q
     * @return
     */
    public static double disLP(Point p1, Point p2, Point q) {// AOJ1265
        return Math.abs(p2.sub(p1).det(q.sub(p1))) / p2.sub(p1).norm();
    }

    }

class EPS {
    public static double EPS = 1e-9;
    public static boolean le(double a, double b) {
        return a < b + EPS;
    }
    public static double value() {
        return EPS;
    }
    }

