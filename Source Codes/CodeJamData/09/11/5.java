import java.io.*;
import java.util.*;
import java.math.*;

public class Happy implements Runnable {

	public static void main(String[] args) {
		new Thread(new Happy()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(this.hashCode());

	@Override
	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
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

	String FNAME = "happy";

	int[][] g = new int[11][100000];

	private void solve() throws IOException {
		int[] a = new int[] { 2, 3, 5, 6, 7, 8, 13, 23, 27, 44, 49, 79, 91, 97,
				125, 143, 167, 216, 219, 415, 608, 707, 1001, 1033, 1177, 1337,
				1695, 1975, 2207, 2753, 3879, 4577, 4977, 5719, 6073, 6307,
				6393, 7895, 9867, 10089, 23117, 28099, 29913, 34527, 35785,
				37131, 47089, 48041, 48769, 58775, 71735, 120149, 120407,
				128821, 218301, 245035, 246297, 346719, 569669, 613479, 697563,
				711725, 2662657, 2688153, 4817803, 11814485 };
		for (int test = 1, testn = nextInt(); test <= testn; test++) {
			out.print("Case #" + test + ": ");
			st = new StringTokenizer(br.readLine());
			ArrayList<Integer> al = new ArrayList<Integer>();
			while (st.hasMoreTokens()) {
				al.add(Integer.parseInt(st.nextToken()));
			}
			for (int i : a) {
				if (good(i, al)) {
					out.println(i);
					break;
				}
			}
		}
	}

	private int solve(ArrayList<Integer> al) {
		int ans = 2;
		while (!good(ans, al)) {
			ans++;
		}
		return ans;
	}

	private boolean good(int x, ArrayList<Integer> al) {
		for (int i : al) {
			if (!good(x, i)) {
				return false;
			}
		}
		return true;
	}

	private boolean good(int x, int b) {
		if (x < g[b].length && g[b][x] == -2) {
			return false;
		}
		if (x < g[b].length) {
			g[b][x] = -2;
		}
		if (x < g[b].length && g[b][x] >= 0) {
			return g[b][x] == 1;
		}
		char[] c = Integer.toString(x, b).toCharArray();
		int y = 0;
		for (int i = 0; i < c.length; i++) {
			y += (c[i] - '0') * (c[i] - '0');
		}
		if (x < g[b].length) {
			g[b][x] = (y == 1 || good(y, b)) ? 1 : 0;
		}
		return x < g[b].length ? g[b][x] == 1 : (y == 1 || good(y, b));
	}
}
