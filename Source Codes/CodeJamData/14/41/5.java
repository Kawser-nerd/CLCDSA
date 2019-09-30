import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class A {

    private void solve() throws Exception {
        int n = nextInt(), x = nextInt();
        int[] s = new int[n];
        for (int i = 0; i < n; ++i) {
            s[i] = nextInt();
        }
        Arrays.sort(s);
        boolean[] used = new boolean[n];
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            int j = i - 1;
            while (j >= 0 && (used[j] || s[j] + s[i] > x)) {
                --j;
            }
            if (j >= 0) {
                used[j] = true;
            }
            ++ans;
        }
        out.println(ans);
    }

    public void run() {
        try {
            int tc = nextInt();
            for (int it = 1; it <= tc; ++it) {
                System.err.println(it);
                out.print("Case #" + it + ": ");
                solve();
            }
        } catch (Exception e) {
            NOO(e);
        } finally {
            out.close();
        }
    }

    PrintWriter out;
    BufferedReader in;
    StringTokenizer St;

    void NOO(Exception e) {
        e.printStackTrace();
        System.exit(42);
    }

    int nextInt() {
        return Integer.parseInt(nextToken());
    }

    long nextLong() {
        return Long.parseLong(nextToken());
    }

    double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    String nextToken() {
        while (!St.hasMoreTokens()) {
            try {
                String line = in.readLine();
                if (line == null)
                    return null;
                St = new StringTokenizer(line);
            } catch (Exception e) {
                NOO(e);
            }
        }
        return St.nextToken();
    }

    private A(String name) {
        try {
            in = new BufferedReader(new FileReader("input.txt"));
            St = new StringTokenizer("");
            out = new PrintWriter(new FileWriter("output.txt"));
        } catch (Exception e) {
            NOO(e);
        }
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new A("a").run();
    }
}
