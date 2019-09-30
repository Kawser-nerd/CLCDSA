import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.Writer;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author palayutm
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            if (n == 3) {
                out.println("2 5 63");
                return;
            }
            int[] a = new int[n];
            int top = 0;
            for (int i = 3; i <= 30000 && top + 3 < n; i += 12) {
                a[top++] = i;
                a[top++] = i + 6;
            }
            for (int i = 2; i <= 30000 && top < n; i += 2) {
                a[top++] = i;
            }
            long S = 0;
            for (int x : a) {
                S += x;
            }
            while (S % 3 > 0) {
                a[n - 1] += 2;
                S += 2;
            }
            out.println(a);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] inbuf = new byte[1024];
        private int lenbuf = 0;
        private int ptrbuf = 0;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int readByte() {
            if (lenbuf == -1) throw new UnknownError();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = stream.read(inbuf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        public int nextInt() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

    }

    static class OutputWriter extends PrintWriter {
        public OutputWriter(OutputStream out) {
            super(out);
        }

        public OutputWriter(Writer out) {
            super(out);
        }

        public void close() {
            super.close();
        }

        public void print(int[] a) {
            for (int i = 0; i < a.length; i++) {
                if (i != 0) {
                    print(' ');
                }
                print(a[i]);
            }
        }

        public void println(int[] a) {
            print(a);
            println();
        }

    }
}