import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		long X = sc.nextLong();
		int K = sc.nextInt();
		long[] r = new long[K];
		for (int i = 0; i < K; ++i) {
			r[i] = sc.nextLong();
		}
		int Q = sc.nextInt();
		long[] t = new long[Q];
		long[] a = new long[Q];
		for (int i = 0; i < Q; ++i) {
			t[i] = sc.nextLong();
			a[i] = sc.nextLong();
		}
		solve(X, K, r, Q, t, a);

	}

	class Query implements Comparable<Query> {
		int type;// 0:turn,1:answer
		long t = -1;
		long a = -1;

		public Query(int type_, long v_, long a_) {
			type = type_;
			if (type == 0) {
				t = v_;
			} else {
				t = v_;
				a = a_;
			}
		}

		@Override
		public int compareTo(Query o) {
			if (t != o.t) {
				return Long.compare(t, o.t);
			} else {
				return -Long.compare(type, o.type);
			}
		}
	}

	void solve(long X, int K, long[] r, int Q, long[] t, long[] a) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		PriorityQueue<Query> pq = new PriorityQueue<>();
		for (int i = 0; i < K; ++i) {
			pq.add(new Query(0, r[i], -1));
		}
		for (int i = 0; i < Q; ++i) {
			pq.add(new Query(1, t[i], a[i]));
		}

		int coe = -1;
		long upper = X;
		long lower = 0;
		long preR = 0;
		long upperpos = X;
		long lowerpos = 0;
		while (!pq.isEmpty()) {
			Query q = pq.poll();
			if (q.type == 1) {
				long ans = -1;
				if (lower > upper) {
					if (coe == 1) {
						ans = Math.min(q.t - preR + lowerpos, X);
					} else {
						ans = Math.max(-(q.t - preR) + lowerpos, 0);
					}
					pw.println(ans);
					continue;
				}
				if (lower > q.a) {
					q.a = lower;
				} else if (upper < q.a) {
					q.a = upper;
				}
				if (coe == 1) {
					ans = Math.min(X, (q.a - lower) + lowerpos + coe * (q.t - preR));
				} else {
					ans = Math.max(0, (q.a - lower) + lowerpos + coe * (q.t - preR));
				}
				pw.println(ans);
			} else {
				long d = q.t - preR;
				if (lower < upper) {
					if (coe == -1) {
						if (lowerpos < d) {
							lower = lower + (d - lowerpos);
						}
					} else {
						if (upperpos > X - d) {
							upper = upper - (upperpos - (X - d));
						}
						if (upper < lower) {
							lower = X;
						}
					}
					lower = Math.min(lower, X);
					upper = Math.min(upper, X);
					lower = Math.max(lower, 0);
					upper = Math.max(upper, 0);
				}

				lowerpos += d * coe;
				upperpos += d * coe;
				lowerpos = Math.max(lowerpos, 0);
				upperpos = Math.max(upperpos, 0);
				lowerpos = Math.min(lowerpos, X);
				upperpos = Math.min(upperpos, X);

				preR = q.t;
				coe *= -1;
			}
		}
		pw.close();
	}

	long bruteForce(long a, long t, long X, long[] r) {
		long cur = a;
		int coe = -1;
		long j = 0;
		for (int i = 0; i < r.length; ++i) {
			if (r[i] >= t)
				break;
			cur += coe * (r[i] - (i > 0 ? r[i - 1] : 0));
			cur = Math.min(cur, X);
			cur = Math.max(cur, 0);
			coe *= -1;
			j = r[i];
		}
		cur += coe * (t - j);
		cur = Math.min(cur, X);
		cur = Math.max(cur, 0);
		return cur;
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}