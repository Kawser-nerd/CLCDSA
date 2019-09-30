import java.io.*;
import java.rmi.AccessException;
import java.util.*;

import com.sun.xml.internal.bind.v2.runtime.unmarshaller.XsiNilLoader.Array;

public class Solution implements Runnable {

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	static final String filename = "A-large";

	public void solve(int test) throws IOException {
		out.print("Case #" + test + ": ");
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			char[] tmp = next().toCharArray();
			for (int j = 0; j < n; ++j) {
				if (tmp[j] == '1') {
					a[i] = j;
				}
			}
		}
		out.println(solve(a));
	}
	
	private int solve(int[] a) {
		if (a.length == 0) {
			return 0;
		}
		int[] b = a.clone();
		Arrays.sort(b);
		int k = a.length - 1;
		loop: while (k >= 0) {
			boolean killed = false;
			for (int i = 0, j = 0; i < a.length; ++i) {
				if (!killed && b[i] == a[k]) {
					killed = true;
					continue;
				}
				if (b[i] > j) {
					--k;
					continue loop;
				}
				++j;
			}
			break;
		}
		if (k < 0) {
			throw new AssertionError();
		}
		int[] r = new int[a.length - 1];
		for (int i = 0; i < k; ++i) {
			r[i] = a[i];
		}
		for (int i = k + 1; i < a.length; ++i) {
			r[i - 1] = a[i];
		}
		return solve(r) + a.length - k - 1;
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new PrintWriter(filename + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				solve(test + 1);
			}
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		} catch (OutOfMemoryError er) {
			List<int[]> x = new ArrayList<int[]>();
			while (true) {
				x.add(new int[100000]);
			}
		}
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Thread(new Solution()).start();
	}
	
}
