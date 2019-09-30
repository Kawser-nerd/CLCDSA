import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Ivan Romanov
 */
public class C {
    private static final String PROBLEM = "C";

    //private static final String SIZE = "large";
    private static final String SIZE = "small-attempt0";
    //private static final String SIZE = "small-practice";

    private String solve() throws IOException {
        int n = nextInt();
        int l = nextInt();
        int h = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        for (int ans = l; ans <= h; ans++) {
            boolean ok = true;
            for (int x : a) {
                if (ans % x == 0 || x % ans == 0) {
                    // ok
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return "" + ans;
            }
        }
        return "NO";
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
        reader = new BufferedReader(new FileReader(PROBLEM + "-" + SIZE + ".in"));
        PrintWriter writer = new PrintWriter(new File(PROBLEM + "-" + SIZE + ".out"));
        try {
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                writer.print("Case #" + (i + 1) + ": ");
                writer.print(solve());
                writer.println();
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new C().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
