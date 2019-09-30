import java.io.*;
import java.util.*;

public class B {

	private void solve() throws IOException {
		int n = nextInt();
		if (n == 0) {
			out.println(0);
			return;
		}
		int[] cnt = new int[10000 + 2];
		for (int i = 0; i < n; i++) {
			cnt[nextInt()]++;
		}
		int res = 200000;
		for (int i = 0; i < cnt.length;) {
			if (cnt[i] > 0) {
				int j = i;
				while (cnt[j] > 0) {
					j++;
				}
				int[] arr = Arrays.copyOfRange(cnt, i, j);
				res = Math.min(res, straight(arr));
				i = j;
			} else {
				i++;
			}
		}
		out.println(res);
	}

	static class Event {
		int x, val;

		public Event(int x, int val) {
			this.x = x;
			this.val = val;
		}
	}

	int straight(int[] a) {
		ArrayList<Event> plus = new ArrayList<B.Event>();
		ArrayList<Event> minus = new ArrayList<B.Event>();
		plus.add(new Event(0, a[0]));
		for (int i = 1; i < a.length; i++) {
			if (a[i] > a[i - 1]) {
				plus.add(new Event(i, a[i] - a[i - 1]));
			}
			if (a[i] < a[i - 1]) {
				minus.add(new Event(i, -a[i] + a[i - 1]));
			}
		}
		minus.add(new Event(a.length, a[a.length - 1]));

		int b = 0;
		int res = a.length + 100;
		for (int i = 0; i < plus.size(); i++) {
			Event t = plus.get(i);
			int cnt = t.val;
			while (cnt > 0) {
				int tmp = minus.get(b).val;
				tmp = Math.min(tmp, cnt);
				minus.get(b).val -= tmp;
				cnt -= tmp;
				res = Math.min(res, minus.get(b).x - t.x);
				if (minus.get(b).val == 0)
					b++;
			}
		}
		return res;
	}

	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	static final boolean large = true;

	public void run() {
		try {
			String fileName = "B-" + (large ? "large" : "small");
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			st = new StringTokenizer("");
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

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}