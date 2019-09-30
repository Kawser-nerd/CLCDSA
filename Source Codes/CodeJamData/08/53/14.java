import java.util.*;
import java.text.*;
import java.io.*;
import java.text.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;

public class Main implements Runnable {

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		// br = new BufferedReader(new InputStreamReader(System.in));
		br = new BufferedReader(new FileReader(inpFile));
		st = new StreamTokenizer(br);
		// out = new PrintWriter(System.out);
		out = new PrintWriter(outFile);
		new Thread(new Main()).start();
	}

	static String taskID = "1";

	static String inpFile = taskID + ".in";

	static String outFile = taskID + ".out";

	static BufferedReader br;

	static PrintWriter out;

	static StreamTokenizer st;

	static void nt() {
		try {
			st.nextToken();
		} catch (IOException ex) {
		}
	}

	int ni() {
		nt();
		return (int) st.nval;
	}

	long nl() {
		nt();
		return (long) st.nval;
	}

	String ns() {
		nt();
		return st.sval;
	}

	double nd() {
		nt();
		return st.nval;
	}

	String nline() {
		try {
			return br.readLine();
		} catch (IOException ex) {
			return null;
		}
	}

	boolean ok(int x, int pr, int m, char[] p) {
		boolean was = false;
		for (int i = 0; i < m; i++) {
			if ((x & (1 << i)) > 0) {
				if (was)
					return false;
				if (p[i] == 'x')
					return false;
				if (i > 0) {
					if ((pr & (1 << (i - 1))) > 0) {
						return false;
					}
				}
				if (i < m - 1) {
					if ((pr & (1 << (i + 1))) > 0) {
						return false;
					}
				}
				was = true;
			} else {
				was = false;
			}
		}
		return true;
	}

	int cnt(int x, int m) {
		int ans = 0;
		for (int i = 0; i < m; i++) {
			if ((x & (1 << i)) > 0) {
				ans++;
			}
		}
		return ans;
	}

	int comp() {
		String[] mas = nline().trim().split(" +");
		int n = Integer.parseInt(mas[0]);
		int m = Integer.parseInt(mas[1]);
		char[][] p = new char[n][];
		for (int i = 0; i < n; i++) {
			p[i] = nline().trim().toCharArray();
		}
		int[][] a = new int[n][1 << m];
		for (int i = 0; i < 1 << m; i++) {
			if (ok(i, 0, m, p[0])) {
				a[0][i] = cnt(i, m);
			}
		}
		for (int i = 1; i < n; i++) {
			for (int v = 0; v < 1 << m; v++) {
				for (int j = 0; j < 1 << m; j++) {
					if (ok(v, j, m, p[i]) && ok(j, 0, m, p[i - 1])) {
						a[i][v] = max(a[i][v], a[i - 1][j] + cnt(v, m));
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < 1 << m; i++) {
			ans = max(ans, a[n - 1][i]);
		}
		return ans;
	}

	public void run() {
		int T = Integer.parseInt(nline().trim());
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			out.println(comp());
		}
		out.close();
	}
}
