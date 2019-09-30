
import java.io.*;
import java.util.StringTokenizer;

public class E {

    private String solveTest() throws IOException {
        int n = nextInt();
        int d = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        for (int i = 0; i + 2 * d < n; i++) {
            if (a[i] != a[i + 2 * d]) return "CHEATERS!";
        }
        int res = 0;
        while (d > 0) {
            // 2d -> d
            int[] b = new int[d + 1];
            for (int i = 0; i < d; i++) {
                b[i] = a[i] - a[i + d];
            }
            b[d] = -b[0];
            for (int i = 0; i < d; i++) {
                int k1 = b[i];
                int k2 = b[i + 1];
                int r = k1 - k2;
                int k = Math.abs(k1 - k2);
                if (k % 2 == 1) return "CHEATERS!";
                res += k / 2;

                if (r > 0) {
                    for (int j = 0; j < d; j++) {
                        a[(i - j + 2 * d) % (2 * d)] -= k / 2;
                    }
                } else {
                    for (int j = 0; j < d; j++) {
                        a[i + 1 + j] -= k / 2;
                    }
                }

                for (int j = 0; j < 2 * d; j++) {
                    if (a[j] < 0) return "CHEATERS!";
                }

            }
            d /= 2;
        }
        return "" + res;
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
        new E().run();
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