import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {

    private void solve() throws Exception {
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = nextInt();
        }
        boolean[] used = new boolean[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int minVal = Integer.MAX_VALUE, minValInd = -1;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && a[j] < minVal) {
                    minVal = a[j];
                    minValInd = j;
                }
            }
            used[minValInd] = true;
            int countBefore = 0, countAfter = 0;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && j < minValInd) {
                    ++countBefore;
                } else if (!used[j] && j > minValInd) {
                    ++countAfter;
                }
            }
            ans += Math.min(countBefore, countAfter);
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

    private B(String name) {
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
        new B("a").run();
    }
}
