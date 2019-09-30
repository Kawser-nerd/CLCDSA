import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.Reader;
import java.util.ArrayDeque;
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
        public void solve(int testNumber, MyInput in, PrintWriter out) {
            char[] cs = in.nextChars();
            int n = cs.length;

            int[] cnt = new int[26];
            for (char c : cs) cnt[c - 'a']++;
            int odd = 0;
            for (int c : cnt) odd += c % 2;
            if (odd != n % 2) {
                out.println(-1);
                return;
            }
            Seg1 seg = new Seg1(n);
            ArrayDeque<Integer>[] deq = new ArrayDeque[26];
            for (int i = 0; i < deq.length; i++) deq[i] = new ArrayDeque<>();
            for (int i = 0; i < n; i++) deq[cs[i] - 'a'].add(i);
            long ans = 0;
            for (int i = 0; i < n / 2; i++) {
                int idx = -1;
                int cost = Integer.MAX_VALUE;
                for (int j = 0; j < deq.length; j++)
                    if (deq[j].size() >= 2) {
                        int l = seg.get(deq[j].peekFirst());
                        int r = seg.get(deq[j].peekLast());
                        if (cost > l - i + n - 1 - i - r) {
                            cost = l - i + n - 1 - i - r;
                            idx = j;
                        }
                    }
                seg.add(0, deq[idx].pollFirst(), 1);
                seg.add(deq[idx].pollLast(), n, -1);
                ans += cost;
            }
            out.println(ans);
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

    static class Seg1 {
        final int n;
        final int[] seg;

        public Seg1(final int n) {
            this.n = Integer.highestOneBit(n) << 1;
            seg = new int[this.n << 1];
            for (int i = 0; i < n; i++) {
                seg[i + this.n - 1] = i;
            }
        }

        void add(int l, int r, int v) {
            add(l, r, v, 0, 0, n);
        }

        void add(int l, int r, int v, int k, int curL, int curR) {
            if (curR <= l || curL >= r) return;
            if (l <= curL && curR <= r) {
                seg[k] += v;
                return;
            }
            final int curM = (curL + curR) / 2;
            add(l, r, v, 2 * k + 1, curL, curM);
            add(l, r, v, 2 * k + 2, curM, curR);
        }

        int get(int i) {
            i += n - 1;
            int ret = seg[i];
            while (i != 0) {
                i = (i - 1) / 2;
                ret += seg[i];
            }
            return ret;
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.