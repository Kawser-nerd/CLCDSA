import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ogiekako
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyScanner in = new MyScanner(inputStream);
        MyPrintWriter out = new MyPrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
            long A = in.nextLong(), B = in.nextLong();
            long res = solve(A, B);
            out.println(res);
        }

        private long solve(long A, long B) {
            if (A == B) return 1;
            if (A == 0) {
                return B + 1;
            }
            if (A > B) throw new RuntimeException();

            long a = Long.highestOneBit(A);
            long b = Long.highestOneBit(B);

            if (a == b) return solve(A ^ a, B ^ b);

            long res = b - A;

            long b2 = Long.highestOneBit(B ^ b) << 1;
            if (b2 == 0) return res + b - A + 1;
            A = Math.max(A, b2);
            return res + b - A + b2;
        }

    }

    static class MyPrintWriter {
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

    }

    static class MyScanner {
        private final InputStream in;
        private static final int BUFSIZE = 65536;
        int bufLen;
        int bufPtr;
        byte[] buf = new byte[BUFSIZE];

        public MyScanner(InputStream in) {
            this.in = in;
        }

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

        public long nextLong() {
            int c = read();
            if (c == -1) throw new NoSuchElementException();
            while (c != '-' && (c < '0' || '9' < c)) {
                c = read();
                if (c == -1) throw new NoSuchElementException();
            }
            if (c == '-') return -nextLong();
            long res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while ('0' <= c && c <= '9');
            return res;
        }

    }
}