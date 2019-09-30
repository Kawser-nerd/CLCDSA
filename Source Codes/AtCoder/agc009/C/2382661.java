import java.io.*;
import java.util.*;
public class Main {
	public static void main(String args[]) {
		Solver_agc009c solver = new Solver_agc009c();
		solver.input();
		solver.solve();
	}
}
class FastScanner {
	BufferedReader br;
	StringTokenizer st;
	public FastScanner(Reader in) {
		br = new BufferedReader(in);
	}

	String next() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				e.printStackTrace();
				throw new RuntimeException("Can't read more inputs.");
			}
		}
		return st.nextToken();
	}
	int nextInt() {
		return Integer.parseInt(next());
	}
	long nextLong() {
		return Long.parseLong(next());
	}
	double nextDouble() {
		return Double.parseDouble(next());
	}
	String readNextLine() {
		String str = "";
		try {
			str = br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return str;
	}
}
class Solver_agc009c {
	static FastScanner in = new FastScanner(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	final int mod = (int)1e9 + 7;
	int n;
	long a, b, s[];
	int f[], g[], sum_f[], sum_g[];
	void input() {
		n = in.nextInt();
		a = in.nextLong();
		b = in.nextLong();
		s = new long[n + 1];
		for(int i = 0; i < n; i++) s[i] = in.nextLong();
		s[n] = Long.MAX_VALUE;
		f = new int[n + 1];
		g = new int[n + 1];
		sum_f = new int[n + 1];
		sum_g = new int[n + 1];
	}
	int addmod(int a, int b) { return (a + b) % mod; }
	void solve() {
		f[n - 1] = g[n - 1] = 1;
		sum_f[n - 1] = sum_g[n - 1] = 1;
		int l_f = n, r_f = n, l_g = n, r_g = n;
		for(int i = n - 2; i >= 0; i--) {
			while(l_f - 1 > i + 1 && s[l_f - 1] - s[i] >= a) l_f--;
			while(l_g - 1 > i + 1 && s[l_g - 1] - s[i] >= b) l_g--;
			if(s[i + 2] - s[i + 1] < b) r_f = i + 2;
			if(s[i + 2] - s[i + 1] < a) r_g = i + 2;
			if(l_f <= r_f) {
				f[i] = addmod(sum_g[l_f - 1], mod - sum_g[r_f]);
			}
			if(l_g <= r_g) {
				g[i] = addmod(sum_f[l_g - 1], mod - sum_f[r_g]);
			}
			sum_f[i] = addmod(f[i], sum_f[i + 1]);
			sum_g[i] = addmod(g[i], sum_g[i + 1]);
		}
		int ans = addmod(f[0], g[0]);
		for(int i = 1; i < n; i++) {
			if(s[i] - s[i - 1] < a) break;
			ans = addmod(ans, f[i]);
		}
		for(int i = 1; i < n; i++) {
			if(s[i] - s[i - 1] < b) break;
			ans = addmod(ans, g[i]);
		}
		out.println(ans);
		out.close();
	}
}