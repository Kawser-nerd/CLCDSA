import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class Main {

    private void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        Arrays.sort(a);
        long res = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] != (i + n % 2) / 2 * 2 + (1 - n % 2)) {
                out.println(0);
                return;
            }
            if (i > 0 && a[i] == a[i - 1]) {
                res = (res * 2) % ((long) (1e9 + 7));
            }
        }
        out.println(res);
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