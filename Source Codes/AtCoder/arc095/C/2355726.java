import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.Reader;
import java.io.InputStreamReader;
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
        int w;
        int h;
        char[][] cs;
        int[][] p = new int[6][2];

        public void solve(int testNumber, MyInput in, PrintWriter out) {
            h = in.nextInt();
            w = in.nextInt();
            cs = new char[h][];
            for (int y = 0; y < h; y++) {
                cs[y] = in.nextChars();
            }

            out.println(rec(0) ? "YES" : "NO");
        }

        boolean rec(int bitY) {
            int idx = Integer.bitCount(bitY) / 2;
            if (h % 2 == 1 && Integer.bitCount(bitY) == h - 1) {
                for (int y0 = 0; y0 < h; y0++)
                    if ((bitY >>> y0 & 1) == 0) {
                        p[idx][0] = p[idx][1] = y0;
                        bitY |= 1 << y0;
                        break;
                    }
            }
            if (Integer.bitCount(bitY) == h) {
                return check();
            }
            int cnt = 0;
            for (int y0 = 0; y0 < h && cnt < 2; y0++)
                if ((bitY >>> y0 & 1) == 0) {
                    for (int y1 = y0 + 1; y1 < h; y1++)
                        if ((bitY >>> y1 & 1) == 0) {
                            p[idx][0] = y0;
                            p[idx][1] = y1;
                            if (rec(bitY | 1 << y0 | 1 << y1)) {
                                return true;
                            }
                        }
                    cnt++;
                }
            return false;
        }

        boolean check() {
            int len = (h + 1) / 2;
            int matched = 0;
            for (int j = 0; j < w; j++)
                if ((matched >>> j & 1) == 0) {
                    for (int k = j + 1; k < w; k++)
                        if ((matched >>> k & 1) == 0) {
                            boolean ok = true;
                            for (int i = 0; i < len; i++) {
                                if (!(cs[p[i][0]][j] == cs[p[i][1]][k] && cs[p[i][0]][k] == cs[p[i][1]][j])) {
                                    ok = false;
                                    break;
                                }
                            }
                            if (ok) {
                                matched |= 1 << j | 1 << k;
                                break;
                            }
                        }
                }
//        dump(matched, p, len);
            if (w % 2 == 1 && Integer.bitCount(matched) == w - 1) {
                for (int j = 0; j < w; j++)
                    if ((matched >>> j & 1) == 0) {
                        boolean ok = true;
                        for (int i = 0; i < len; i++) {
                            if (!(cs[p[i][0]][j] == cs[p[i][1]][j] && cs[p[i][0]][j] == cs[p[i][1]][j])) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok) {
                            matched |= 1 << j;
                            break;
                        }
                    }
            }
            return Integer.bitCount(matched) == w;
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