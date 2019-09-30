import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int n;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();
            if (Integer.bitCount(a ^ b) % 2 == 0) {
                out.printLine("NO");
                return;
            }
            out.printLine("YES");
            ArrayList<ii> bits = new ArrayList<>();
            for (int i = 0; i < n; ++i)
                bits.add(new ii(((a ^ b) >> i) % 2, i));
            Collections.sort(bits);
            int[] p = new int[n], ip = new int[n];
            for (int i = 0; i < bits.size(); ++i) {
                p[i] = bits.get(i).second;
                ip[p[i]] = i;
            }
//        System.err.println(String.format("%s %s", Integer.toBinaryString(apply(a, p)), Integer.toBinaryString(apply(b, p))));
            ArrayList<Integer> res = calc(apply(a, p), apply(b, p), n);
            Assert.assertTrue(res.size() == (1 << n));
            Assert.assertTrue(check(res));
            for (int x : res)
                out.print(apply(x, ip) + " ");
            out.printLine();
        }

        private boolean check(ArrayList<Integer> res) {
            for (int i = 0; i + 1 < res.size(); ++i)
                if (Integer.bitCount(res.get(i) ^ res.get(i + 1)) != 1)
                    return false;
            return true;
        }

        private int apply(int a, int[] p) {
            int res = 0;
            for (int i = 0; i < n; ++i)
                res |= ((a >> p[i]) % 2) << i;
            return res;
        }

        private ArrayList<Integer> calc(int a, int b, int n) {
//        System.err.println(n + ": " + Integer.toBinaryString(a) + " " + Integer.toBinaryString(b));
            if (n == 1) {
                Assert.assertTrue(a != b);
                ArrayList<Integer> res = new ArrayList<>();
                res.add(a);
                res.add(b);
                return res;
            }
            if (a % 2 == b % 2) {
                ArrayList<Integer> path = calc(a / 2, b / 2, n - 1);
                Assert.assertTrue(path.size() % 2 == 0);
                ArrayList<Integer> res = new ArrayList<>();
                int zero = a % 2;
                int one = 1 - zero;
                for (int i = 0; i < path.size(); i += 2) {
                    int x = path.get(i);
                    int y = path.get(i + 1);
                    res.add(x * 2 + zero);
                    res.add(x * 2 + one);
                    res.add(y * 2 + one);
                    res.add(y * 2 + zero);
                }
                Assert.assertTrue(res.get(0) == a);
                Assert.assertTrue(res.get(res.size() - 1) == b);
                return res;
            }
            Assert.assertTrue(n >= 3);
            ArrayList<Integer> path = calc(a / 4, b / 4, n - 2);
            Assert.assertTrue(path.size() % 2 == 0);
            ArrayList<Integer> res = new ArrayList<>();
            int start = a & 3, finish = b & 3;
            Assert.assertTrue(start == (3 ^ finish));
            for (int i = 0; i < path.size(); i += 2) {
                int x = path.get(i);
                int y = path.get(i + 1);
                if (i == 0) {
                    res.add(x * 4 + (start ^ 0));
                    res.add(x * 4 + (start ^ 1));
                    res.add(x * 4 + (start ^ 3));
                    res.add(x * 4 + (start ^ 2));
                } else {
                    res.add(x * 4 + (start ^ 3));
                    res.add(x * 4 + (start ^ 1));
                    res.add(x * 4 + (start ^ 0));
                    res.add(x * 4 + (start ^ 2));
                }
                res.add(y * 4 + (start ^ 2));
                res.add(y * 4 + (start ^ 0));
                res.add(y * 4 + (start ^ 1));
                res.add(y * 4 + (start ^ 3));
            }
            Assert.assertTrue(res.get(0) == a);
            Assert.assertTrue(res.get(res.size() - 1) == b);
            return res;
        }

    }

    static class Assert {
        public static void assertTrue(boolean flag) {
//        if (!flag)
//        while (true);
            if (!flag)
                throw new AssertionError();
        }

    }

    static class ii implements Comparable<ii> {
        public int first;
        public int second;

        public ii() {
        }

        public ii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            ii ii = (ii) o;

            if (first != ii.first) return false;
            if (second != ii.second) return false;

            return true;
        }

        public int hashCode() {
            int result = first;
            result = 31 * result + second;
            return result;
        }

        public int compareTo(ii o) {
            if (first != o.first) {
                return first < o.first ? -1 : 1;
            }
            if (second != o.second) {
                return second < o.second ? -1 : 1;
            }
            return 0;
        }


        public String toString() {
            return "{" +
                    "first=" + first +
                    ", second=" + second +
                    '}';
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

    }
}