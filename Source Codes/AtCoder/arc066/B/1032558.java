import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author Pavel Mavrin
 */
public class Main {

    private static final long MOD = (long) (1e9 + 7);

    private void solve() throws IOException {
        long n = Long.parseLong(next()) + 1;
        String s = Long.toBinaryString(n);
        int m = s.length();
        int[] a = new int[m];
        Arrays.fill(a, -1);
        long res = 0;
        for (int i = 0; i < m; i++) if (s.charAt(i) == '1') {
            for (int j = 0; j < i; j++) {
                a[j] = s.charAt(j) - '0';
            }
            a[i] = 0;
            res += calc(a);
            res %= MOD;
        }
        out.println(res);
    }

    private long calc(int[] a) {
        long q = 1, w = 0;
        for (int i = a.length - 1; i >= 0; i--) {
            long qq = 0, ww = 0;            
            if (a[i] != 1) {
                qq += q;
                ww += (q + w);
            }
            if (a[i] != 0) {
                qq += (q + w);
                ww += w;
            }
            q = qq % MOD;
            w = ww % MOD;
        }
        return q;
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

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}