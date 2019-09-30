import java.util.*;
import static java.lang.Math.*;
import java.io.*;

public class A {
	public static void p(Object... args) { System.out.println(Arrays.deepToString(args));}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int zz = 1; zz <= T; zz++) {
			long B = in.nextLong();
			int N = in.nextInt();
			long[] V = new long[37];
			for (int i = 0; i < N; i++)
				V[i] = in.nextLong();
			Arrays.sort(V);
			//			p(V);
			double ans = 0.0;
			for (int use = 1; use < 37; use++) {
				ArrayList<MaxEntry> M = new ArrayList<MaxEntry>();
				for (int m = 1; m + use <= 37; m++) {
					long max = V[use + m - 1];
					long fixed = 0;
					for (int i = 0; i < m; i++) {
						fixed += max - V[i + use];
					}
					M.add(new MaxEntry(max, fixed, m));
				}
				long min = V[use - 1];
				long minspaces = 0;
				for (int i = 0; i < use; i++) {
					minspaces += min - V[i];
				}
				if (B < minspaces)
					continue;

				for (int i = 0; i < M.size(); i++) {
					MaxEntry e = M.get(i);
					long maxcando = i + 1 < M.size() ? M.get(i + 1).max : Long.MAX_VALUE;
					if (e.max == maxcando)
						continue;

					long budget = B;
					budget -= minspaces + e.fix;
					if (e.max == min) {
						budget -= e.variable;
					}
					long placenormal = max(0, min(budget / use, e.max - min - 1));
					budget -= use * placenormal;
					if (budget < 0)
						continue;
					long extratimes = min(maxcando - e.max - 1, budget / (use + e.variable));
					budget -= extratimes * (use + e.variable);
					long totalcanwin = minspaces + (placenormal + extratimes) * use;

					double ev = totalcanwin * ((1.0/use) * 36) - (B - budget);
					//					if (ev > ans) {
					//						p(min, e.max, maxcando);
					//						p(ev, use, maxcando, min, totalcanwin, (B-budget), extratimes, e.variable);
					//					}
					ans = max(ans, ev);
				}
			}
			System.out.format("Case #%d: %.09f\n", zz, ans);
		}
	}
	static class MaxEntry {
		long max, fix, variable;
		public MaxEntry(long max, long fix, long variable) {
			this.max = max;
			this.fix = fix;
			this.variable = variable;
		}
	}
}
