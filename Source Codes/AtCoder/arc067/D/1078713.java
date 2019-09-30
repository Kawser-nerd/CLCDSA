import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.LinkedList;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Xi Lin
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
        static int N = 50000 + 10;
        static long[] mx = new long[N * 4];
        static long[] tag = new long[N * 4];

        void push(int rt) {
            if (tag[rt] != 0) {
                tag[lson(rt)] += tag[rt];
                tag[rson(rt)] += tag[rt];
                mx[lson(rt)] += tag[rt];
                mx[rson(rt)] += tag[rt];
                tag[rt] = 0;
            }
        }

        int lson(int x) {
            return x << 1;
        }

        int rson(int x) {
            return x << 1 | 1;
        }

        void modify(int rt, int l, int r, int L, int R, long v) {
            if (R < l || L > r) return;
            if (L <= l && R >= r) {
                mx[rt] += v;
                tag[rt] += v;
                return;
            }
            push(rt);
            int mid = (l + r) >> 1;
            modify(lson(rt), l, mid, L, R, v);
            modify(rson(rt), mid + 1, r, L, R, v);
            mx[rt] = max(mx[lson(rt)], mx[rson(rt)]);
        }

        long ask(int rt, int l, int r, int L, int R) {
            if (R < l || L > r) return 0;
            if (L <= l && R >= r) return mx[rt];
            push(rt);
            int mid = (l + r) >> 1;
            return max(ask(lson(rt), l, mid, L, R), ask(rson(rt), mid + 1, r, L, R));
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            long A[] = new long[n - 1];
            for (int i = 0; i < n - 1; ++i) {
                A[i] = in.nextInt();
            }
            LinkedList<W>[] queue = new LinkedList[m];
            for (int i = 0; i < m; ++i) {
                queue[i] = new LinkedList<W>();
                queue[i].add(new W((int) (1e9 + 10), -1));
            }
            int B[] = new int[m];
            long ret = 0;
            for (int i = 0; i < n; ++i) {
                long total = 0;
                for (int j = 0; j < m; ++j) {
                    B[j] = in.nextInt();
                    total += B[j];
                }
                ret = max(ret, total);
                for (int j = 0; j < m; ++j) {
                    while (B[j] >= queue[j].getLast().val) {
                        //out.printf("%d ", queue[j].size());
                        W e = queue[j].pollLast();
                        //queue[j].size();
                        //out.printf("%d\n", queue[j].size());
                        modify(1, 0, n - 1, queue[j].getLast().idx + 1, e.idx, -e.val);
                    }
                    modify(1, 0, n - 1, queue[j].getLast().idx + 1, i, B[j]);
                    queue[j].add(new W(B[j], i));
                }
                if (i > 0) {
                    modify(1, 0, n - 1, 0, i - 1, -A[i - 1]);
                }
                ret = max(ret, ask(1, 0, n - 1, 0, i));

            }
            out.println(ret);
        }

        long max(long a, long b) {
            if (a > b) return a;
            else return b;
        }

        class W {
            int val;
            int idx;

            public W(int _v, int _i) {
                val = _v;
                idx = _i;
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.