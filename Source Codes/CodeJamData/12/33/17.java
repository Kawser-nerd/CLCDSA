import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

@SuppressWarnings("unused")
public class C {
	static long[][] memo;

	public static void main(String[] args) throws Exception {
		// Scanner in = new Scanner(System.in);
		// PrintStream out = System.out;
		// Scanner in = new Scanner(new File("C-small.in"));
		// PrintStream out = new PrintStream("C-small.out");
		Scanner in = new Scanner(new File("C-large.in"));
		PrintStream out = new PrintStream("C-large.out");
		int T = in.nextInt();
		for (int kase = 1; kase <= T; kase++) {
			memo = new long[1000][1000];
			for (int i = 0; i < 1000; i++)
				Arrays.fill(memo[i], -1);
			int N = in.nextInt();
			int M = in.nextInt();
			ArrayList<Long> a = new ArrayList<Long>();
			ArrayList<Integer> A = new ArrayList<Integer>();
			ArrayList<Long> b = new ArrayList<Long>();
			ArrayList<Integer> B = new ArrayList<Integer>();
			for (int i = 0; i < N; i++) {
				a.add(in.nextLong());
				A.add(in.nextInt());
			}
			for (int i = 0; i < M; i++) {
				b.add(in.nextLong());
				B.add(in.nextInt());
			}
			for (int i = 1; i < A.size(); i++) {
				if (A.get(i - 1) == A.get(i)) {
					a.set(i - 1, a.get(i - 1) + a.get(i));
					a.remove(i);
					A.remove(i);
				}
			}
			for (int i = 1; i < B.size(); i++) {
				if (B.get(i - 1) == B.get(i)) {
					b.set(i - 1, b.get(i - 1) + b.get(i));
					b.remove(i);
					B.remove(i);
				}
			}
			out.println("Case #" + kase + ": " + go(0, 0, a, A, b, B));
		}
	}

	private static long go(int i, int j, ArrayList<Long> a, ArrayList<Integer> A, ArrayList<Long> b, ArrayList<Integer> B) {
		int xx = i;
		int yy = j;
		if (i == a.size() || j == b.size())
			return 0;
		if (memo[xx][yy] != -1)
			return memo[xx][yy];
		if (A.get(i) != B.get(j)) {
			return memo[xx][yy] = Math.max(go(i + 1, j, a, A, b, B), go(i, j + 1, a, A, b, B));
		}
		long x = a.get(i);
		long y = b.get(j);
		long ans = Math.min(x, y) + go(i + 1, j + 1, a, A, b, B);
		while (x != y) {
			if (x > y) {
				if (j < B.size() - 1) {
					j++;
					if (A.get(i) == B.get(j)) {
						y += b.get(j);
					}
				} else {
					break;
				}
			} else {
				if (i < a.size() - 1) {
					i++;
					if (A.get(i) == B.get(j)) {
						x += a.get(i);
					}
				} else {
					break;
				}
			}
			ans = Math.max(ans, Math.min(x, y) + go(i + 1, j + 1, a, A, b, B));
		}
		return memo[xx][yy] = ans;
	}
}