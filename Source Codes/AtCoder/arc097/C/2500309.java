import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.Reader;
import java.io.InputStreamReader;
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
        MyInput in = new MyInput(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        BIT bit;
        int n;
        int[] c;
        int[] a;
        int[][] pos;
        int[][] memo;

        public void solve(int testNumber, MyInput in, PrintWriter out) {
            n = in.nextInt() * 2;
            c = new int[n];
            a = new int[n];
            pos = new int[2][n + 1];
            for (int i = 0; i < n; i++) {
                c[i] = in.nextChars()[0] == 'B' ? 0 : 1;
                a[i] = in.nextInt();
                pos[c[i]][a[i]] = i + 1;
            }
            TreeSet<Integer> black = new TreeSet<>();
            TreeSet<Integer> white = new TreeSet<>();
            int ans = 0;
//        for (int i = 0; i < n; i++) {
//            black.clear();
//            white.clear();
//            for (int j = 0; j < n; j++) {
//                if (c[j] == 0) {
//                    if (black.higher(a[j]) != null) {
//                        swap(c, a, j, j - 1);
//                        ans++;
//                    }
//                    black.add(a[j]);
//                } else {
//                    if (white.higher(a[j]) != null) {
//                        swap(c, a, j, j - 1);
//                        ans++;
//                    }
//                    white.add(a[j]);
////                    dump(i, j, c[j], a[j]);
//                }
//            }
//            dump(i, c, a);
//        }
//        if (true) {
//            out.println(ans);
//            return;
//        }

            bit = new BIT(n + 10);
            memo = new int[n + 1][n + 1];
            for (int[] m : memo) Arrays.fill(m, -1);

            out.println(rec(n / 2, n / 2));
        }

        int rec(int w, int b) {
            int i = w + b;
            if (i == 0) return 0;
            if (memo[w][b] >= 0) return memo[w][b];
            int ans = Integer.MAX_VALUE;
            if (w > 0) {
//            dump(1, w, pos[1][w]);
                bit.add(pos[1][w], 1);
                ans = Math.min(ans, rec(w - 1, b) + bit.sum(pos[1][w] - 1));
                bit.add(pos[1][w], -1);
            }
            if (b > 0) {
                bit.add(pos[0][b], 1);
                ans = Math.min(ans, rec(w, b - 1) + bit.sum(pos[0][b] - 1));
                bit.add(pos[0][b], -1);
            }
            return memo[w][b] = ans;
        }

        class BIT {
            final int n;
            final int[] bit;

            public BIT(int size) {
                n = size;
                bit = new int[n + 1];
            }

            public int sum(int i) {
                int res = 0;
                for (; i > 0; i -= i & -i) {
                    res += bit[i];
                }
                return res;
            }

            public void add(int i, int x) {
                if (i == 0) throw new RuntimeException();
                for (; i <= n; i += i & -i) {
                    bit[i] += x;
                }
            }

        }

    }

    static class MyInput {
        private final BufferedReader in;
        private static int pos;
        private static int readLen;
        private static final char[] buffer = new char[1024 * 8];
        private static char[] str = new char[500 * 8 * 2];
        private static boolean[] isDigit = new boolean[256];
        private static boolean[] isSpace = new boolean[256];
        private static boolean[] isLineSep = new boolean[256];

        static {
            for (int i = 0; i < 10; i++) {
                isDigit['0' + i] = true;
            }
            isDigit['-'] = true;
            isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
            isLineSep['\r'] = isLineSep['\n'] = true;
        }

        public MyInput(InputStream is) {
            in = new BufferedReader(new InputStreamReader(is));
        }

        public int read() {
            if (pos >= readLen) {
                pos = 0;
                try {
                    readLen = in.read(buffer);
                } catch (IOException e) {
                    throw new RuntimeException();
                }
                if (readLen <= 0) {
                    throw new MyInput.EndOfFileRuntimeException();
                }
            }
            return buffer[pos++];
        }

        public int nextInt() {
            int len = 0;
            str[len++] = nextChar();
            len = reads(len, isSpace);
            int i = 0;
            int ret = 0;
            if (str[0] == '-') {
                i = 1;
            }
            for (; i < len; i++) ret = ret * 10 + str[i] - '0';
            if (str[0] == '-') {
                ret = -ret;
            }
            return ret;
        }

        public char nextChar() {
            while (true) {
                final int c = read();
                if (!isSpace[c]) {
                    return (char) c;
                }
            }
        }

        int reads(int len, boolean[] accept) {
            try {
                while (true) {
                    final int c = read();
                    if (accept[c]) {
                        break;
                    }
                    if (str.length == len) {
                        char[] rep = new char[str.length * 3 / 2];
                        System.arraycopy(str, 0, rep, 0, str.length);
                        str = rep;
                    }
                    str[len++] = (char) c;
                }
            } catch (MyInput.EndOfFileRuntimeException e) {
            }
            return len;
        }

        public char[] nextChars() {
            int len = 0;
            str[len++] = nextChar();
            len = reads(len, isSpace);
            return Arrays.copyOf(str, len);
        }

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }
}