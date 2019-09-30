import java.util.*;
import java.text.*;
import java.io.*;
import java.text.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;

public class Main implements Runnable {

	static String code = "c2";

	static String inpFile = code + ".in";

	static String outFile = code + ".out";

	public static void main(String[] args) throws IOException {
		fr = new FileReader(inpFile);
		br = new BufferedReader(fr);
		out = new PrintWriter(outFile);
		con = new PrintWriter(System.out);
		new Thread(new Main()).start();
	}

	static FileReader fr;

	static BufferedReader br;

	static PrintWriter out;

	static PrintWriter con;

	static StringTokenizer st;

	void msg(String s) {
		con.println(s);
		con.flush();
	}

	static String nt() {
		while (st == null || !st.hasMoreTokens()) {
			String s = null;
			try {
				s = br.readLine();
			} catch (Exception ex) {
				s = null;
			}
			st = new StringTokenizer(s);
		}
		return st.nextToken();
	}

	int ni() {
		return Integer.parseInt(nt());
	}

	long nl() {
		return Long.parseLong(nt());
	}

	boolean eof() {
		boolean ready = false;
		try {
			ready = br.ready();
		} catch (IOException ex) {
			ready = false;
		}
		return !(ready || (st != null && st.hasMoreTokens()));
	}

	long p = 1000000009L;
	int n, k;
	LinkedList<Integer> e[];
	boolean[] w;

	long F(int n, int k1, int k2) {
		if (k1 + k2 > n)
			return 0;
		long ans = 1;
		for (long i = n - k1 - k2 + 1; i <= n - k1; i++) {
			ans *= i;
			ans %= p;
		}
		return ans;
	}

	long count(int cur, int par) {
		long ans = 1;
		w[cur] = true;
		for (int v : e[cur]) {
			if (!w[v]) {
				ans *= count(v, cur);
				ans %= p;
			}
		}
		if (par >= 0) {
			ans *= F(k, e[par].size(), e[cur].size() - 1);
		} else {
			ans *= k;
		}
		ans %= p;
		return ans;
	}

	public void solution() {
		n = ni();
		k = ni();
		e = new LinkedList[n];
		w = new boolean[n];
		for (int i = 0; i < n; i++) {
			e[i] = new LinkedList<Integer>();
		}
		for (int i = 0; i < n - 1; i++) {
			int u = ni() - 1;
			int v = ni() - 1;
			e[u].add(v);
			e[v].add(u);
		}
		int start = 0;
		for (int i = 0; i < n; i++) {
			if (e[i].size() == 1) {
				start = i;
				break;
			}
		}
		if (n == 2)
			out.println(k);
		else
			out.print(count(start, -1));

	}

	public void run() {
		int T = ni();
		for (int i = 1; i <= T; i++) {
			out.print("Case #" + i + ": ");
			solution();
			out.println();
		}
		if (out != null)
			out.close();
		if (con != null)
			con.close();
	}
}
