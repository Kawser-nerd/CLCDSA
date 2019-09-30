import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class Main {

    private void solve() throws IOException {
        int n = nextInt();
        long e = nextInt();
        long t = nextInt();
        long[] x = new long[n + 1];
        for (int i = 0; i < n; i++) {
            x[i] = nextInt();
        }
        x[n] = e;
        long[] d = new long[n + 1];
        long min = Long.MAX_VALUE;
        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            while ((x[j] - x[i]) * 2 > t) {
                min = Math.min(min, d[j + 1] + (x[j + 1] - x[j]) + 3 * x[j]);
                j--;
            }
            d[i] = d[j + 1] + t + (x[j + 1] - x[i]);
            if (min < Long.MAX_VALUE) {
                d[i] = Math.min(d[i], min - 3 * x[i]);
            }
        }
        out.println(x[0] + d[0]);
    }

    private BufferedReader br;
    private PrintWriter out;
    private StringTokenizer st;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    private void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

}