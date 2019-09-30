
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Dsmall {

    private int n;

    private int solveTest() throws IOException {
        n = nextInt();
        int m = 0;
        for (int i = 0; i < n; i++) {
            String s = next();
            for (int j = 0; j < n; j++) {
                m += (s.charAt(j) - '0') << (i * n + j);
            }
        }
        int res = n * n;
        for (int mm = 0; mm < (1 << (n * n)); mm++) {
            if ((mm & m) == m) {
                if (check(mm)) {
//                    System.out.println(mm);
                    res = Math.min(res, Integer.bitCount(mm - m));
                }
            }
        }
        return res;
    }

    boolean[] z;
    boolean[] r;
    boolean[][] a;

    private boolean check(int m) {
        z = new boolean[n];
        r = new boolean[n];
        a = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = (m & (1 << (i * n + j))) > 0;
            }
        }
        boolean res = bt();
//        System.out.println(Arrays.deepToString(a) + " " + res);
        return res;
    }

    private boolean bt() {
        for (int i = 0; i < n; i++) if (!z[i]) {
            boolean ok = false;
            for (int j = 0; j < n; j++) if (a[i][j] && !r[j]) {
                ok = true;
                z[i] = true;
                r[j] = true;
                if (!bt()) return false;
                z[i] = false;
                r[j] = false;
            }
            if (!ok) return false;
        }
        return true;
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            int res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new Dsmall().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName().substring(0, 1) + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName().substring(0, 1) + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

}