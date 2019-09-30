import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class a {
	
	int n, m;
	TreeSet<String> dir;

	private void solve() throws Exception {
		n = nextInt(); m = nextInt();
		dir = new TreeSet<String>();
		dir.add("/");
		for (int i = 0; i < n; ++i){
			String s = in.readLine().trim();
			add(s);
		}
		int init = dir.size();
		for (int i = 0; i < m; ++i){
			String s = in.readLine().trim();
			add(s);
		}
		out.println(dir.size() - init);
	}

	private void add(String s) {
		String[] tok = s.split("/");
		String cur = "";
		for (int i = 1; i < tok.length; ++i){
			cur += "/" + tok[i];
			dir.add(cur);
		}
	}

	public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(1);
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private a(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new a("a").run();
	}

}
