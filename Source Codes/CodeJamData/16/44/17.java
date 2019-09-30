import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Deasy {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++) {
            int n = nextInt();
            boolean[][] a = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                String s = nextToken();
                for (int j = 0; j < n; j++)
                    a[i][j] = s.charAt(j) == '1';
            }
            int maxMask = 1 << (n * n);
            int ans = 1000000000;
            for (int i = 0; i < maxMask; i++) {
                boolean[][] b = new boolean[n][n];
                for (int j = 0; j < n; j++)
                    for (int k = 0; k < n; k++) b[j][k] = a[j][k];
                int cur = 0;
                for (int j = 0; j < n; j++)
                    for (int k = 0; k < n; k++) {
                        int ind = j * n + k;
                        if ((i & (1 << ind)) != 0) {
                            b[j][k] = true;
                            cur++;
                        }
                    }
                boolean good = true;
                for (int j = 0; j < n; j++) {
                    int count1 = 0;
                    int count2 = 0;
                    int mask = 0;
                    for (int k = 0; k < n; k++)
                        if (b[j][k]) {
                            count1++;
                            for (int h = 0; h < n; h++) if (b[h][k]) mask |= 1 << h;
                        }
                    if (count1 == 0 || Integer.bitCount(mask) > count1) good = false;
                }
                if (good) ans = Math.min(ans, cur);
            }
            out.printf("Case #%d: %d\n", testCase + 1, ans);
        }
    }

    public static void main(String[] args) throws IOException {
        new Deasy().run();
    }

    void run() throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
		reader = new BufferedReader(new FileReader("input.txt"));
        tokenizer = null;
        out = new PrintWriter(new OutputStreamWriter(System.out));
		out = new PrintWriter(new FileWriter("output.txt"));
        solve();
        reader.close();
        out.flush();

    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
