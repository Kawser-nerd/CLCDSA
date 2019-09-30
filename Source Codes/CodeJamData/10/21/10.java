import static java.lang.Integer.parseInt;

import java.io.*;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Directory {
		final Map<String, Directory> children = new HashMap<String, Directory>();
		
		int create(String path) {
			while (path.length() > 0 && path.charAt(0) == '/') {
				path = path.substring(1);
			}
			if (path.length() == 0) {
				return 0;
			}
			int pos = path.indexOf('/');
			String name;
			if (pos < 0) {
				name = path;
				path = null;
			} else {
				name = path.substring(0, pos);
				path = path.substring(pos + 1);
			}
			int ans = 0;
			if (!children.containsKey(name)) {
				children.put(name, new Directory());
				ans = 1;
			}
			if (path != null) {
				ans += children.get(name).create(path);
			}
			return ans;
		}
	}
	
	static void solveTest() throws Exception {
		int n = nextInt();
		int m = nextInt();
		Directory root = new Directory();
		for (int i = 0; i < n; i++) {
			root.create(in.readLine());
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			ans += root.create(in.readLine());
		}
		out.println(ans);
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
		}
	}

	public static void main(String[] args) throws Exception {
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
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}