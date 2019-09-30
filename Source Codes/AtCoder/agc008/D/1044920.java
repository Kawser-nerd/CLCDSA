import java.io.*;
import java.util.*;

public class Main {
	
	static PrintWriter out;
	
	final static int INF = (int) 1e9;
	final static int MOD = (int) 1e9 + 7;
	final static long LINF = (long) 1e18;
	final static double PI = (double) Math.acos(-1.0);
	final static double EPS = (double) 1e-9;
	
	void solve() {
		int n = Input.nextInt();
		final int[] x = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = Input.nextInt() - 1;
		}
		int[] res = new int[n * n];
		for (int i = 0; i < n; i++) {
			res[x[i]] = i + 1;
		}
		ArrayList<Integer> v = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			v.add(i);
		}
		Collections.sort(v, new Comparator<Integer>() {
			public int compare(Integer i, Integer j) {
				return Integer.compare(x[i], x[j]);
			}
		});
		for (int j = 0; j < n; j++) {
			int i = v.get(j);
			int cnt = i;
			for (int k = 0; k < x[i] && cnt > 0; k++) {
				if (res[k] == 0) {
					res[k] = i + 1;
					cnt--;
				}
			}
			if (cnt > 0) {
				out.println("No");
				return;
			}
		}
		Collections.sort(v, new Comparator<Integer>() {
			public int compare(Integer i, Integer j) {
				return Integer.compare(x[j], x[i]);
			}
		});
		for (int j = 0; j < n; j++) {
			int i = v.get(j);
			int cnt = n - i - 1;
			for (int k = n * n - 1; k > x[i] && cnt > 0; k--) {
				if (res[k] == 0) {
					res[k] = i + 1;
					cnt--;
				}
			}
			if (cnt > 0) {
				out.println("No");
				return;
			}
		}
		out.println("Yes");
		for (int i = 0; i < n * n; i++) {
			out.printf("%d%c", res[i], " \n".charAt(i == n * n - 1 ? 1 : 0));
		}
	}
	
	public static void main(String[] args) {
		try {
			out = new PrintWriter(System.out);
			//out = new PrintWriter(new FileWriter("a.out"));
		}
		catch (Exception ex) {
		}
		long stime = System.currentTimeMillis();
		Main practice = new Main();
		practice.solve();
		if (System.getProperty("_LOCAL_") != null) {
			out.println("\nTime elapsed: " + (System.currentTimeMillis() - stime) + "ms");
		}
		out.close();
	}
	
	static class Input {
		static StringTokenizer token = null;
		static BufferedReader in;
		static {
			try {
				if (System.getProperty("_LOCAL_") != null) {
					//in = new BufferedReader(new FileReader("in.txt"));
					in = new BufferedReader(new InputStreamReader(System.in));
				}
				else {
					in = new BufferedReader(new InputStreamReader(System.in));
				}
			}
			catch (Exception ex) {
			}
		}
		static int nextInt() {
			return Integer.parseInt(nextString());
		}
		static long nextLong() {
			return Long.parseLong(nextString());
		}
		static double nextDouble() {
			return Double.parseDouble(nextString());
		}
		static String nextString() {
			try {
				while (token == null || !token.hasMoreTokens()) {
					token = new StringTokenizer(in.readLine());
				}
			}
			catch (IOException e) {
			}
			return token.nextToken();
		}
	}
}