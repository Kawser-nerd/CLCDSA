import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class C implements Runnable {

	public static void main(String[] args) {
		new Thread(new C()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public final boolean large = false;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			String FN = "C-" + (large ? "large" : "small");
			br = new BufferedReader(new FileReader(FN + ".in"));
			out = new PrintWriter(FN + ".out");
			int T = nextInt();
			for (int i = 1; i <= T; i++) {
				out.print("Case #" + i + ": ");
				solve();
			}
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
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

	private void solve() throws IOException {
		int c = nextInt();
		HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
		for (int i = 0; i < c; i++) {
			int p = nextInt(), v = nextInt();
			hm.put(p, v);
		}

		int ans = 0;
		while (true) {
			int p = -1, v = -1;
			for (Entry<Integer, Integer> e : hm.entrySet()) {
				if (e.getValue() >= 2) {
					p = e.getKey();
					v = e.getValue();
					break;
				}
			}
			if (v == -1)
				break;
			ans++;
			hm.remove(p);
			hm.put(p, v - 2);
			Integer prev = hm.get(p - 1), next = hm.get(p + 1);
			if (prev == null) {
				prev = 0;
			}
			if (next == null)
				next = 0;
			hm.put(p - 1, prev + 1);
			hm.put(p + 1, next + 1);
		}
		out.println(ans);
	}
}