import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        arc099_c solver = new arc099_c();
        solver.solve(1, in, out);
        out.close();
    }

    static class arc099_c {
        int inf = 100000000;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();

            int m = in.nextInt();

            Set[] g = new Set[n];

            for (int i = 0; i < n; i++) {
                g[i] = new HashSet();
            }

            int[] u = new int[m];
            int[] v = new int[m];
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    g[i].add(j);
                    g[j].add(i);
                }
            }

            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;

                u[i] = a;
                v[i] = b;

                g[a].remove(b);
                g[b].remove(a);
            }

            IsBipartite isb = new IsBipartite(g);

            List<cp> cps = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (!isb.vis[i]) {
                    boolean isBipar = isb.isBipartite(i);
                    if (!isBipar) {
                        out.println(-1);
                        return;
                    }
                    isb.oneColorNodes = 0;
                    isb.zeroColorNodes = 0;
                    isb.assign2Colors(i);
                    cps.add(new cp(isb.oneColorNodes, isb.zeroColorNodes));
                }
            }

            boolean[][] dp = new boolean[cps.size()][n + 1];

            dp[0][cps.get(0).o] = true;
            dp[0][cps.get(0).z] = true;

            for (int i = 1; i < cps.size(); i++) {
                cp ccp = cps.get(i);
                for (int j = 0; j <= n; j++) {
                    if (j >= ccp.o) {
                        dp[i][j] |= dp[i - 1][j - ccp.o];
                    }
                    if (j >= ccp.z) {
                        dp[i][j] |= dp[i - 1][j - ccp.z];
                    }
                }
            }

            int ans = inf;
            for (int i = 0; i <= n; i++) {
                if (dp[cps.size() - 1][i]) {
                    int s1 = i;
                    int s2 = n - i;

                    ans = Math.min(ans, cs(s1) + cs(s2));
                }
            }

            if (ans == inf) {
                out.println(-1);
                return;
            }

            out.println(ans);
        }

        int cs(int i) {
            return (i * (i - 1)) / 2;
        }

        class IsBipartite {
            Set[] g;
            int n;
            boolean[] vis;
            boolean[] colorVis;
            int[] level;
            int[] color;
            int zeroColorNodes = 0;
            int oneColorNodes = 0;

            public IsBipartite(Set[] g) {
                this.g = g;
                this.n = g.length;
                this.vis = new boolean[n];
                this.level = new int[n];
                this.color = new int[n];
                this.colorVis = new boolean[n];
            }

            boolean isBipartite(int u) {
                ArrayDeque<Integer> queue = new ArrayDeque<>();

                queue.addLast(u);
                vis[u] = true;
                level[u] = 0;

                while (queue.size() > 0) {
                    int front = queue.removeFirst();

                    for (int v : (Set<Integer>) g[front]) {
                        if (vis[v]) {
                            if (level[v] == level[front]) {
                                return false;
                            }
                        } else {
                            queue.addLast(v);
                            vis[v] = true;
                            level[v] = level[front] + 1;
                        }
                    }
                }

                return true;
            }

            void assign2Colors(int u) {
                dfs(u, -1);
            }

            void dfs(int u, int prevColor) {
                if (prevColor == -1) {
                    color[u] = 0;
                } else {
                    color[u] = 1 - prevColor;
                }

                if (color[u] == 0)
                    zeroColorNodes++;
                else
                    oneColorNodes++;

                colorVis[u] = true;

                for (int v : (Set<Integer>) g[u]) {
                    if (!colorVis[v])
                        dfs(v, color[u]);
                }
            }

        }

        class cp {
            int o;
            int z;

            public cp(int o, int z) {
                this.o = o;
                this.z = z;
            }

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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.