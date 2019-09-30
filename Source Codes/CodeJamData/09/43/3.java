import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "C-large";

	int N;
	boolean[][] ss;
	boolean[] was;
	int[] M;

	boolean khun(int x) {
		if (was[x])
			return false;
		was[x] = true;
		for (int y = 0; y < N; y++)
			if (ss[x][y] && (M[y] == -1 || khun(M[y]))) {
				M[y] = x;
				return true;
			}
		return false;
	}

	public void solve() throws Exception {
		int ntests = iread();
		for (int ntest = 1; ntest <= ntests; ntest++) {
			N = iread();
			int K = iread();
			int[][] p = new int[N][K];
			for (int i = 0; i < N; i++)
				for (int j = 0; j < K; j++)
					p[i][j] = iread();
			ss = new boolean[N][N];
			for (int i = 0; i < N; i++)
				Arrays.fill(ss[i], true);
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					for (int k = 0; k < K; k++)
						if (p[i][k] >= p[j][k])
							ss[i][j] = false;
			was = new boolean[N];
			M = new int[N];
			Arrays.fill(M, -1);
			for (int i = 0; i < N; i++) {
				Arrays.fill(was, false);
				khun(i);
			}
			int ans = 0;
			for (int i=0; i<N;i++)
				if (M[i]==-1)
					ans++;
			out.write("Case #"+ntest+": "+ans+"\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(taskname + ".in"));
			out = new BufferedWriter(new FileWriter(taskname + ".out"));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		// Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}
}