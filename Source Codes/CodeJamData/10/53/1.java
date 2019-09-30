import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solveTest() throws Exception {
		int c = nextInt();
		int arr[] = new int[6000000];
		long sumsqr = 0;
		for (int i = 0; i < c; i++) {
			int pos = nextInt() + 3000000;
			int val = nextInt();
			arr[pos] = val;
//			System.out.println("pos: " + pos + ", val: " + val);
			sumsqr += (long) pos * pos * val;
		}
		ScanLoop: while (true) {
			int i = 0;
			while (arr[i] <= 1) {
				++i;
				if (i >= arr.length) {
					break ScanLoop;
				}
			}
			int j = i;
			do {
				--i;
			} while (arr[i] > 0);
			++i;
			do {
				++j;
			} while (arr[j] > 0);
			int cnt = 0;
			long sum = 0;
			for (int k = i; k < j; k++) {
				cnt += arr[k];
				sum += (long) k * arr[k];
				arr[k] = 0;
			}
			long minSum = (long) cnt * (cnt - 1) / 2;
			sum -= minSum;
			for (int k = 0; k < cnt; k++) {
				arr[(int) (sum / cnt) + k + ((k + (int) (sum % cnt) >= cnt) ? 1 : 0)]++;
			}
		}
		for (int i = 0; i < arr.length; i++) {
			sumsqr -= (long) i * i * arr[i];
		}
		out.println(-sumsqr / 2);
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
			System.out.print(".");
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