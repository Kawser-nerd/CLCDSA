import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class EqualSumsHard {
	public static void main(String[] args) throws Throwable {
		Scanner in = new Scanner(new File("eqsums.in"));
		PrintWriter out = new PrintWriter("eqsums.out");
		int testCount = Integer.parseInt(in.nextLine().trim());
		for (int i = 0; i < testCount; i++) {
			System.err.println("Test case #" + (i + 1));
			out.println("Case #" + (i + 1) + ":");
			solve(in, out);
		}
		out.close();
	}

	static final Random rand = new Random(123123L);

	static void solve(Scanner in, PrintWriter out) {
		int n = in.nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextLong();
		}
		for (int i = 1; i < n; i++) {
			int j = rand.nextInt(i + 1);
			long t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		final int ALL = 10000000;
		SubSet[] all = new SubSet[ALL];
		int count = 0;
		for (int i = 0; i < n && count < ALL; i++) {
			all[count++] = new SubSet(i, -1, -1, a[i]);
			for (int j = i + 1; j < n && count < ALL; j++) {
				all[count++] = new SubSet(i, j, -1, a[i] + a[j]);
				for (int k = j + 1; k < n && count < ALL; k++) {
					all[count++] = new SubSet(i, j, k, a[i] + a[j] + a[k]);
				}
			}
		}
		sort(all, 0, count, new Comparator<SubSet>() {
			@Override
			public int compare(SubSet o1, SubSet o2) {
				return Long.signum(o1.sum - o2.sum);
			}
		});
		SubSet.a = a;
		for (int i = 0; i < count;) {
			int j = i;
			while (j < count && all[i].sum == all[j].sum) {
				++j;
			}
			for (int k1 = i; k1 < j; k1++) {
				for (int k2 = k1 + 1; k2 < j; k2++) {
					SubSet s1 = all[k1];
					SubSet s2 = all[k2];
					if (!s1.intersect(s2)) {
						out.println(s1);
						out.println(s2);
						return;
					}
				}
			}
			i = j;
		}
		out.println("Impossible");
	}

	static class SubSet {
		static long[] a;
		int id1;
		int id2;
		int id3;
		long sum;

		public SubSet(int id1, int id2, int id3, long sum) {
			this.id1 = id1;
			this.id2 = id2;
			this.id3 = id3;
			this.sum = sum;
		}

		boolean intersect(SubSet s) {
			if (id1 >= 0) {
				if (id1 == s.id1 || id1 == s.id2 || id1 == s.id3) {
					return true;
				}
			}

			if (id2 >= 0) {
				if (id2 == s.id1 || id2 == s.id2 || id2 == s.id3) {
					return true;
				}
			}

			if (id3 >= 0) {
				if (id3 == s.id1 || id3 == s.id2 || id3 == s.id3) {
					return true;
				}
			}

			return false;
		}

		@Override
		public String toString() {
			if (id2 < 0) {
				return a[id1] + "";
			} else if (id3 < 0) {
				return a[id1] + " " + a[id2];
			} else {
				return a[id1] + " " + a[id2] + " " + a[id3];
			}
		}

	}

	static void printAnswer(long[] a, int mask1, int mask2, PrintWriter out) {
		List<Long> ans1 = getMask(a, mask1);
		List<Long> ans2 = getMask(a, mask2);
		printList(ans1, out);
		printList(ans2, out);
	}

	static List<Long> getMask(long[] a, int mask) {
		List<Long> ret = new ArrayList<Long>();
		for (int i = 0; i < a.length; i++) {
			if (((mask >> i) & 1) == 1) {
				ret.add(a[i]);
			}
		}
		Collections.sort(ret);
		return ret;
	}

	static void printList(List<Long> a, PrintWriter out) {
		for (int i = 0; i < a.size(); i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(a.get(i));
		}
		out.println();
	}

}
