import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
    public static void main(String[] args) {
        new B().run();
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public void solve() throws IOException {
        int n = nextInt();
        long b = nextLong();
        if (b > 1L << (n - 2)) {
            out.println("IMPOSSIBLE");
            return;
        }
        int[][] a = new int[n][n];
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                a[i][j] = 1;
            }
        }
        b--;
        a[0][n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (b % 2 == 1) {
                a[0][i] = 1;
            }
            b /= 2;
        }

        out.println("POSSIBLE");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out.print(a[i][j]);
            }
            out.println();
        }
    }

    public void run() {
        try {
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");

            int t = nextInt();
            for (int i = 0; i < t; i++) {
                out.print(String.format("Case #%d: ", i + 1));
                solve();
            }

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
