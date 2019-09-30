import java.util.*;
import static java.lang.Math.*;
import java.io.*;

public class D {
	public static void p(Object... args) { System.out.println(Arrays.deepToString(args));}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int zz = 1; zz <= T; zz++) {
			String start = in.next();
			N = start.length();
			int st = 0;
			for (int i = 0; i < N; i++) {
				if (start.charAt(i) == 'X')
					st |= 1 << i;
			}
			DP = new double[1<<N];
			Arrays.fill(DP, -1);
			DP[(1<<N)-1] = 0;
			System.out.format("Case #%d: %.12f\n", zz, compute(st));
		}
	}
	static int N;
	static double[] DP;
	static double compute(int at) {
		if (DP[at] != -1)
			return DP[at];

		double ans = 0.0;

		for (int i = 0; i < N; i++) {
			int cost = N;
			int j = i;
			while(get(at, j)) {
				j++;
				cost--;
				if (j == N)
					j = 0;
			}
			ans += cost + compute(at | (1<<j));
		}
		ans /= N;
		DP[at] = ans;
		return ans;
	}

	static boolean get(int num, int bit) {
		return (num & (1<<bit)) != 0;
	}
}
