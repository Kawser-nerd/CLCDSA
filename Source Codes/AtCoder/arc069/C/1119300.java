import java.util.Scanner;
import java.util.TreeSet;

public class Main {
	public static void main(String[] args) {
		Main m = new Main();
		m.solve();
	}

	private void solve() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] a = new int[N];
		int[] mx = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
			if (i == 0) {
				mx[i] = a[i];
			} else {
				mx[i] = Math.max(mx[i - 1], a[i]);
			}
		}
		sc.close();

		long[] cnt = new long[N];

		TreeSet<Count> set = new TreeSet<>();
		long upCnt = 0;
		int cur = Integer.MAX_VALUE;
		for (int i = N - 1; i >= 0; i--) {
			int next = 0;
			Count c = set.ceiling(new Count(a[i], 0));
			if (c == null || c.num != a[i]) {
				set.add(new Count(a[i], 1));
			} else {
				set.remove(c);
				c.cnt += 1;
				set.add(c);
			}
			if (i == 0) {
				next = 0;
			} else {
				if (cur == mx[i - 1]) {
					continue;
				}
				next = mx[i - 1];
			}
			cnt[i] = upCnt * (mx[i] - next);
			while ((c = set.lower(new Count(mx[i] + 1, 0))) != null) {
				if (c.num <= next) {
					break;
				}
				cnt[i] += ((long) c.num - next) * c.cnt;
				cur = c.num;
				set.remove(c);
				upCnt += c.cnt;
			}
			cur = next;
		}
		StringBuffer buf = new StringBuffer();
		for (int i = 0; i < N; i++) {
			buf.append(Long.toString(cnt[i]));
			buf.append("\n");
		}
		System.out.println(buf.toString());
	}

	class Count implements Comparable<Count> {
		int num = 0;
		int cnt = 0;

		Count(int num, int cnt) {
			this.num = num;
			this.cnt = cnt;
		}

		@Override
		public int compareTo(Count o) {
			if (this.num != o.num) {
				return this.num - o.num;
			} else {
				return this.cnt - o.cnt;
			}
		}

		@Override
		public boolean equals(Object o) {
			if (o instanceof Count) {
				Count c = (Count) o;
				return c.num == this.num && c.cnt == this.cnt;
			} else {
				return false;
			}
		}
	}
}