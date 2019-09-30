
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {

    private String solveTest() throws IOException {
        int n = nextInt();
        int k = nextInt();
        double[] p = new double[n];
        for (int i = 0; i < n; i++) p[i] = Double.parseDouble(next());
        Arrays.sort(p);
        double res = 0;
        for (int t = 0; t <= k; t++) {
            double[] d = new double[k + 1];
            d[0] = 1;
            for (int j = 0; j < n; j++)
                if (j < t || (j >= n - (k - t))) {
                    for (int q = k; q >= 0; q--) {
                        d[q] = d[q] * (1 - p[j]) + (q == 0 ? 0 : d[q - 1] * p[j]);
                    }
                }
            res = Math.max(res, d[k / 2]);
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