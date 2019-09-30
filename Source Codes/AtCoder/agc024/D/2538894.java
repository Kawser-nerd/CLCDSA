import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.Reader;
import java.io.InputStreamReader;
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
        MyInput in = new MyInput(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        List<Integer>[] g;

        public void solve(int testNumber, MyInput in, PrintWriter out) {
            int n = in.nextInt();
            g = new List[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<>();
            }

            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                g[a].add(b);
                g[b].add(a);
            }

            IsoTreeNode ans = null;
            for (int i = 0; i < n; i++) {
                ans = minTree(ans, dfs(i, -1));
            }

            for (int i = 0; i < n; i++) {
                for (int t : g[i])
                    if (i < t) {
                        IsoTreeNode x = merge(dfs(i, t), dfs(t, i));
                        x.leaf *= 2;
                        ans = minTree(ans, x);
                    }
            }

            out.println(ans.color + " " + ans.leaf);
        }

        IsoTreeNode dfs(int v, int p) {
            IsoTreeNode m = null;
            for (int t : g[v])
                if (t != p) {
                    m = merge(m, dfs(t, v));
                }
            IsoTreeNode res = new IsoTreeNode();
            res.color = (m == null ? 1 : m.color + 1);
            res.child = m;
            res.branch = g[v].size() - (p == -1 ? 0 : 1);
            res.leaf = (m == null ? 1 : m.leaf * res.branch);
            return res;
        }

        IsoTreeNode minTree(IsoTreeNode a, IsoTreeNode b) {
            if (a == null) return b;
            if (b == null) return a;
            if (a.color != b.color) return a.color < b.color ? a : b;
            return a.leaf < b.leaf ? a : b;
        }

        IsoTreeNode merge(IsoTreeNode a, IsoTreeNode b) {
            if (a == null && b == null) return null;
            if (a == null) {
                a = b;
                b = null;
            }
            if (b == null) {
                return a;
            }

            IsoTreeNode res = new IsoTreeNode();
            res.child = merge(a.child, b.child);
            res.branch = Math.max(a.branch, b.branch);
            res.leaf = (res.child == null ? 1 : res.child.leaf * res.branch);
            res.color = (res.child == null ? 1 : res.child.color + 1);
            return res;
        }

        class IsoTreeNode {
            IsoTreeNode child;
            long branch;
            long color;
            long leaf;

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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.