import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class Solution implements Runnable {

	private static final int INF = (int) 1e9;

	void solve() throws Exception {
		int tc = nextInt();
		for (int tt = 0; tt < tc; tt++) {
			int n = nextInt();
			HashMap<String, Integer> map = new HashMap<String, Integer>();
			int[][] offer = new int[n][3];
			for (int i = 0; i < n; i++) {
				String color = nextToken();
				int a = nextInt();
				int b = nextInt();
				Integer num = map.get(color);
				if (num == null) {
					num = map.size();
					map.put(color, num);
				}
				offer[i] = new int[] {num, a, b};
			}
			int ans = INF;
			for (int mask = 0; mask < (1 << n); mask++) {
				int[] fence = new int[10001];
				TreeSet<Integer> colors = new TreeSet<Integer>();
				int cur = 0;
				for (int i = 0; i < n; i++) {
					if ((mask & (1 << i)) != 0) {
						cur++;
						for (int j = offer[i][1]; j <= offer[i][2]; j++) {
							fence[j]++;
						}
						colors.add(offer[i][0]);
					}
				}
				boolean good = true;
				for (int i = 1; i <= 10000; i++) {
					if (fence[i] == 0) {
						good = false;
						break;
					}
				}
				good &= colors.size() <= 3;
				if (good) {
					ans = Math.min(ans, cur);
				}
			}
			out.print("Case #" + (tt + 1) + ": ");
			if (ans == INF) {
				out.println("IMPOSSIBLE");
			} else {
				out.println(ans);
			}
		}
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new Thread(new Solution("b")).start();
	}

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;

	public Solution(String fname) throws IOException {
		in = new BufferedReader(new FileReader(fname + ".in"));
		st = new StringTokenizer("");
		out = new PrintWriter(new FileWriter(fname + ".out"));
	}


	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}

	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	public void run() {
		try {
			solve();
		} catch (Exception e) {
			apstenu(e);
		} finally {
			out.close();
		}
	}

	private void apstenu(Exception e) {
		e.printStackTrace();
		System.exit(1);
	}

}
