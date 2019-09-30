import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ilyakor
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int n;
        TaskD.Perm f;
        TaskD.Perm g;
        TaskD.Perm F;
        TaskD.Perm G;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            int k = in.nextInt() - 1;
            f = new TaskD.Perm(n);
            g = new TaskD.Perm(n);
            for (int i = 0; i < n; ++i)
                f.a[i] = in.nextInt() - 1;
            for (int i = 0; i < n; ++i)
                g.a[i] = in.nextInt() - 1;
            F = f.inv();
            G = g.inv();

            int[][] d = new int[60][];
            d[0] = new int[]{1};
            d[1] = new int[]{2};
            for (int i = 2; i < d.length; ++i)
                d[i] = mult(d[i - 1], inv(d[i - 2]));

            TaskD.Perm base = g.mult(F).mult(G).mult(f);
            int cnt = k / 6;
            base = pow(base, cnt);
            TaskD.Perm ibase = base.inv();

            TaskD.Perm res = base.mult(toPerm(d[k % 6])).mult(ibase);
            for (int i = 0; i < n; ++i)
                out.print((res.a[i] + 1) + " ");
            out.printLine();
//        for (int i = 0; i < d.length; ++i)
//            System.err.println(tostr(d[i]));
        }

        private TaskD.Perm pow(TaskD.Perm x, int y) {
            TaskD.Perm res = new TaskD.Perm(n);
            while (y > 0) {
                if (y % 2 == 0) {
                    y /= 2;
                    x = x.mult(x);
                } else {
                    --y;
                    res = res.mult(x);
                }
            }
            return res;
        }

        TaskD.Perm toPerm(int[] a) {
            TaskD.Perm res = new TaskD.Perm(n);
            for (int x : a) {
                if (x == 1) res = res.mult(f);
                if (x == 2) res = res.mult(g);
                if (x == -1) res = res.mult(F);
                if (x == -2) res = res.mult(G);
            }
            return res;
        }

        private int[] mult(int[] a, int[] b) {
            int l = a.length - 1, r = 0;
            while (l >= 0 && r < b.length && a[l] + b[r] == 0) {
                --l;
                ++r;
            }
            int[] res = new int[l + 1 + b.length - r];
            for (int i = 0; i <= l; ++i)
                res[i] = a[i];
            for (int i = r; i < b.length; ++i)
                res[l + 1 + i - r] = b[i];
            return res;
        }

        private int[] inv(int[] a) {
            int[] res = new int[a.length];
            for (int i = 0; i < a.length; ++i)
                res[i] = -a[a.length - i - 1];
            return res;
        }

        static class Perm {
            int[] a;

            public Perm(int n) {
                a = new int[n];
                for (int i = 0; i < n; ++i)
                    a[i] = i;
            }

            TaskD.Perm mult(TaskD.Perm other) {
                TaskD.Perm res = new TaskD.Perm(a.length);
                for (int i = 0; i < a.length; ++i)
                    res.a[i] = a[other.a[i]];
                return res;
            }

            TaskD.Perm inv() {
                TaskD.Perm res = new TaskD.Perm(a.length);
                for (int i = 0; i < a.length; ++i)
                    res.a[a[i]] = i;
                return res;
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buffer = new byte[10000];
        private int cur;
        private int count;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public static boolean isSpace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int read() {
            if (count == -1) {
                throw new InputMismatchException();
            }
            try {
                if (cur >= count) {
                    cur = 0;
                    count = stream.read(buffer);
                    if (count <= 0)
                        return -1;
                }
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            return buffer[cur++];
        }

        public int readSkipSpace() {
            int c;
            do {
                c = read();
            } while (isSpace(c));
            return c;
        }

        public int nextInt() {
            int sgn = 1;
            int c = readSkipSpace();
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10 + c - '0';
                c = read();
            } while (!isSpace(c));
            res *= sgn;
            return res;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}