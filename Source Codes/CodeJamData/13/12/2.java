import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			long E = in.nextLong();
			long R = in.nextLong();
			int N = in.nextInt();
			long[] V = new long[N];
			Day[] D = new Day[N];
			for (int i = 0; i < N; i++) {
				V[i] = in.nextLong();
				D[i] = new Day(i, V[i]);
			}
			Arrays.sort(D);
			long[] max = new long[N];
			long[] min = new long[N];
			Arrays.fill(max, E);
			Arrays.fill(min, 0);
			
			long ans = 0;
			for (Day d:D) {
				
				int i = d.idx;
				ans += V[i]*(max[i]-min[i]);
				if (max[i] < min[i])
					throw new RuntimeException("foobar!");
//				System.out.println("\t"+d.value+" "+i+" "+max[i]+" "+min[i]+" "+ans);
				
				long total = 0;
				for (int j = i+1; j < N; j++) {
					total += R;
					max[j] = min(max[j], min[i]+total);
				}
				total = 0;
				for (int j = i-1; j >= 0; j--) {
					total += R;
					min[j] = max(min[j], max[i]-total);
				}
			}
			System.out.format("Case #%d: %d\n", t, ans);
		}
	}

	public static class Day implements Comparable<Day> {
		int idx;
		long value;
		public Day(int idx, long value) {
			this.idx = idx;
			this.value = value;
		}
		public int compareTo(Day d) {
			if (value < d.value)
				return 1;
			if (value > d.value)
				return -1;
			if (idx < d.idx)
				return -1;
			if (idx > d.idx)
				return 1;
			return 0;
		}
	}
}
