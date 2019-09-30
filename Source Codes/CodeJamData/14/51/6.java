import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        System.err.println("[" + testNumber + "]");
        int n = in.nextInt();
        int p = in.nextInt();
        int q = in.nextInt();
        int r = in.nextInt();
        int s = in.nextInt();
        a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = ((long) i * p + q) % r + s;
        }
        for (int i = 1; i < n; i++) a[i] += a[i - 1];
        long minimal = a[n - 1];
        for (int i = 0; i < n; i++) {
            minimal = Math.min(minimal, Math.max(sum(0, i), sum(i, n)));
        }
        for (int i = 2, j = 1; i < n; i++) {
            while (j + 1 < i && sum(0, j + 1) <= sum(j + 1, i)) {
                ++j;
            }
            minimal = Math.min(minimal, Math.max(Math.max(sum(i, n), sum(j, i)), sum(0, j)));
            if (j + 1 < i) {
                minimal = Math.min(minimal, Math.max(Math.max(sum(i, n), sum(j + 1, i)), sum(0, j + 1)));
            }
        }
        out.println("Case #" + testNumber + ": " + (1. - 1. * minimal / a[n - 1]));
    }

    static long[] a;

    static long sum(int l, int r) {
        if (l >= r) return 0;
        long ret = a[r - 1];
        if (l > 0) ret -= a[l - 1];
        return ret;
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

