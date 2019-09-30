import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.io.IOException;
import java.util.Comparator;
import java.util.Collections;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int r = in.nextInt(), c = in.nextInt(), n = in.nextInt();

            List<Segment> a = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                int x1 = in.nextInt(), y1 = in.nextInt();
                int x2 = in.nextInt(), y2 = in.nextInt();

                int left = calcPos(r, c, x1, y1);
                int right = calcPos(r, c, x2, y2);
                if (left != -1 && right != -1) {
                    if (left > right) {
                        int aux = left;
                        left = right;
                        right = aux;
                    }
                    a.add(new Segment(left, right));
                }
            }
            Collections.sort(a, Comparator.comparingInt(o -> o.right));
            List<Segment> stk = new ArrayList<>();
            for (Segment e : a) {
                while (!stk.isEmpty() && e.left < stk.get(stk.size() - 1).right) {
                    Segment s = stk.get(stk.size() - 1);
                    stk.remove(stk.size() - 1);
                    if (s.left < e.left) {
                        out.println("NO");
                        return;
                    }
                }
                stk.add(e);
            }
            out.println("YES");
        }

        private int calcPos(int r, int c, int x, int y) {
            if (y == 0) {
                return x;
            } else if (x == r) {
                return r + y;
            } else if (y == c) {
                return r + c + (r - x);
            } else if (x == 0) {
                return r + c + r + (c - y);
            } else {
                return -1;
            }
        }

        private class Segment {
            int left;
            int right;

            Segment(int left, int right) {
                this.left = left;
                this.right = right;
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}