import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashSet;
import java.util.Objects;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        agc014a solver = new agc014a();
        solver.solve(1, in, out);
        out.close();
    }

    static class agc014a {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();

//        if (a == b && b == c) {
//            out.println(-1);
//            return;
//        }

            Set<trip> trips = new HashSet<>();
            trips.add(new trip(a, b, c));

            int ans = 0;
            while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
                int ha = a / 2;
                int hb = b / 2;
                int hc = c / 2;

                a = hb + hc;
                b = ha + hc;
                c = ha + hb;

                if (trips.contains(new trip(a, b, c))) {
                    out.println(-1);
                    return;
                }

                ans++;
                trips.add(new trip(a, b, c));
            }

            out.println(ans);
        }

        class trip {
            int a;
            int b;
            int c;

            public trip(int a, int b, int c) {
                this.a = a;
                this.b = b;
                this.c = c;
            }


            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                trip trip = (trip) o;
                return a == trip.a &&
                        b == trip.b &&
                        c == trip.c;
            }


            public int hashCode() {

                return Objects.hash(a, b, c);
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

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}