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
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author prakharjain
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        CLexicographicConstraints solver = new CLexicographicConstraints();
        solver.solve(1, in, out);
        out.close();
    }

    static class CLexicographicConstraints {
        int max = 1_000_000_000;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();

            int[] a = in.nextIntArray(n);

            int lo = 1;
            int hi = n;

            int ans = n;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (isp(a, n, mid)) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            out.println(ans);
        }

        boolean isp(int[] a, int n, int base) {
            ArrayDeque[] segs = new ArrayDeque[n];

            for (int i = 0; i < n; i++) {
                segs[i] = new ArrayDeque<seg>();

            }

            segs[0].add(new seg(0, max - 1, 0));

            for (int i = 1; i < n; i++) {
                if (a[i] > a[i - 1]) {
                    segs[i] = segs[i - 1];
                } else {

                    segs[i] = segs[i - 1];

                    ArrayDeque<seg> pseg = segs[i];

                    if (pseg.size() == 1 && pseg.getFirst().val == base - 1)
                        return false;

                    int tci = a[i] - 1;

                    while (pseg.getLast().l > tci) {
                        pseg.removeLast();
                    }

//                int lo = 0;
//                int hi = pseg.size() - 1;
//
//                int segi = -1;
//                while (lo <= hi) {
//                    int mid = (lo + hi) / 2;
//
//                    seg mseg = pseg.get(mid);
//
//                    if (mseg.l <= tci && mseg.r >= tci) {
//                        segi = mid;
//                        break;
//                    } else if (mseg.r < tci) {
//                        lo = mid + 1;
//                    } else {
//                        hi = mid - 1;
//                    }
//                }

                    seg aseg = pseg.removeLast();

                    if (pseg.isEmpty() && aseg.val == base - 1)
                        return false;

                    if (aseg.val == base - 1) {
                        aseg = pseg.removeLast();
                        tci = aseg.r;
                    }

                    if (tci == aseg.l) {
                        if (!pseg.isEmpty() && pseg.getLast().val == aseg.val + 1) {
                            pseg.getLast().r = aseg.l;
                        } else {
                            segs[i].add(new seg(aseg.l, aseg.l, aseg.val + 1));
                        }
                        if (aseg.l + 1 < max) {
                            segs[i].add(new seg(aseg.l + 1, max - 1, 0));
                        }
                    } else {
                        segs[i].add(new seg(aseg.l, tci - 1, aseg.val));
                        segs[i].add(new seg(tci, tci, aseg.val + 1));
                        if (tci + 1 < max) {
                            segs[i].add(new seg(tci + 1, max - 1, 0));
                        }
                    }
                }
            }

            return true;
        }

        class seg {
            int l;
            int r;
            int val;

            public seg(int l, int r, int val) {
                this.l = l;
                this.r = r;
                this.val = val;
            }

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

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.