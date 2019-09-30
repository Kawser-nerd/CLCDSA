import java.util.*;
import java.io.*;
import java.awt.geom.*;
import java.math.*;

public class Main {

	static final Scanner in = new Scanner(System.in);
	static final PrintWriter out = new PrintWriter(System.out,false);
	static boolean debug = false;

	static void solve() {
		int n = in.nextInt();
		long[][] a = new long[n][2];
		ArrayList<long[]> x = new ArrayList<>();
		ArrayList<long[]> y = new ArrayList<>();
		for (int i=0; i<n; i++) {
			for (int j=0; j<2; j++) {
				a[i][j] = in.nextInt();
			}
			if (a[i][0] < a[i][1]) {
				x.add(a[i]);
			} else {
				y.add(a[i]);
			}
		}

		Collections.sort(x, new Comparator<long[]>(){
			public int compare(long[] a, long[] b) {
				if (a[0] != b[0]) {
					return Long.compare(a[0], b[0]);
				}
				return Long.compare(b[1], a[1]);
			}
		});

		Collections.sort(y, new Comparator<long[]>(){
			public int compare(long[] a, long[] b) {
				if (a[1] != b[1]) {
					return Long.compare(b[1], a[1]);
				}
				return Long.compare(b[0], a[0]);
			}
		});
		
		BigInteger max = BigInteger.ZERO;
		BigInteger h = BigInteger.ZERO;
		for (int i=0; i<x.size(); i++) {
			h = h.add(new BigInteger(String.valueOf(x.get(i)[0])));
			max = max.max(h);
			h = h.subtract(new BigInteger(String.valueOf(x.get(i)[1])));
		}
		for (int i=0; i<y.size(); i++) {
			h = h.add(new BigInteger(String.valueOf(y.get(i)[0])));
			max = max.max(h);
			h = h.subtract(new BigInteger(String.valueOf(y.get(i)[1])));
		}

		out.println(max);
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