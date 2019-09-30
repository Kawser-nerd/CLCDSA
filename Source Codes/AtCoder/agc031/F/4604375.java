import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.Collections;
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
        long mod;
        long[] p2;
        long[] mask;

        long gcd(long a, long b) {
            while (b > 0) {
                long t = a % b;
                a = b;
                b = t;
            }
            return a;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int q = in.nextInt();
            mod = in.nextLong();
            Vertex[] v1s = new Vertex[n];
            Vertex[] v2s = new Vertex[n];
            List<Vertex> all = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                v1s[i] = new Vertex();
                v2s[i] = new Vertex();
                all.add(v1s[i]);
                all.add(v2s[i]);
            }
            for (int i = 0; i < m; ++i) {
                int ia = in.nextInt() - 1;
                int ib = in.nextInt() - 1;
                long c = in.nextLong();
                v1s[ia].adj.add(new Edge(v2s[ib], c));
                v1s[ib].adj.add(new Edge(v2s[ia], c));
                v2s[ia].adj.add(new Edge(v1s[ib], c));
                v2s[ib].adj.add(new Edge(v1s[ia], c));
            }
            {
                p2 = new long[(int) (mod + 10)];
                p2[0] = 1;
                int cnt = 1;
                while (true) {
                    long nxt = (p2[cnt - 1] * 2);
                    if (nxt >= mod) nxt -= mod;
                    if (nxt == 1) break;
                    p2[cnt++] = nxt;
                }
                p2 = Arrays.copyOf(p2, cnt);
                if (cnt % 2 != 0) throw new RuntimeException();
            }
            v1s[0].init(0, 0, 0);
            long someVal = v1s[0].adj.isEmpty() ? 0 : v1s[0].adj.get(0).val;
            long loopGcd = mod;
            long[] extras = new long[p2.length + 1];
            for (int i = p2.length - 2; i >= 0; i -= 2) {
                extras[i] = (extras[i + 2] + someVal * (p2[i] + p2[i + 1])) % mod;
            }
            if (extras[0] != 0) throw new RuntimeException();

            for (Vertex src : all)
                if (src.depth >= 0) {
                    for (Edge e : src.adj) {
                        Vertex dst = e.dest;
                        long cost = (src.valFromRoot + e.val * p2[src.depth % p2.length] + dst.valToRoot * p2[(src.depth + 1) % p2.length]) % mod;
                        int len = (src.depth + 1 + dst.depth) % p2.length;
                        if (len % 2 != 0) throw new RuntimeException();
                        cost += extras[len];
                        loopGcd = gcd(loopGcd, cost);
                    }
                }
            mask = new long[(int) ((loopGcd + 63) >> 6)];

            List<Test> tests = new ArrayList<>();
            boolean[] answers = new boolean[q];
            for (int qi = 0; qi < q; ++qi) {
                int ia = in.nextInt() - 1;
                int ib = in.nextInt() - 1;
                long need = in.nextLong();
                for (int ja = 0; ja < 2; ++ja) {
                    Vertex a = ja == 0 ? v1s[ia] : v2s[ia];
                    if (a.depth < 0) continue;
                    for (int jb = 0; jb < 2; ++jb) {
                        Vertex b = jb == 0 ? v1s[ib] : v2s[ib];
                        if (b.depth < 0) continue;
                        long before = a.valToRoot % loopGcd;
                        long mulBy = p2[a.depth % p2.length] % loopGcd;
                        long after = b.valFromRoot % loopGcd;
                        long left = mulBy * (after + someVal) % loopGcd;
                        long right = ((need - before + mulBy * someVal) % loopGcd + loopGcd) % loopGcd;
                        long g = gcd(left, loopGcd);
                        if (right % g == 0) {
                            left /= g;
                            right /= g;
                            long curMod = loopGcd / g;
                            long toCheck = right * BigInteger.valueOf(left).modInverse(BigInteger.valueOf(curMod)).longValue() % curMod;
                            if (curMod == 1)
                                answers[qi] = true;
                            else
                                tests.add(new Test((int) curMod, (int) toCheck, qi));
                        /*long tmp = left;
                        do {
                            if (tmp == right) {
                                out.println("YES");
                                continue queryLoop;
                            }
                            tmp = tmp * 4 % loopGcd;
                        } while (tmp != left);*/
                        }
                    }
                }
            }

            Collections.sort(tests, new Comparator<Test>() {

                public int compare(Test o1, Test o2) {
                    return o1.curMod - o2.curMod;
                }
            });
            for (int pos = 0; pos < tests.size(); ) {
                int curMod = tests.get(pos).curMod;
                int j = pos;
                while (j < tests.size() && tests.get(j).curMod == curMod) ++j;

                int count = j - pos;
                int each = (int) (Math.floor(Math.sqrt((double) curMod / count)) + 1);
                int reps = (curMod + each - 1) / each;
                long p4 = 1;
                for (int i = 0; i < each; ++i) {
                    p4 = p4 * 4 % curMod;
                }
                long prod = 1;
                for (int i = 0; i < reps; ++i) {
                    mask[(int) (prod >> 6)] |= (1L << (prod & 63));
                    prod = prod * p4 % curMod;
                }
                for (int at = pos; at < j; ++at) {
                    prod = tests.get(at).toCheck;
                    for (int i = 0; i < each; ++i) {
                        if ((mask[(int) (prod >> 6)] & (1L << (prod & 63))) != 0) {
                            answers[tests.get(at).queryId] = true;
                            break;
                        }
                        prod = prod * 4 % curMod;
                    }
                }
                prod = 1;
                for (int i = 0; i < reps; ++i) {
                    mask[(int) (prod >> 6)] &= ~(1L << (prod & 63));
                    prod = prod * p4 % curMod;
                }

                pos = j;
            }
            for (boolean x : answers)
                if (x) out.println("YES");
                else out.println("NO");
        }

        class Edge {
            Vertex dest;
            long val;

            public Edge(Vertex dest, long val) {
                this.dest = dest;
                this.val = val;
            }

        }

        class Test {
            int curMod;
            int toCheck;
            int queryId;

            public Test(int curMod, int toCheck, int queryId) {
                this.curMod = curMod;
                this.toCheck = toCheck;
                this.queryId = queryId;
            }

        }

        class Vertex {
            long valToRoot;
            long valFromRoot;
            int depth = -1;
            List<Edge> adj = new ArrayList<Edge>();

            public void init(int depth, long valToRoot, long valFromRoot) {
                this.depth = depth;
                this.valToRoot = valToRoot;
                this.valFromRoot = valFromRoot;
                for (Edge e : adj)
                    if (e.dest.depth < 0) {
                        e.dest.init(depth + 1, (e.val + 2 * valToRoot) % mod, (valFromRoot + e.val * p2[depth % p2.length]) % mod);
                    }
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}