
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {

    private int[] p;
    private int n;

    private String solveTest() throws IOException {
        n = nextInt();
        int c = nextInt();
        int m = nextInt();
        int[] d = new int[c];
        p = new int[m];
        for (int i = 0; i < m; i++) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            d[b]++;
            p[i] = a;
        }
        Arrays.sort(p);
        int l = 0;
        for (int i = 0; i < c; i++) {
            l = Math.max(l, d[i]);
        }
        l--;
        int r = m;
        while (r > l + 1) {
            int mm = (l + r) / 2;
            if (pos(mm)) {
                r = mm;
            } else {
                l = mm;
            }
        }
        pos(r);
        return "" + r + " " + prom;
    }

    private int prom;

    private boolean pos(int mm) {
        int q = n - 1;
        int c = mm;
        prom = 0;
        for (int i = p.length - 1; i >= 0; i--) {
            while (c == 0 || p[i] < q) {
                q--;
                c = mm;
                if (q < 0) return false;
            }
            if (p[i] > q) {
                prom++;
            } else {
                c--;
            }
        }
        return true;
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            String res = solveTest();
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
        new B().run();
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