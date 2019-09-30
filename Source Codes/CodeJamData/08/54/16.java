import java.util.*;
import java.text.*;
import java.io.*;
import java.text.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;

public class Main implements Runnable {

	public static void main(String[] args) throws IOException {
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

	int[] di = new int[] { 1, 2 };
	int[] dj = new int[] { 2, 1 };

	long modulo = 10007;

	long comp() {
		int h = ni();
		int w = ni();
		int r = ni();
		boolean[][] f = new boolean[h][w];
		for (int i = 0; i < r; i++) {
			int x = ni() - 1;
			int y = ni() - 1;
			f[x][y] = true;
		}
		long[][] a = new long[h][w];
		a[0][0] = 1;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				for (int v = 0; v < 2; v++) {
					int ii = i + di[v];
					int jj = j + dj[v];
					if (ii >= 0 && jj >= 0 && ii < h && jj < w && !f[ii][jj]) {
						a[ii][jj] += a[i][j];
						a[ii][jj] %= modulo;
					}
				}
			}
		}
		return a[h - 1][w - 1] % modulo;
	}

	public void run() {
		int T = ni();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			long ans = comp();
			out.println(ans);
		}
		out.close();
	}
}
