import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import java.util.StringTokenizer;

public class Solution implements Runnable {
	
	private static final int MOD = 1000002013;
	
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private int solve(int n, int[][] pairs) {
		long answer1 = 0;
		int[][] events = new int[pairs.length * 2][];
		for (int i = 0; i < pairs.length; i++) {
			events[2 * i + 0] = new int[] {pairs[i][0], pairs[i][2]};
			events[2 * i + 1] = new int[] {pairs[i][1], -pairs[i][2]};
			int dist = pairs[i][1] - pairs[i][0];
			answer1 = (answer1 + (cost(dist, n) * pairs[i][2]) % MOD) % MOD;
		}
		Arrays.sort(events, new Comparator<int[]>() {
			@Override
			public int compare(int[] arg0, int[] arg1) {
				if (arg0[0] < arg1[0]) {
					return -1;
				}
				if (arg0[0] > arg1[0]) {
					return 1;
				}
				if (arg0[1] > arg1[1]) {
					return -1;
				}
				if (arg0[1] < arg1[1]) {
					return 1;
				}
				return 0;
			}
		});
		long answer2 = 0;
		int[] ticketStart = new int[pairs.length];
		int[] ticketCount = new int[pairs.length];
		int tickets = 0;
		for (int i = 0; i < events.length; i++) {
			if (events[i][1] > 0) {
				ticketStart[tickets] = events[i][0];
				ticketCount[tickets] = events[i][1];
				tickets++;
			} else {
				while (events[i][1] < 0) {
					int exit = Math.min(-events[i][1], ticketCount[tickets - 1]);
					events[i][1] += exit;
					ticketCount[tickets - 1] -= exit;
					int dist = events[i][0] - ticketStart[tickets - 1];
					answer2 = (answer2 + (cost(dist, n) * exit) % MOD) % MOD;
					if (ticketCount[tickets - 1] == 0) {
						tickets--;
					}
				}
			}
		}
		return (int) (((answer1 - answer2) % MOD + MOD) % MOD);
	}
	
	private long cost(int dist, int n) {
		long base = (n + 1L) * dist;
		long sub = (dist * (dist - 1L)) / 2;
		return ((base - sub) % MOD + MOD) % MOD;
	}

	private void solve() throws IOException {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			int n = nextInt();
			int m = nextInt();
			int[][] pairs = new int[m][3];
			for (int i = 0; i < m; i++) {
				pairs[i][0] = nextInt();
				pairs[i][1] = nextInt();
				pairs[i][2] = nextInt();
			}
			int answer = solve(n, pairs);
			out.println("Case #" + test + ": " + answer);
		}
	}

	@Override
	public void run() {
		try {
			solve();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		} finally {
			out.close();
		}
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	public Solution(String filename) {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(filename + ".out"));
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Solution("data").run();
	}
}
