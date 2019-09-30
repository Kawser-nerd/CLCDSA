import java.util.*;
import java.io.*;
import java.awt.geom.*;
import java.math.*;

public class Main {

	static final Scanner in = new Scanner(System.in);
	static final PrintWriter out = new PrintWriter(System.out,false);
	static boolean debug = false;
	
	static final int MOD = 1_000_000_007;
	
	public static long modPow(long x, long n, long mod) {
		long res = 1;
		while (n > 0) {
			if ((n&1) == 1) res = res * x % mod;
			x = x * x % mod;
			n >>= 1;
		}
		return res;
	}

	static void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		int[] x = new int[n];
		
		for (int i=0; i<n; i++) {
			a[i] = in.nextInt();
			if ((n+1)%2 != a[i]%2) {
				out.println(0);
				return;
			}
			x[a[i]]++;
			if (x[a[i]] > 2) {
				out.println(0);
				return;
			}
		}
		
		if (x[0] > 1) {
			out.println(0);
			return;
		}
		
		out.println(modPow(2, n/2, MOD));
	}

	public static void main(String[] args) {
		debug = args.length > 0;
		long start = System.nanoTime();

		solve();
		out.flush();

		long end = System.nanoTime();
		dump((end - start) / 1000000 + " ms");
		in.close();
		out.close();
	}

	static void dump(Object... o) { if (debug) System.err.println(Arrays.deepToString(o)); }
}