import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.AbstractCollection;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int Q = in.nextInt();
            ArrayList<Long> q = new ArrayList<>();
            q.add((long) n);
            for (int i = 0; i < Q; ++i) {
                long x = in.nextLong();
                while (q.size() > 0 && q.get(q.size() - 1) >= x)
                    q.remove(q.size() - 1);
                q.add(x);
            }

            HashMap<Long, Long> d = new HashMap<>();
            PriorityQueue<Long> queue = new PriorityQueue<>();
            d.put(q.get(q.size() - 1), 1L);
            queue.add(-q.get(q.size() - 1));
            int cur = q.size() - 1;
            while (!queue.isEmpty()) {
                long val = -queue.poll();
                while (cur >= 0 && q.get(cur) >= val) --cur;
                if (cur == -1) continue;
                long prev = q.get(cur);
                long cnt = d.get(val);
                long r = val / prev;
                if (!d.containsKey(prev)) {
                    d.put(prev, cnt * r);
                    queue.add(-prev);
                } else {
                    d.put(prev, d.get(prev) + cnt * r);
                }
                if (val % prev != 0) {
                    long mod = val % prev;
                    if (!d.containsKey(mod)) {
                        d.put(mod, cnt);
                        queue.add(-mod);
                    } else {
                        d.put(mod, d.get(mod) + cnt);
                    }
                }
            }

            long[] res = new long[n + 1];
            for (int i = 1; i <= q.get(0); ++i) {
                if (!d.containsKey((long) i)) continue;
                long val = d.get((long) i);
                res[i] += val;
            }
            for (int i = n - 1; i > 0; --i)
                res[i] += res[i + 1];
            for (int i = 1; i <= n; ++i)
                out.printLine(res[i]);
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

        public long nextLong() {
            long sgn = 1;
            int c = readSkipSpace();
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10L + (long) (c - '0');
                c = read();
            } while (!isSpace(c));
            res *= sgn;
            return res;
        }

    }
}