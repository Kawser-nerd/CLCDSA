import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		System.out.println(solve(sc.nextLine(), sc.nextLine()));
	}

	long solve(String A, String B) {
		Scanner sc = new Scanner(System.in);
		int n = A.length();
		String BBB = B + B + B;
		int[] prev1 = new int[BBB.length()];
		int[] next1 = new int[BBB.length()];
		for (int i = 0; i < BBB.length(); ++i) {
			if (BBB.charAt(i) == '1') {
				prev1[i] = i;
			} else {
				if (i > 0) {
					prev1[i] = prev1[i - 1];
				} else {
					prev1[i] = -1;
				}
			}
		}
		for (int i = BBB.length() - 1; i >= 0; --i) {
			if (BBB.charAt(i) == '1') {
				next1[i] = i;
			} else {
				if (i + 1 < BBB.length()) {
					next1[i] = next1[i + 1];
				} else {
					next1[i] = BBB.length();
				}
			}
		}

		long ans = Long.MAX_VALUE;
		out: for (int rot = -n; rot <= n; ++rot) {
			boolean[] distinct = new boolean[n];
			int n10 = 0, n01 = 0;
			for (int i = 0; i < n; ++i) {
				if (A.charAt(i) == BBB.charAt((i + n) + rot)) {
					continue;
				}
				distinct[i] = true;
				if (A.charAt(i) == '0') {
					++n01;
				} else {
					++n10;
				}
			}
			int[] left = new int[n];
			int[] right = new int[n];
			for (int i = 0; i < n; ++i) {
				if (!distinct[i])
					continue;
				if (next1[0] == BBB.length()) {
					continue out;
				}
				left[i] = ((i + n) + rot) - prev1[(i + n) + rot];
				right[i] = next1[(i + n) + rot] - ((i + n) + rot);
				if (rot > 0) {
					left[i] = Math.max(0, left[i] - rot);
				} else {
					right[i] = Math.max(0, right[i] + rot);
				}
			}
			ans = Math.min(ans, 2 * f(left, right) + n10 + n01 + Math.abs(rot));
		}
		return (ans > 2 * n ? -1 : ans);
	}

	long f(int[] left, int[] right) {
		class Pair implements Comparable<Pair> {
			int left;
			int right;

			public Pair(int left_, int right_) {
				left = left_;
				right = right_;
			}

			public int compareTo(Pair o) {
				if (left != o.left)
					return Integer.compare(left, o.left);
				else
					return Integer.compare(right, o.right);
			};
		}
		int n = left.length;
		ArrayList<Pair> list = new ArrayList<>();
		for (int i = 0; i < n; ++i) {
			list.add(new Pair(left[i], right[i]));
		}
		Collections.sort(list);
		for (int i = (list.size() - 2); i >= 0; --i) {
			if (list.get(i).right <= list.get(i + 1).right) {
				list.remove(i);
			}
		}

		long ret = Long.MAX_VALUE;
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		for (int i = 0; i < list.size(); ++i) {
			pq.add(list.get(i));
		}
		Pair pre = null;
		while (!pq.isEmpty()) {
			Pair pair = pq.poll();
			if (pre == null) {
				ret = Math.min(ret, pair.right);
			} else {
				ret = Math.min(ret, pair.right + pre.left);
			}
			if (pq.isEmpty()) {
				ret = Math.min(ret, pair.left);
			}
			pre = pair;
		}
		return ret;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}