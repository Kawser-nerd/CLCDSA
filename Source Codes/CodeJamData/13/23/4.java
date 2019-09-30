import java.util.*;
import java.io.*;

public class C {
    public void run() throws IOException {
        FastScanner dic = new FastScanner(new FileInputStream("garbled_email_dictionary.txt"));
        in = new FastScanner(new FileInputStream("C-large.in"));
        out = new PrintWriter(new FileOutputStream("C-large.out"));

        int n = dic.nextInt();
        String[] s = new String[n];
        int len = 0;
        for (int i = 0; i < n; i++) {
            s[i] = dic.next();
            len += s[i].length();
        }

        int[][] go = new int[len + 1][26];
        boolean[] term = new boolean[len + 1];
        for (int[] z : go) {
            Arrays.fill(z, -1);
        }

        int nv = 1;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < s[i].length(); j++) {
                int c = s[i].charAt(j) - 'a';
                if (go[cur][c] == -1) {
                    go[cur][c] = nv;
                    nv++;
                }
                cur = go[cur][c];
            }
            term[cur] = true;
        }

        System.out.println(nv);

        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            String t = in.next();
            int m = t.length();

            Map<Pos, Integer>[] dp = new Map[m + 1];
            for (int v = 0; v <= m; v++) {
                dp[v] = new HashMap<Pos, Integer>();
            }
            dp[0].put(new Pos(0, 5), 0);

            for (int i = 0; i < m; i++) {
                int c = t.charAt(i) - 'a';
//                System.out.println(dp[i].size());
                for (Pos p : dp[i].keySet()) {
                    if (go[p.p][c] != -1) {
                        int z = dp[i].get(p);
                        Pos q = new Pos(go[p.p][c], Math.min(5, p.last + 1));
                        if (dp[i + 1].containsKey(q)) {
                            z = Math.min(dp[i + 1].get(q), z);
                        }
                        dp[i + 1].put(q, z);
                        if (term[q.p]) {
                            q = new Pos(0, q.last);
                            z = dp[i].get(p);
                            if (dp[i + 1].containsKey(q)) {
                                z = Math.min(dp[i + 1].get(q), z);
                            }
                            dp[i + 1].put(q, z);
                        }
                    }
                    if (p.last == 5) {
                        for (int d = 0; d < 26; d++) {
                            if (go[p.p][d] != -1) {
                                Pos q = new Pos(go[p.p][d], 1);
                                int z = dp[i].get(p) + 1;
                                if (dp[i + 1].containsKey(q)) {
                                    z = Math.min(dp[i + 1].get(q), z);
                                }
                                dp[i + 1].put(q, z);
                                if (term[q.p]) {
                                    q = new Pos(0, q.last);
                                    z = dp[i].get(p) + 1;
                                    if (dp[i + 1].containsKey(q)) {
                                        z = Math.min(dp[i + 1].get(q), z);
                                    }
                                    dp[i + 1].put(q, z);
                                }
                            }
                        }
                    }
                }
            }

            int ans = m;
            for (Pos p : dp[m].keySet()) {
                if (p.p == 0) {
                    int v = dp[m].get(p);
                    if (v < ans) {
                        ans = v;
                    }
                }
            }

            out.println("Case #" + test + ": " + ans);

        }

        out.close();
    }

    static class Pos {
        int p;
        int last;

        Pos(int p, int last) {
            this.p = p;
            this.last = last;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pos pos = (Pos) o;

            if (last != pos.last) return false;
            if (p != pos.p) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = p;
            result = 31 * result + last;
            return result;
        }
    }

    FastScanner in;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new C().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream in) throws IOException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        String next() {
            try {
                while (st == null || !st.hasMoreTokens()) {
                    st = new StringTokenizer(br.readLine());
                }
            } catch (IOException e) {
                System.err.println(e);
                System.exit(1);
            }
            return st.nextToken();
       }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}