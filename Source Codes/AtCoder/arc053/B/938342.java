import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    int N;
    int cnt[];
    int odd;

    void solve() throws IOException {
        String S = ns();
        N = S.length();

        cnt = new int[26];
        for (int i = 0; i < N; i++) {
            cnt[S.charAt(i) - 'a']++;
        }

        odd = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) odd++;
        }

        int high = N + 1;
        int low = 0;
        while (high - low > 1) {
            int mid = (high + low) / 2;
            if (can(mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }

        out.println(low);
    }

    boolean can(int k) {
        if (N / k >= odd) {
            if (k % 2 == 0 && odd != 0) return can(k + 1);
            return true;
        }
        return false;
    }

    String ns() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine(), " ");
        }
        return tok.nextToken();
    }

    int ni() throws IOException {
        return Integer.parseInt(ns());
    }

    long nl() throws IOException {
        return Long.parseLong(ns());
    }

    double nd() throws IOException {
        return Double.parseDouble(ns());
    }

    String[] nsa(int n) throws IOException {
        String[] res = new String[n];
        for (int i = 0; i < n; i++) {
            res[i] = ns();
        }
        return res;
    }

    int[] nia(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = ni();
        }
        return res;
    }

    long[] nla(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nl();
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        tok = new StringTokenizer("");
        Main main = new Main();
        main.solve();
        out.close();
    }
}