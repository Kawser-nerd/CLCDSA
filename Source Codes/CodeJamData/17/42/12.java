import java.io.*;
import java.util.*;
import java.util.stream.Stream;

public class B {
    FastScanner in;
    PrintWriter out;

    boolean valid(int ans, int[] tik) {
        int sum = 0;
        for (int i = 0; i < tik.length; i++) {
            sum += tik[i];
            if (sum > (i + 1) * ans) {
                return false;
            }
        }
        return true;
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();

        for (int test = 1; test <= testNo; test++) {

            int n = in.nextInt();
            int c = in.nextInt();
            int m = in.nextInt();
            int[] cnt = new int[c];
            int[] tik = new int[n];
            for (int i = 0; i < m; i++) {
                int pp = in.nextInt() - 1;
                int bb = in.nextInt() - 1;
                cnt[bb]++;
                tik[pp]++;
            }

            int ans = Arrays.stream(cnt).max().getAsInt();
            while (!valid(ans, tik)) {
                ans++;
            }

            int pro = 0;
            for (int i = 0; i < n; i++) {
                if (tik[i] > ans) {
                    pro += tik[i] - ans;
                }
            }

            System.out.println("Case #" + test + ": " + ans + " " + pro);
            out.println("Case #" + test + ": " + ans + " " + pro);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-large.in"));
            out = new PrintWriter(new File("B-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        Locale.setDefault(Locale.US);
        new B().run();
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}