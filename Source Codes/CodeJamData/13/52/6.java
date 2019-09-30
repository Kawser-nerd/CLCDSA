import java.io.PrintStream;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.Reader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("taskb1.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("taskb1.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskB1 solver = new TaskB1();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB1 {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        System.err.println("[" + testNumber + "]");
        out.print("Case #" + testNumber + ":");
        int n = in.nextInt();
        Point2DInteger[] p = new Point2DInteger[n];
        for (int i = 0; i < n; i++) {
            p[i] = new Point2DInteger(in.nextInt(), in.nextInt());
        }
        int[] perm = new int[n];
        for (int i = 0; i < n; i++) {
            perm[i] = i;
        }
        int[] ans = null;
        long bestArea = 0;
        do {
            if (perm[0] != 0) break;
            boolean ok = true;
            Point2DInteger[] q = new Point2DInteger[n];
            for (int i = 0; i < n; i++) {
                q[i] = p[perm[i]];
            }
            all:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j || (i + 1) % n == j || i == (j + 1) % n) {
                        continue;
                    }
                    if (GeometryAlgorithms.segmentsIntersect(q[i], q[(i + 1) % n], q[j], q[(j + 1) % n])) {
                        ok = false;
                        break all;
                    }
                }
            }
            if (ok) {
                long area = GeometryAlgorithms.signedDoubledArea(q);
                if (area > bestArea) {
                    bestArea = area;
                    ans = perm.clone();
                }
            }
        } while (ArrayUtils.nextPermutation(perm));
        for (int i : ans) out.print(" " + i);
        out.println();
    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}

class Point2DInteger {
    public int x;
    public int y;

    public Point2DInteger(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public long vmul(Point2DInteger p) {
        return (long) x * p.y - (long) y * p.x;
    }

    public String toString() {
        return "{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Point2DInteger that = (Point2DInteger) o;

        if (x != that.x) return false;
        if (y != that.y) return false;

        return true;
    }

    public int hashCode() {
        int result = x;
        result = 31 * result + y;
        return result;
    }


    }

class GeometryAlgorithms {

    public static long vmulFromPoint(Point2DInteger from, Point2DInteger v, Point2DInteger u) {
        long x1 = v.x - from.x;
        long y1 = v.y - from.y;
        long x2 = u.x - from.x;
        long y2 = u.y - from.y;
        return x1 * y2 - x2 * y1;
    }

    public static long signedDoubledArea(Point2DInteger... p) {
        long ret = 0;
        for (int i = 0; i < p.length; i++) {
            int j = i + 1;
            if (j == p.length) {
                j = 0;
            }
            ret += p[i].vmul(p[j]);
        }
        return ret;
    }

    public static boolean segmentsIntersect(Point2DInteger p1, Point2DInteger p2, Point2DInteger q1, Point2DInteger q2) {
        long v1 = vmulFromPoint(p1, q1, q2);
        long v2 = vmulFromPoint(p2, q1, q2);
        long u1 = vmulFromPoint(q1, p1, p2);
        long u2 = vmulFromPoint(q2, p1, p2);
        if (v1 == 0 && v2 == 0 && u1 == 0 && u2 == 0) {
            return Math.max(Math.min(p1.x, p2.x), Math.min(q1.x, q2.x)) <= Math.min(Math.max(p1.x, p2.x), Math.max(q1.x, q2.x)) &&
                    Math.max(Math.min(p1.y, p2.y), Math.min(q1.y, q2.y)) <= Math.min(Math.max(p1.y, p2.y), Math.max(q1.y, q2.y));
        }
        return Long.signum(v1) != Long.signum(v2) && Long.signum(u1) != Long.signum(u2);
    }

}

class ArrayUtils {


    public static boolean nextPermutation(int[] a) {
        for (int i = a.length - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                int cur = i + 1;
                for (int j = i + 2; j < a.length; j++) {
                    if (a[j] > a[i] && a[j] < a[cur]) {
                        cur = j;
                    }
                }
                {
                    int t = a[cur];
                    a[cur] = a[i];
                    a[i] = t;
                }
                for (int j = i + 1, k = a.length - 1; j < k; j++, k--) {
                    int t = a[j];
                    a[j] = a[k];
                    a[k] = t;
                }
                return true;
            }
        }
        return false;
    }


    }

