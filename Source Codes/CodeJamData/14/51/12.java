import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            int N = scan.nextInt();
            long p = scan.nextInt();
            long q = scan.nextInt();
            long r = scan.nextInt();
            long s = scan.nextInt();
            long[] arr = new long[N];
            long[] dp = new long[N + 1];
            long sum = 0;
            for (int i = 0; i < N; ++i) {
                arr[i] = ((i * p + q) % r) + s;
                sum += arr[i];
                dp[i + 1] = dp[i] + arr[i];
            }
            long avg = sum / 3;
            int first = 0;
            int second = N - 1;
            long temp = 0;
            int index = 0;
            while (temp < avg && index < N) {
                temp += arr[index];
                first = index;
                ++index;
            }
            temp = 0;
            index = first + 1;
            while (temp < avg && index < N) {
                temp += arr[index];
                second = index;
                ++index;
            }
            double res = 0;
            for (int i = Math.max(0, first - 100); i < Math.min(N, first + 100); ++i) {
                for (int j = Math.max(0, second - 100); j < Math.min(N, second + 100); ++j) {
                    if (j <= i) {
                        continue;
                    }
                    long a = dp[i + 1];
                    long b = dp[j] - dp[i + 1];
                    long c = dp[N] - dp[j];
                    long left = sum - Math.max(a, Math.max(b, c));
                    res = Math.max(res, 1.0 * left / sum);
                }
            }
            System.out.println(String.format("Case #%d: %.11f", taskIndex, res));
        }
    }
}

class FastScanner {
    BufferedReader in;
    StringTokenizer tok;

    public FastScanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }

    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            throw new InputMismatchException();
        }
    }

    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }
        return tok.nextToken();
    }

    private String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }
    
    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() {
        return Long.parseLong(nextToken());
    }

}
