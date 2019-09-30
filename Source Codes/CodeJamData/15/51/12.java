import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    ArrayList<Integer>[] ch;

    class P {
        int id;
        long s;
        long mins;
        long maxs;

        public P(int id, long s, long mins, long maxs) {
            this.id = id;
            this.s = s;
            this.mins = mins;
            this.maxs = maxs;
        }
    }

    P[] p;

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            int n = in.nextInt();
            long d = in.nextInt();
            ch = new ArrayList[n];
            long[] s = new long[n];
            p = new P[n];
            s[0] = in.nextInt();
            p[0] = new P(0, s[0], s[0], s[0]);
            long as = in.nextInt();
            long cs = in.nextInt();
            long rs = in.nextInt();
            int[] m = new int[n];
            m[0] = in.nextInt();
            int am = in.nextInt();
            int cm = in.nextInt();
            int rm = in.nextInt();
            for (int i = 1; i < n; i++) {
                s[i] = (s[i - 1] * as + cs) % rs;
                m[i] = (m[i - 1] * am + cm) % rm;
                int par = m[i] % i;
                p[i] = new P(i, s[i], Math.min(s[i], p[par].mins), Math.max(s[i], p[par].maxs));
            }

            TreeSet<P> cur = new TreeSet<P>(new Comparator<P>() {
                @Override
                public int compare(P o1, P o2) {
                    int v = Long.compare(o1.mins, o2.mins);
                    return v == 0 ? o1.id - o2.id : v;
                }
            });
            P[] q = p.clone();
            Arrays.sort(p, new Comparator<P>() {
                @Override
                public int compare(P o1, P o2) {
                    return Long.compare(o1.mins, o2.mins);
                }
            });
            Arrays.sort(q, new Comparator<P>() {
                @Override
                public int compare(P o1, P o2) {
                    return Long.compare(o1.maxs, o2.maxs);
                }
            });
            int ans = 1;
            int qi = 0;
            for (int i = 0; i < n; i++) {
                if (p[i].maxs - p[i].mins > d) {
                    continue;
                }
                while (qi < n && q[qi].maxs <= p[i].mins + d) {
                    cur.add(q[qi]);
                    qi++;
                }
                while (!cur.isEmpty()) {
                    P min = cur.first();
                    if (min.mins < p[i].mins) {
                        cur.pollFirst();
                    } else {
                        break;
                    }
                }
                if (cur.size() > ans) {
                    ans = cur.size();
                }
            }

            out("Case #%d: %d\n", test, ans);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("A-large.in"));
            out = new PrintWriter(new File("A-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new A().run();
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}