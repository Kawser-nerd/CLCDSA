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
        String S = next();
        String T = next();
        if (S.equals(T)) {
            out.println(0);
            return;
        }
        int j = n - 1;
        int res = 0;
        int[] q = new int[n + 1];
        int h = 0;
        int t = 0;
        int d = 0;
        int jj = n;
        for (int i = n - 1; i >= 0; i--) {
            if (j > i) j = i;
            while (j >= 0 && S.charAt(j) != T.charAt(i)) j--;
            if (j < 0) {
                out.println(-1);
                return;
            }
            while (t > h) {
                int xx = q[h] - d;
                if (xx > i) {
                    h++;
                } else {
                    break;
                }
            }
            if (j < i && j != jj) {
                d++;
                q[t++] = (j + d);
                res = Math.max(res, t - h);
            }
            jj = j;
//            System.out.println(i + " " + j);
//            for (int e = h; e < t; e++) {
//                System.out.println(q[e] - d);
//            }
        }
        out.println(res);
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