import java.util.*;
import java.io.*;
import java.awt.geom.*;
import java.math.*;

public class Main {

	static final Scanner in = new Scanner(System.in);
	static final PrintWriter out = new PrintWriter(System.out,false);
	static boolean debug = false;
	
	static final long MOD = 1_000_000_007;

	static void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		long[] x = new long[n];
		long[] y = new long[m];
		long sumX = 0, sumY = 0;
		for (int i=0; i<n; i++) {
			x[i] = in.nextInt();
			if (i != 0)
				sumX = (sumX + (x[i]-x[i-1])*i%MOD*(n-i)%MOD)%MOD;
		}
		for (int i=0; i<m; i++) {
			y[i] = in.nextInt();
			if (i != 0)
				sumY = (sumY + (y[i]-y[i-1])*i%MOD*(m-i)%MOD)%MOD;
		}
		out.println(sumX*sumY%MOD);
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