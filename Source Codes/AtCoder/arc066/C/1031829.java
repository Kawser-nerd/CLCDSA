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
        long[] a = new long[n];
        char[] c = new char[n];
        c[0] = '+';
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                c[i] = next().charAt(0);
            }
            a[i] = nextInt();
        }
        long s = 0;
        long ss = 0;
        long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (c[i] == '+') {
                s += a[i];
            } else {
                ans = Math.max(-a[i] + s + ans, -a[i] - s + ss);
                ss += s + a[i];
                s = 0;
            }
        }
        ans += s;
        out.println(ans);
    }




    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}