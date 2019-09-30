import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Don Li
 */
public class Main {
    
    int MOD = (int) 1e9 + 7;
    
    void solve() {
        int n = in.nextInt();
        char[] s = in.nextToken().toCharArray();
        
        int[] cnt = new int[26];
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }
        
        long ans = 1;
        for (int i = 0; i < 26; i++) {
            ans = ans * (cnt[i] + 1) % MOD;
        }
        ans = (ans - 1 + MOD) % MOD;
        out.println(ans);
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