import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Don Li
 */
public class Main {
    
    int LOG = 40;
    
    void solve() {
        long A = in.nextLong(), B = in.nextLong();
        
        long ans = xor(B) ^ xor(A - 1);
        out.println(ans);
    }
    
    long xor(long n) {
        if (n <= 0) return 0;
        long res = 0;
        for (int i = 0; i < LOG; i++) {
            long period = 1L << (i + 1);
            long zeros = period / 2, ones = period / 2;
            long q = (n + 1) / period, r = (n + 1) % period;
            long v = 0;
            if (q % 2 == 1 && ones % 2 == 1) v ^= 1;
            if (r > zeros && (r - zeros) % 2 == 1) v ^= 1;
            res |= v << i;
        }
        return res;
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