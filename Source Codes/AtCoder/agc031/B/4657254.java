import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Don Li
 */
public class Main {
    
    int N = (int) 2e5 + 10;
    int MOD = (int) 1e9 + 7;
    
    int[] sum = new int[N];
    
    void solve() {
        int n = in.nextInt();
        int[] c = new int[n];
        for (int i = 0; i < n; i++) c[i] = in.nextInt();
        
        int sz = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || c[i] != c[i - 1]) c[sz++] = c[i];
        }
        c = Arrays.copyOf(c, sz);
        n = sz;
        
        int[][] dp = new int[n + 1][2];
        sum[c[0]] = dp[1][0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i + 1][0] = (dp[i][0] + dp[i][1]) % MOD;
            dp[i + 1][1] = sum[c[i]];
            sum[c[i]] = (sum[c[i]] + dp[i + 1][0]) % MOD;
        }
        out.println((dp[n][0] + dp[n][1]) % MOD);
    }
    
    
    public static void main(String[] args) {
        in = new FastScanner(new BufferedReader(new InputStreamReader(System.in)));
        out = new PrintWriter(System.out);
        new Main().solve();
        out.close();
    }
    
    static FastScanner in;
    static PrintWriter out;
    
    static class FastScanner {
        BufferedReader in;
        StringTokenizer st;
        
        public FastScanner(BufferedReader in) {
            this.in = in;
        }
        
        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        
        public int nextInt() {
            return Integer.parseInt(nextToken());
        }
        
        public long nextLong() {
            return Long.parseLong(nextToken());
        }
        
        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }
}