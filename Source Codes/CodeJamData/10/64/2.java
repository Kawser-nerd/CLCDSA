import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solveTest() throws Exception {
		int n = nextInt();
		long x[] = new long[n];
		for (int i = 0; i < n; i++) {
			x[i] = nextLong();
		}
		long f = nextLong();
		sort(x);
		long segs[] = new long[n - 1];
		for (int i = 0; i < segs.length; i++) {
			segs[i] = x[i + 1] - x[i];
		}
		long presegs[] = new long[(segs.length + 1) / 2];
		long postsegs[] = new long[segs.length / 2];
		for (int i = 0; i < presegs.length; i++) {
			presegs[i] = segs[i];
		}
		for (int i = 0; i < postsegs.length; i++) {
			postsegs[i] = segs[segs.length - i - 1];
		}
		long preres[][] = calc(presegs);
		long postres[][] = calc(postsegs);
		long ans = Long.MIN_VALUE;
		for (int i = 0; i < preres.length; i++) {
			for (int j = max(0, i - 1); j < min(postres.length, i + 2); j++) {
				long arr1[] = preres[i];
				long arr2[] = postres[j];
				for (long elem1: arr1) {
					int pos = Arrays.binarySearch(arr2, f - elem1);
					if (pos < 0) {
						pos = ~pos - 1;
						if (pos < 0) {
							continue;
						}
					}
					long elem2 = arr2[pos];
					ans = max(ans, elem1 + elem2);
				}
			}
		}
		if (ans == Long.MIN_VALUE) {
			out.println("NO SOLUTION");
		} else {
			out.println(ans);
		}
	}
	
	static long[][] calc(long segs[]) {
		long ans[][] = new long[][] {{0}};
		for (int i = 0; i < segs.length; i++) {
			long seg = segs[i];
			long nans[][] = new long[ans.length + 1][];
			nans[0] = new long[] {};
			for (int j = 1; j < nans.length; j++) {
				long add = j * seg * 2;
				long curList[] = new long[16];
				int curPos = 0;
				for (int k = max(0, j - 1); k < min(ans.length, j + 2); k++) {
					for (long elem: ans[k]) {
						long nelem = elem + add;
						if (curPos >= curList.length) {
							curList = Arrays.copyOf(curList, curList.length * 2);
						}
						curList[curPos++] = nelem;
					}
				}
				sort(curList, 0, curPos);
				int p1 = 0;
				int p2 = 0;
				while (p1 < curPos) {
					if (p1 == 0 || curList[p1] != curList[p1 - 1]) {
						curList[p2++] = curList[p1];
					}
					p1++;
				}
				nans[j] = Arrays.copyOf(curList, p2);
			}
			ans = nans;
		}
		return ans;
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
			System.out.print('.');
		}
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		System.out.print("Enter filename: ");
		System.out.flush();
		String filename = new BufferedReader(new InputStreamReader(System.in)).readLine();
		in = new BufferedReader(new InputStreamReader(
			new FileInputStream(new File(filename + ".in"))));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
			new FileOutputStream(new File(filename + ".out")))));
		solve();
		in.close();
		out.close();
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}
	
	static long nextLong() throws IOException {
		return parseLong(next());
	}
	
	static double nextDouble() throws IOException {
		return parseDouble(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}