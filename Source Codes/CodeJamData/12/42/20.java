import java.lang.*;
import java.io.*;
import java.util.*;

public class Solution {
	public static BufferedReader br;
	public static PrintWriter out;
	public static StringTokenizer stk;

	// ///////////////// TO CHANGE ///////////////////////////
	public static boolean isServer = false;

	// ///////////////// TO CHANGE ///////////////////////////

	public static void main(String[] args) throws IOException {
		if (isServer) {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
			br = new BufferedReader(new FileReader("in.txt"));
			out = new PrintWriter(new File("out.txt"));
		}

		(new Solution()).run();
	}

	public void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public String nextLine() {
		try {
			return br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
			return "";
		}
	}

	public String nextWord() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return stk.nextToken();
	}

	public Integer nextInt() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Integer.valueOf(stk.nextToken());
	}

	public Long nextLong() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Long.valueOf(stk.nextToken());
	}

	public Double nextDouble() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Double.valueOf(stk.nextToken());
	}

	public Float nextFloat() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Float.valueOf(stk.nextToken());
	}
	
	int n;
	long w, l;
	long[] r;
	boolean[] used;
	long[] px, py;
	long[] apx, apy;
	boolean ans = false;
	
	void dfs(int cnt, long x) {
		if (ans) return;
		if (cnt == n) {
			apx = px.clone();
			apy = py.clone();
			ans = true;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				long nx = x;
				if (nx > 0)  nx += r[i];
				if (nx <= w) {
					long minY = 0;
					for (int j = 0; j < n; j++) {
						if (used[j] && px[j] + r[j] + r[i] > nx) {
							minY = Math.max(py[j] + r[j] + r[i], minY);
						}
					}
					long ny = minY;
					if (minY <= l) {
						used[i] = true;
						px[i] = nx;
						py[i] = ny;
						dfs(cnt+1, nx + r[i]);
						dfs(cnt+1, 0);
						used[i] = false;
					}
				}
			}
		}
	}
	
	public void run() {
		int tt = nextInt();
		for (int t = 0; t < tt; t++) {
			n = nextInt();
			w = nextInt(); l = nextInt();
			r = new long[n];
			for (int i = 0; i < n; i++) {
				r[i] = nextInt();
			}
			px = new long[n];
			py = new long[n];
			apx = null;
			apy = null;
			used = new boolean[n];
			ans = false;
			dfs(0, 0);
			out.printf("Case #%d:", t+1);
			for (int i = 0; i < n; i++) {
				out.print(' ');
				out.print(apx[i]);
				out.print(' ');
				out.print(apy[i]);
			}
			out.println();
		}
		out.flush();
	}
}
