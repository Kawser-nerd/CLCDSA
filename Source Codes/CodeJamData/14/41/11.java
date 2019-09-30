import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {

    public void solve() throws Exception {
    	int T = sc.nextInt();
    	for (int Case = 1; Case <= T; Case++) {
    		int n = sc.nextInt(), x = sc.nextInt();
    		int[] sz = new int[n];
    		for (int i = 0; i < n; i++) {
    			sz[i] = sc.nextInt();
    		}
    		Arrays.sort(sz);
    		int ans = 0;
    		for (int l = 0, r = n - 1; r >= l; r--) {
    			ans++;
    			if (sz[l] + sz[r] <= x) {
    				l++;
    			}
    		}
    		out.printf(Locale.US, "Case #%d: %d\n", Case, ans);
    	}
    }

    static Throwable uncaught;

    BufferedReader in;
    FastScanner sc;
    PrintWriter out;

    @Override
    public void run() {
        try {
        	in = new BufferedReader(new FileReader("A-large.in"));
        	out = new PrintWriter(new FileWriter("A-large.out"));
            //in = new BufferedReader(new InputStreamReader(System.in));
            //out = new PrintWriter(System.out);
            sc = new FastScanner(in);
            solve();
        } catch (Throwable uncaught) {
            Solution.uncaught = uncaught;
        } finally {
            out.close();
        }
    }

    public static void main(String[] args) throws Throwable {
        Thread thread = new Thread(null, new Solution(), "", (1 << 26));
        thread.start();
        thread.join();
        if (Solution.uncaught != null) {
            throw Solution.uncaught;
        }
    }

}

class FastScanner {

    BufferedReader in;
    StringTokenizer st;

    public FastScanner(BufferedReader in) {
        this.in = in;
    }

    public String nextToken() throws Exception {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }

}