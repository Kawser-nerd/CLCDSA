import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.TreeSet;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            Segment[] a = new Segment[n];
            for (int i = 0; i < a.length; ++i) {
                int left = in.nextInt();
                int right = in.nextInt();
                a[i] = new Segment(left, right, i);
            }
            Arrays.sort(a, (o1, o2) -> o1.left - o2.left);
            TreeSet<Segment> s = new TreeSet<>();
            TreeSet<Segment> s2 = new TreeSet<>();
            int ans = 0;
            int last = 1;
            for (Segment e : a) {
                if (last > m) break;
                if (last <= e.left) {
                    s.add(e);
                    last++;
                    ans++;
                } else if (!s.isEmpty()) {
                    Segment v = s.first();
                    if (e.right > v.right) {
                        s.pollFirst();
                        s.add(e);
                        s2.add(v);
                    } else {
                        s2.add(e);
                    }
                } else {
                    s2.add(e);
                }
            }
            int right = m;
            for (Segment e : s2.descendingSet()) {
                if (right < last) {
                    break;
                }
                if (right >= e.right) {
                    ans++;
                    right--;
                }
            }
            out.println(n - ans);

        }

        private class Segment implements Comparable<Segment> {
            int left;
            int right;
            int index;

            Segment(int left, int right) {
                this.left = left;
                this.right = right;
                this.index = -1;
            }

            Segment(int left, int right, int index) {
                this.left = left;
                this.right = right;
                this.index = index;
            }

            public int compareTo(Segment o) {
                if (right != o.right) {
                    return right - o.right;
                } else if (left != o.left) {
                    return left - o.left;
                } else {
                    return index - o.index;
                }
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