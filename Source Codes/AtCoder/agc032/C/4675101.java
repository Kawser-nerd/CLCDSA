import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.Vector;
import java.nio.charset.Charset;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner in = new LightScanner(inputStream);
        LightWriter out = new LightWriter(outputStream);
        CThreeCircuits solver = new CThreeCircuits();
        solver.solve(1, in, out);
        out.close();
    }

    static class CThreeCircuits {
        private static final String YES = "Yes";
        private static final String NO = "No";

        public void solve(int testNumber, LightScanner in, LightWriter out) {
            int n = in.ints(), m = in.ints();
            int[] cnt = new int[n];
            List<List<Integer>> neg = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                neg.add(new ArrayList<>());
            }
            for (int i = 0; i < m; i++) {
                int a = in.ints() - 1, b = in.ints() - 1;
                cnt[a]++;
                neg.get(a).add(b);
                cnt[b]++;
                neg.get(b).add(a);
            }

            int cr = 0;
            boolean[] isCr = new boolean[n];
            boolean flg = false;
            for (int i = 0; i < n; i++) {
                if (cnt[i] % 2 == 1) {
                    out.ansln(NO); //OK
                    return;
                } else if (cnt[i] >= 6) {
                    flg = true;
                } else if (cnt[i] == 4) {
                    cr++;
                    isCr[i] = true;
                }
            }
            if (flg) {
                out.ansln(YES);
                return;
            } else if (cr >= 3) {
                out.ansln(YES);
                return;
            } else if (cr <= 1) {
                out.ansln(NO);
                return;
            }

            boolean[] visited = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (!isCr[i]) {
                    continue;
                }
                Stack<CThreeCircuits.Visit> st = new Stack<>();
                st.add(new CThreeCircuits.Visit(i, 0));
                while (!st.isEmpty()) {
                    CThreeCircuits.Visit p = st.pop();
                    visited[p.dest] = true;
                    for (Integer b : neg.get(p.dest)) {
                        if (b == i && p.depth > 1) {
                            out.ansln(YES);
                            return;
                            //throw new RuntimeException();
                        } else if (isCr[b] || visited[b]) {
                            continue;
                        }
                        st.push(new CThreeCircuits.Visit(b, p.depth + 1));
                    }
                }
            }
            out.ansln(NO);
        }

        private static class Visit {
            int dest;
            int depth;

            public Visit(int dest, int depth) {
                this.dest = dest;
                this.depth = depth;
            }

        }

    }

    static class LightWriter implements AutoCloseable {
        private final Writer out;
        private boolean autoflush = false;
        private boolean breaked = true;

        public LightWriter(Writer out) {
            this.out = out;
        }

        public LightWriter(OutputStream out) {
            this(new BufferedWriter(new OutputStreamWriter(out, Charset.defaultCharset())));
        }

        public LightWriter print(char c) {
            try {
                out.write(c);
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter print(String s) {
            try {
                out.write(s, 0, s.length());
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter ans(String s) {
            if (!breaked) {
                print(' ');
            }
            return print(s);
        }

        public LightWriter ansln(String... n) {
            for (String n1 : n) {
                ans(n1).ln();
            }
            return this;
        }

        public LightWriter ln() {
            print(System.lineSeparator());
            breaked = true;
            if (autoflush) {
                try {
                    out.flush();
                } catch (IOException ex) {
                    throw new UncheckedIOException(ex);
                }
            }
            return this;
        }

        public void close() {
            try {
                out.close();
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int ints() {
            return Integer.parseInt(string());
        }

    }
}