import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Ivan Romanov
 */
public class D {

    char[] s;

    int[] p;

    int k;

    boolean[] was;

    int ans;

    private String solve() throws IOException {
        k = nextInt();
        s = nextToken().toCharArray();
        p = new int[k];
        was = new boolean[k];
        ans = Integer.MAX_VALUE;
        rec(0);
        return "" + ans;
    }

    private void rec(int p) {
        if (p == k) {
            char[] q = new char[s.length];
            for (int b = 0; b < s.length / k; b++) {
                for (int i = 0; i < k; i++) {
                    q[b * k + i] = s[b * k + this.p[i]];
                }
            }
            char last = (char) 0;
            int count = 0;
            for (char ch : q) {
                if (ch != last) {
                    count++;
                    last = ch;
                }
            }
            ans = Math.min(ans, count);
        } else {
            for (int i = 0; i < k; i++) {
                if (!was[i]) {
                    was[i] = true;
                    this.p[p] = i;
                    rec(p + 1);
                    this.p[p] = 0;
                    was[i] = false;
                }
            }
        }
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
        reader = new BufferedReader(new FileReader("D-small.in"));
        PrintWriter writer = new PrintWriter(new File("D-small.out"));
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
            new D().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}