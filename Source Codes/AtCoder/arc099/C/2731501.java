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
        int n;
        int m;
        boolean[][] con;
        int[] color;
        UnionFind uf;

        public void solve(int testNumber, MyInput in, PrintWriter out) {
//        if (true) { test(); return; }
            n = in.nextInt();
            m = in.nextInt();
            int[][] es = new int[m][];

            for (int i = 0; i < m; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                es[i] = new int[]{a, b};
            }
            out.println(solve(es));
        }

        int solve(int[][] es) {
            uf = new UnionFind(n);
            con = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    con[i][j] = true;
                }
                con[i][i] = false;
            }

            for (int i = 0; i < m; i++) {
                int a = es[i][0] - 1;
                int b = es[i][1] - 1;
                con[a][b] = con[b][a] = false;
            }
            color = new int[n];
            for (int i = 0; i < n; i++)
                if (color[i] == 0) {
                    if (!dfs(i, 1)) {
                        return -1;
                    }
                }

            int[] cnt = new int[n];
            for (int i = 0; i < n; i++)
                if (color[i] == 1) {
                    cnt[uf.root(i)]++;
                }

            boolean[] dp = new boolean[n + 1];
            dp[0] = true;
            for (int i = 0; i < n; i++)
                if (uf.root(i) == i) {
//            dump(i, cnt[i], uf.size(i));
                    final int c1 = cnt[i];
                    final int c2 = uf.size(i) - cnt[i];
                    boolean[] dp2 = new boolean[n + 1];
                    for (int j = n; j >= 0; j--) {
                        if (j - c1 >= 0) dp2[j] |= dp[j - c1];
                        if (j - c2 >= 0) dp2[j] |= dp[j - c2];
                    }
                    dp = dp2;
                }

            int ans = Integer.MAX_VALUE;
            for (int i = 0; i <= n; i++)
                if (dp[i]) {
//            dump(i);
                    ans = Math.min(ans, i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
                }
            return ans;
        }

        boolean dfs(int v, int c) {
            if (color[v] != 0) {
                if (color[v] != c) return false;
                return true;
            }
            color[v] = c;
            for (int i = 0; i < n; i++)
                if (con[v][i]) {
                    uf.union(v, i);
                    if (!dfs(i, -c)) return false;
                }
            return true;
        }

        class UnionFind {
            private int[] data;

            public UnionFind(int size) {
                data = new int[size];
                clear();
            }

            public void clear() {
                Arrays.fill(data, -1);
            }

            public int root(int x) {
                return data[x] < 0 ? x : (data[x] = root(data[x]));
            }

            public void union(int x, int y) {
                if ((x = root(x)) != (y = root(y))) {
                    if (data[y] < data[x]) {
                        final int t = x;
                        x = y;
                        y = t;
                    }
                    data[x] += data[y];
                    data[y] = x;
                }
            }

            public int size(int x) {
                return -data[root(x)];
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

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }
}