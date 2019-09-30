import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * User: Igor Kirov
 * Date: 03.05.2014
 */
public class A implements Runnable {
    private boolean check(int n, char[][] c, int[][] count, int[] counts) {
        for (int i = 1; i < n; i++) {
            if (counts[i] != counts[i - 1]) return false;
            for (int j = 0; j <= counts[i]; j++) {
                if (c[i][j] != c[i - 1][j]) return false;
            }
        }
        return true;
    }

    private void solve() throws IOException {
        int n = nextInt();

        char[][] c = new char[110][110];
        int[][] count = new int[110][110];
        int[] counts = new int[110];

        for (int i = 0; i < n; i++) {
            String s = nextToken();
            char prev = 0;
            int curcnt = 0;
            int cnt = 0;
            for (char cc : s.toCharArray()) {
                if (cc != prev) {
                    c[i][cnt] = prev;
                    count[i][cnt] = curcnt;
                    cnt++;
                    curcnt = 1;
                    prev = cc;
                } else {
                    curcnt++;
                }
            }
            c[i][cnt] = prev;
            count[i][cnt] = curcnt;
            counts[i] = cnt;
        }

        if (!check(n, c, count, counts)) {
            writer.println("Fegla Won");
            return;
        }

        int ans = 0;
        for (int tt = 0; tt < counts[0]; tt++) {
            int curans = Integer.MAX_VALUE;
            for (int q = 1; q <= 100; q++) {
                int cc = 0;
                for (int i = 0; i < n; i++) {
                    cc += Math.abs(count[i][tt + 1] - q);
                }
                curans = Math.min(curans, cc);
            }
            ans += curans;
        }
        writer.println(ans);
    }

    public static void main(String[] args) {
        new Thread(null, new A(), "", 64 * 1024 * 1024).start();
    }

    StringTokenizer tokenizer;
    BufferedReader reader;
    PrintWriter writer;

    public void run() {
        try {
            try {
                Locale.setDefault(Locale.US);
            } catch (Exception ignored) {
            }

            reader = new BufferedReader(new FileReader("A.in"));
            writer = new PrintWriter(new FileWriter("A.out"));
            tokenizer = null;

            int tests = nextInt();
            for (int i = 0; i < tests; i++) {
                writer.printf("Case #%d: ", i + 1);
                solve();
                writer.flush();
            }

            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private BigInteger nextBigInteger() throws IOException {
        return new BigInteger(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}