import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ogiekako
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		MyScanner in = new MyScanner(inputStream);
		MyPrintWriter out = new MyPrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    private MyScanner in;
    private MyPrintWriter out;

    public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
        this.in = in;
        this.out = out;
        if (testNumber == 1) prepare();
        out.printFormat("Case #%d:\n", testNumber);
        System.err.println("case " + testNumber);
        solve();
    }

    private void prepare() {

    }

    private void solve() {
        int R = in.nextInt(), N = in.nextInt(), M = in.nextInt(), K = in.nextInt();
        for (int iter = 0; iter < R; iter++) {
            int[] prods = new int[K];
            for (int i = 0; i < K; i++) prods[i] = in.nextInt();
            int[] res = solve(new int[N], M, 0, prods);
            for (int r : res) out.printFormat("%d", r);
            out.println();
        }
    }

    private int[] solve(int[] res, int M, int p, int[] prods) {
        if (p >= res.length) {
            if (possible(res, prods)) return res;
            return null;
        } else {
            for (int i = 2; i <= M; i++) {
                res[p] = i;
                int[] a = solve(res, M, p + 1, prods);
                if (a != null) return a;
            }
        }
        return null;
    }

    private boolean possible(int[] val, int[] prods) {
        for (int p : prods) {
            boolean ok = false;
            for (int i = 0; i < 1 << val.length; i++) {
                int prod = 1;
                for (int j = 0; j < val.length; j++) if (i << 31 - j < 0) prod *= val[j];
                if (prod == p) ok = true;
            }
            if (!ok) return false;
        }
        return true;
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
        if(os.length == 0){
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
        out.printf(format,args);
    }

}

