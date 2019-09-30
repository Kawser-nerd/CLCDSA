import java.util.*;
import java.io.*;

public class C {

    boolean[][] d;

    int na, nb;
    boolean[] u;
    int[] p;

    boolean dfs(int x) {
        u[x] = true;
        for (int y = 0; y < nb; y++) {
            if (d[x][y] && (p[y] == -1 || !u[p[y]] && dfs(p[y]))) {
                p[y] = x;
                return true;
            }
        }
        return false;
    }

    public void run() throws IOException {
        in = new FastScanner(new FileInputStream("C-large.in"));
        out = new PrintWriter(new FileOutputStream("C-large.out"));

        int tn = in.nextInt();
        for (int test = 1; test <= tn; test++) {
            System.err.println(test);
            int n = in.nextInt();
            Map<String, Integer> a = new HashMap<>();
            Map<String, Integer> b = new HashMap<>();
            d = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                String wa = in.next();
                String wb = in.next();
                int ia, ib;
                if (a.containsKey(wa)) {
                    ia = a.get(wa);
                } else {
                    ia = a.size();
                    a.put(wa, ia);
                }
                if (b.containsKey(wb)) {
                    ib = b.get(wb);
                } else {
                    ib = b.size();
                    b.put(wb, ib);
                }
                d[ia][ib] = true;
            }
            na = a.size();
            nb = b.size();

            p = new int[nb];
            Arrays.fill(p, -1);
            u = new boolean[na];

            int ans = n - na - nb;
            for (int i = 0; i < na; i++) {
                Arrays.fill(u, false);
                if (dfs(i)) {
                    ans++;
                }
            }
            out.println("Case #" + test + ": " + ans);
        }

        out.close();
    }

    FastScanner in;
    PrintWriter out;

    void print(Object... o) {
        for (Object x : o) {
            out.print(x);
            System.out.print(x);
        }
        out.flush();
    }

    void println(Object... o) {
        for (Object x : o) {
            out.print(x);
            System.out.print(x);
        }
        out.println();
        System.out.println();
        out.flush();
    }

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
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