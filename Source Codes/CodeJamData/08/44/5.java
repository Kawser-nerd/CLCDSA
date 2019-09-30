import java.util.*;
import java.io.*;

public class PermRLE implements Runnable {
	private final String problemID = getClass().getName();
	private final String problemType = "big";
	private BufferedReader in;
	private PrintWriter out;
	private static final int inf = Integer.MAX_VALUE / 3;
	private int[][] w; 
	private int[][][] addon;
	
	private int calc(int k, String s, int first, int last) {
		for (int mask = 0; mask < (1 << k); mask++) {
			Arrays.fill(w[mask], inf);
		}
		w[(1 << first) | (1 << last)][first] = s.length() / k;
		for (int mask = 0; mask < (1 << k); mask++) {
			if ((mask & (1 << first)) == 0) {
				continue;
			}
			if ((mask & (1 << last)) == 0) {
				continue;
			}
			int place = -2;
			for (int i = 0; i < k; i++) {
				if ((mask & (1 << i)) != 0) {
					place++;
				}
			}
			for (int prev = 0; prev < k; prev++) {
				if ((mask & (1 << prev)) == 0) {
					continue;
				}
				for (int next = 0; next < k; next++) {
					if ((mask & (1 << next)) != 0) {
						continue;
					}
					int newMask = mask | (1 << next);
					int newValue = w[mask][prev] + addon[place][prev][next];
					w[newMask][next] = Math.min(w[newMask][next], newValue);
				}
			}
		}
		int result = inf;
		for (int prev = 0; prev < k; prev++) {
			int cur = w[(1 << k) - 1][prev] + addon[k - 2][prev][last];
			result = Math.min(result, cur);
		}
		return result;
	}

	private void solveSingleTest(int testNumber) throws IOException {
		System.out.println("Test " + testNumber);
		int k = Integer.parseInt(in.readLine());
		String s = in.readLine();
		int ans = Integer.MAX_VALUE;
		w = new int[1 << k][k];
		
		addon = new int[k - 1][k][k];
		for (int p = 0; p + 1 < k; p++) {
			for (int u = 0; u < k; u++) {
				for (int v = 0; v < k; v++) {
					addon[p][u][v] = 0;
					for (int i = 0; i < s.length() / k; i++) {
						char ch1 = s.charAt(i * k + u);
						char ch2 = s.charAt(i * k + v);
						addon[p][u][v] += (ch1 == ch2) ? 0 : 1; 
					}
				}
			}
		}
		for (int first = 0; first < k; first++) {
			for (int last = 0; last < k; last++) {
				if (first == last) {
					continue;
				}
				int cur = calc(k, s, first, last);
				for (int i = 0; i < s.length() / k - 1; i++) {
					char ch1 = s.charAt(i * k + last);
					char ch2 = s.charAt(i * k + k + first);
					if (ch1 == ch2) {
						cur--;
					}
				}
				ans = Math.min(ans, cur);
			}
		}
		out.println("Case #" + testNumber + ": " + ans);
	}
	
	public static void main(String[] args) {
		new Thread(new PermRLE()).start();
	}

	public void run() {
		try {
			solve();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	private void solve() throws IOException {
		in = new BufferedReader(new FileReader(new File(problemID + "_" + problemType + ".in")));
		out = new PrintWriter(new File(problemID + "_" + problemType + ".out"));
		
		int testsNumber = Integer.parseInt(in.readLine());
		for (int i = 0; i < testsNumber; i++) {
			solveSingleTest(i + 1);
		}
		
		in.close();
		out.close();
	}
}
