import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashSet;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final long BUBEN = (long) (1E11);

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            //int n = 1000 * 100;
            int[] pr = PrimesGenerator.getPrimes(101000);

            HashSet<Long> prs = new HashSet<>();
            for (int p : pr) prs.add((long) p);
            HashSet<Long> prs2 = new HashSet<>();
            for (int p : pr) prs2.add((long) p * (long) p);

            HashMap<Long, Integer> d = new HashMap<>();
            HashMap<Long, Long> op = new HashMap<>();
            for (int i = 0; i < n; ++i) {
                long x = in.nextLong();
                //long x = 9999999967L;
                long y = 1, oy = 1;
                if (prs.contains(x)) {
                    y *= x;
                    oy *= x;
                    oy *= x;
                } else if (prs2.contains(x)) {
                    y *= x;
                    long s = (long) Math.sqrt(x) - 3;
                    if (s < 0) s = 0;
                    while (s * s < x) ++s;
                    oy *= s;
                } else {
                    for (int p : pr) {
                        if (p > x) break;
                        if (p > 4000) {
//                        long up = (long)Math.pow(2E10 / x, 2.0 / 3.0) + 10;
//                        if (p > up) break;
                            break;
                        }
                        int c = 0;
                        while (x % p == 0) {
                            x /= p;
                            ++c;
                        }
                        c %= 3;
                        if (c == 0) continue;
                        if (c == 1) {
                            y *= p;
                            oy *= p;
                            if (oy > BUBEN) oy = 0;
                            oy *= p;
                            if (oy > BUBEN) oy = 0;
                        } else {
                            y *= p;
                            y *= p;
                            oy *= p;
                            if (oy > BUBEN) oy = 0;
                        }
                    }
                    if (x != 1) {
                        if (prs.contains(x)) {
                            y *= x;
                            oy *= x;
                            if (oy > BUBEN) oy = 0;
                            oy *= x;
                            if (oy > BUBEN) oy = 0;
                        } else if (prs2.contains(x)) {
                            y *= x;
                            long s = (long) Math.sqrt(x) - 3;
                            if (s < 0) s = 0;
                            while (s * s < x) ++s;
                            oy *= s;
                            if (oy > BUBEN) oy = 0;
                        } else {
                            y *= x;
                            oy = 0;
                        }
                    }
                }


                if (d.containsKey(y)) {
                    d.put(y, d.get(y) + 1);
                } else {
                    d.put(y, 1);
                    op.put(y, oy);
                }
            }

            HashSet<Long> used = new HashSet<>();
            int res = 0;
            for (long x : d.keySet()) {
                if (x == 1) {
                    ++res;
                    continue;
                }
                if (used.contains(x)) continue;
                long ox = op.get(x);
                int val = d.get(x);
                int oval = d.containsKey(ox) ? d.get(ox) : 0;
                res += Math.max(val, oval);
                used.add(x);
                used.add(ox);
            }
            out.printLine(res);
        }

    }

    static class PrimesGenerator {
        public static int[] getPrimes(int n) {
            boolean[] prime = new boolean[n + 1];
            Arrays.fill(prime, 2, n + 1, true);
            for (int i = 2; i * i <= n; i++) {
                if (prime[i]) {
                    for (int j = i * i; j <= n; j += i) {
                        prime[j] = false;
                    }
                }
            }
            int[] primes = new int[n + 1];
            int cnt = 0;
            for (int i = 0; i < prime.length; i++)
                if (prime[i])
                    primes[cnt++] = i;

            return Arrays.copyOf(primes, cnt);
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