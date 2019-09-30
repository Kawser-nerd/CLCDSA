
import java.io.*;
import java.util.StringTokenizer;

public class B {

    private int solveTest() throws IOException {
        int r = nextInt();
        int c = nextInt();
        if (r > c) {
            int t = r;
            r = c;
            c = t;
        }
        int n = nextInt();
        System.out.println(r + " " + c + " " + n);
        if (r == 1) {
            if (n <= (c + 1) / 2) {
                return 0;
            } else {
                n -= (c + 1) / 2;
                int res = n * 2;
                if (c % 2 == 0) {
                    res--;
                }
                return res;
            }
        }
        if (n <= (r * c + 1) / 2) {
            return 0;
        }
        int res = (r - 1) * c + (c - 1) * r;
        int p = (r - 2) * (c - 2);
        int h = r * c - n;
        if (h <= (p + 1) / 2) {
            return res - h * 4;
        }
        if (p % 2 == 0) {
            h -= p / 2;
            res -= p / 2 * 4;
            if (h <= r + c - 4) {
                return res - h * 3;
            }
            h -= r + c - 4;
            res -= (r + c - 4) * 3;
            return res - 2 * h;
        } else {
            int hh = h;
            int res1 = res;
            hh -= (p + 1) / 2;
            res1 -= (p + 1) / 2 * 4;
            if (hh <= r + c - 6) {
                res1 -= hh * 3;
            } else {
                hh -= r + c - 6;
                res1 -= (r + c - 6) * 3;
                res1 -= hh * 2;
            }
            hh = h;
            int res2 = res;
            hh -= p / 2;
            res2 -= p / 2 * 4;
            if (hh <= r + c - 2) {
                res2 -= hh * 3;
            } else {
                hh -= r + c - 2;
                res2 -= (r + c - 2) * 3;
                res2 -= hh * 2;
            }
            return Math.min(res1, res2);
        }
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
        new B().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName() + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName() + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

}