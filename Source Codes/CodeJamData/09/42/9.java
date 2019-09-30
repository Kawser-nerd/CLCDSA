import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Locale;
import java.util.Queue;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.Map.Entry;

public class Solution implements Runnable {

	public static void main(String[] args) {
		(new Thread(new Solution())).start();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	int n, m, gf;
	boolean[][] map;
	TreeMap<Long, Integer>[][] hs;
	
	boolean bit(long q, int w) {
		return ((q & (1l << w)) != 0);
	}
	
	boolean wall(int i, int j, long q) {
		return !map[i][j] && !bit(q, j);
	}
	
	int rek(int i, int j, long bd, int f) {
		if (f > gf) return Integer.MAX_VALUE / 2;
		if (hs[i][j] != null && hs[i][j].containsKey(bd)) return hs[i][j].get(bd);
		if (i == n - 1) {
			return 0;
		}
		if (!wall(i + 1, j, 0)) {
			return rek(i + 1, j, 0, f + 1);
		} else {
			int ans = Integer.MAX_VALUE / 2;
			long bdn = 0;
			int lx = j;
			while (lx >= 0 && !wall(i, lx, bd) && wall(i + 1, lx, 0)) lx--;
			if (lx >= 0 && !wall(i, lx, bd)) ans = Math.min(ans, rek(i + 1, lx, 0, 1));
			lx++;
			int rx = j;
			while (rx < m && !wall(i, rx, bd) && wall(i + 1, rx, 0)) rx++;
			if (rx < m && !wall(i, rx, bd)) ans = Math.min(ans, rek(i + 1, rx, 0, 1));
			rx--;
			for (int b = lx; b < rx; b++) {
				bdn = 0;
				for (int e = b; e < rx; e++) {
					bdn += (1l << e);
					ans = Math.min(ans, e - b + 1 + rek(i + 1, e, bdn, 1));
				}
			}
			for (int e = rx; e > lx; e--) {
				bdn = 0;
				for (int b = e; b > lx; b--) {
					bdn += (1l << b);
					ans = Math.min(ans, e - b + 1 + rek(i + 1, b, bdn, 1));
				}
			}
			if (hs[i][j] == null) hs[i][j] = new TreeMap<Long, Integer>();
			hs[i][j].put(bd, ans);
			return ans;
		}
	}
	
	void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		gf = nextInt();
		map = new boolean[n][m];
		hs = new TreeMap[n][m];
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			for (int j = 0; j < m; j++) {
				hs[i][j] = null;
				map[i][j] = (s.charAt(j) == '.');
			}
		}
		int q = rek(0, 0, 0, 0);
		if (q == Integer.MAX_VALUE / 2) out.println("No"); else out.println("Yes " + q);
	}
	
	public void run() {
		Locale.setDefault(Locale.UK);
		try {
			if (System.getProperty("ONLINE_JUDGE") != null) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			} else {
				in = new BufferedReader(new FileReader(new File("input.txt")));
				out = new PrintWriter(new FileWriter(new File("output.txt")));
			}
			int t = nextInt();
			for (int nn = 1; nn <= t; nn++) {
				out.print("Case #" + nn + ": ");
				solve();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		out.flush();
	}

}
