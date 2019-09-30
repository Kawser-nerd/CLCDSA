import java.io.*;
import java.util.*;

public class Wheel {
	public static void main(String[] args) {
		new Wheel().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	private void run() {
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

	String FNAME = "d";
	int n;

	private void solve() throws IOException {
		for (int test = 1, testn = nextInt(); test <= testn; test++) {
			out.print("Case #" + test + ": ");
			System.out.println("Case #" + test + ": ");
			char[] s = nextToken().toCharArray();
			n = s.length;
			int prof = 0;
			for (int i = 0; i < s.length; i++) {
				if (s[i] == 'X') {
					prof |= 1 << i;
				}
			}
			prof = min(prof);
			map = new HashMap<>();
			count(prof);
			out.println(map.get(prof));
		}
	}

	private void count(int prof) {
		if (prof == ((1 << n) - 1)) {
			map.put(prof, 0.0);
		}
		if (map.containsKey(prof)) {
			return;
		}
		double win = 0;
		for (int i = n - 1; i >= 0; i--) {
			if ((prof & (1 << i)) == 0) {
				int prof2 = min(prof | (1 << i));
				count(prof2);
				win += 1.0 / n * (n + map.get(prof2));
				for (int j = i - 1; j >= 0 && (prof & (1 << j)) != 0; j--) {
					win += 1.0 / n * ((n - (i - j)) + map.get(prof2));
				}
			}
		}
		map.put(prof, win);
	}

	HashMap<Integer, Double> map;

	private int min(int prof) {
		int ans = prof;
		for (int i = 0; i < n; i++) {
			prof = (prof >> 1) | ((prof & 1) << (n - 1));
			ans = Math.min(ans, prof);
		}
		return ans;
	}
}
