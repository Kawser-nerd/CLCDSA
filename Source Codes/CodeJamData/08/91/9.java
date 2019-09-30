import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main implements Runnable {

	public static void main(String[] args) {
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			solve();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	BufferedReader br;
	PrintWriter pw;

	private void solve() throws Exception {
		br = new BufferedReader(new FileReader("a.in"));
		pw = new PrintWriter("a.out");

		int tests = Integer.parseInt(br.readLine().trim());
		for (int test = 1; test <= tests; test++) {
			pw.print("Case #" + test + ": ");
			runtest();
		}

		br.close();
		pw.close();
	}

	class Item implements Comparable<Item>{
		int x, t;

		public int compareTo(Item o) {
			if (x != o.x) {
				return x - o.x;
			}
			return t - o.t;
		}

	}

	private void runtest() throws Exception {
		int n = Integer.parseInt(br.readLine().trim());
		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			a[i] = Integer.parseInt(st.nextToken());
			b[i] = Integer.parseInt(st.nextToken());
			c[i] = Integer.parseInt(st.nextToken());
		}

		int res = 0;
		Item[] items = new Item[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			items[i] = new Item();
		}

		for (int ai = 0; ai < n; ai++) {
			int A = a[ai];
			int count = 0;
			for (int i = 0; i < n; i++) {
				int l = b[i];
				int r = 10000 - A - c[i];
				if (l <= r && A >= a[i]) {
					items[count].x = l;
					items[count].t = 1;
					count++;
					items[count].x = r + 1;
					items[count].t = 2;
					count++;
				}
			}
			Arrays.sort(items, 0, count);
			int cur = 0;
			int best = 0;
			int i = 0;
			while (i < count) {
				int v = items[i].x;
				while (i < count && items[i].x == v) {
					if (items[i].t == 1) {
						cur++;
					}
					if (items[i].t == 2) {
						cur--;
					}
					i++;
				}
				if (cur > best) {
					best = cur;
				}
			}
			if (best > res) {
				res = best;
			}
		}

		pw.println(res);
	}

}
