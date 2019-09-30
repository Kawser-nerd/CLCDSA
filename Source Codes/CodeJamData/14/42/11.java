import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {

    public void solve() throws Exception {
    	int T = sc.nextInt();
    	for (int Case = 1; Case <= T; Case++) {
    		int n = sc.nextInt();
    		int[] a = new int[n];
    		for (int i = 0; i < n; i++) {
    			a[i] = sc.nextInt();
    		}
    		int ans = 0;
    		for (int i = 0; i < n; i++) {
    			int left = 0;
    			for (int j = 0; j < i; j++) {
    				if (a[j] > a[i]) {
    					left++;
    				}
    			}
    			int right = 0;
    			for (int j = i + 1; j < n; j++) {
    				if (a[j] > a[i]) {
    					right++;
    				}
    			}
    			ans += min(left, right);
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
        	in = new BufferedReader(new FileReader("B-large.in"));
        	out = new PrintWriter(new FileWriter("B-large.out"));
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